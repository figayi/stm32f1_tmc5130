
#include "VitalSignsMonitor.h"

#include "derivative.h"
#include "Board.h"
#include "HAL.h"
#include "makefor.h"

	#define VM_MIN_INTERFACE_BOARD  70   // minimum motor supply voltage for system in [100mV]
	#define VM_MAX_INTERFACE_BOARD  700  // maximum motor supply voltage for system in [100mV]
	#define VM_FACTOR               713  // ADC reaches limit at VM = 71.3V => VM Factor (in 100mV) = 713

	// error bits
	#define VSM_CHX                     (1<<0)   // any errors on the evalboards
	#define VSM_CH1                     (1<<1)   // any errors on motion controller board
	#define VSM_CH2                     (1<<2)   // any errors on driver board

	#define VSM_ERRORS_VM               (1<<0)   // something's wrong with the motor supply VM for any board
	#define VSM_ERRORS_CH1              (1<<1)   // something's wrong with the motor supply VM for motion controller board
	#define VSM_ERRORS_CH2              (1<<2)   // something's wrong with the motor supply VM for driver board
	#define VSM_BUSY                    (1<<3)   // any board is busy
	#define VSM_BUSY_CH1                (1<<4)   // motion controller board is busy
	#define VSM_BUSY_CH2                (1<<5)   // driver board is busy
	#define VSM_ERRORS_BROWNOUT         (1<<6)   // motor supply VM is to low for any board
	#define VSM_ERRORS_BROWNOUT_CH1     (1<<7)   // motor supply VM is to low for motion controller board
	#define VSM_ERRORS_BROWNOUT_CH2     (1<<8)   // motor supply VM is to low for driver board
	#define VSM_ERRORS_OVERVOLTAGE      (1<<9)   // motor supply VM is to high for any board
	#define VSM_ERRORS_OVERVOLTAGE_CH1  (1<<10)  // motor supply VM is to high for motion controller board
	#define VSM_ERRORS_OVERVOLTAGE_CH2  (1<<11)  // motor supply VM is to high for driver board

	// Status LED frequencies
	// Values are time in ms between LED toggles
	#define VSM_HEARTRATE_NORMAL  500  // Normal:   1 Hz
	#define VSM_HEARTRATE_FAST    50   // Busy:    10 Hz

	#define VSM_BROWNOUT_DELAY 50 // Delay (in 10ms) between voltage (re-)application and configuration restoration

VitalSignsMonitorTypeDef VitalSignsMonitor =
{
	.brownOut   = 0,                     // motor supply to low
	.VM         = 0,                     // actual measured motor supply VM
	.heartRate  = VSM_HEARTRATE_NORMAL,  // status LED blinking frequency
	.errorMask  = 0xFFFFFFFF,            // error mask, each bit stands for one error bit, 1 means error will be reported
	.busy       = 0,                     // if module is busy, status LED is blinking fast
	.debugMode  = 0,                     // debug mode e.g. releases error LED for debug purpose
	.errors     = 0                      // actual error bits
};

#define ADC_VM_RES 4095

// Make the status LED blink
// Frequency informs about normal operation or busy state
void heartBeat(uint32 tick)
{
	static uint32 lastTick = 0;

	if(VitalSignsMonitor.heartRate == 0)
		return;

	if((tick - lastTick) > VitalSignsMonitor.heartRate)
	{
		LED_TOGGLE();
		lastTick = tick;
	}
}

// Check for over/undervoltage of motor supply VM
void checkVM()
{
	uint32 VM;
	static uint8 stable = VSM_BROWNOUT_DELAY + 1; // delay value + 1 is the state during normal voltage levels - set here to prevent restore shortly after boot

	VM = *HAL.ADCs->VM;              // read ADC value for motor supply VM
	VM = (VM*VM_FACTOR)/ADC_VM_RES;  // calculate voltage from ADC value

	VitalSignsMonitor.VM           = VM;  // write to interface
	VitalSignsMonitor.overVoltage  = 0;   // reset overvoltage status
	VitalSignsMonitor.brownOut     = 0;   // reset undervoltage status

	// check for over/undervoltage and set according status if necessary
	if(VM > VM_MAX_INTERFACE_BOARD)  VitalSignsMonitor.overVoltage  |= VSM_CHX;
	if(VM >	Evalboards.ch1.VMMax)    VitalSignsMonitor.overVoltage  |= VSM_CHX | VSM_CH1;
	if(VM >	Evalboards.ch2.VMMax)    VitalSignsMonitor.overVoltage  |= VSM_CHX | VSM_CH2;

	// check for over/undervoltage and set according status if necessary
	if(VM <	VM_MIN_INTERFACE_BOARD)  VitalSignsMonitor.brownOut  |= VSM_CHX;
	if(VM <	Evalboards.ch1.VMMin)    VitalSignsMonitor.brownOut  |= VSM_CHX | VSM_CH1;
	if(VM <	Evalboards.ch2.VMMin)    VitalSignsMonitor.brownOut  |= VSM_CHX | VSM_CH2;

	// after brownout all settings are restored to the boards
	// this happens after supply was stable for a set delay (checkVM() is called every 10 ms/systicks)
	if(VitalSignsMonitor.brownOut)
	{
		stable = 0;
	}
	else
	{
		if(stable < VSM_BROWNOUT_DELAY)
		{
			stable++;
		}
		else if(stable == VSM_BROWNOUT_DELAY)
		{
			Evalboards.ch2.config->restore();
			Evalboards.ch1.config->restore();

			stable++;
		}
	}
}

/* Routine to frequently check system for errors */
void vitalsignsmonitor_checkVitalSigns()
{
	int errors = 0;
	static uint32 lastTick = 0;
	uint32 tick;

	tick = systick_getTick();

	// Check motor supply VM every 10ms
	if((tick - lastTick) >= 10)
	{
		checkVM();
		lastTick = tick;
	}

	// Check for board errors
	Evalboards.ch2.checkErrors(tick);
	Evalboards.ch1.checkErrors(tick);

	// Status LED
	heartBeat(tick);

	// reset all error bits but not the voltage errors
	errors = VitalSignsMonitor.errors & (VSM_ERRORS_OVERVOLTAGE | VSM_ERRORS_OVERVOLTAGE_CH1 | VSM_ERRORS_OVERVOLTAGE_CH2);

	// collect errors from board channels
	if(Evalboards.ch1.errors)  errors |= VSM_ERRORS_CH1;
	if(Evalboards.ch2.errors)  errors |= VSM_ERRORS_CH2;

	if(VitalSignsMonitor.busy)                        errors |= VSM_BUSY;
	if(Evalboards.ch1.config->state != CONFIG_READY)  errors |= VSM_BUSY | VSM_BUSY_CH1;
	if(Evalboards.ch2.config->state != CONFIG_READY)  errors |= VSM_BUSY | VSM_BUSY_CH2;

	if(VitalSignsMonitor.brownOut)                    errors |= VSM_ERRORS_VM | VSM_ERRORS_BROWNOUT;
	if(VitalSignsMonitor.brownOut & VSM_CH1	)         errors |= VSM_ERRORS_VM | VSM_ERRORS_BROWNOUT | VSM_ERRORS_BROWNOUT_CH1;
	if(VitalSignsMonitor.brownOut & VSM_CH2	)         errors |= VSM_ERRORS_VM | VSM_ERRORS_BROWNOUT | VSM_ERRORS_BROWNOUT_CH2;

	if(VitalSignsMonitor.overVoltage)                 errors |= VSM_ERRORS_VM | VSM_ERRORS_OVERVOLTAGE;
	if(VitalSignsMonitor.overVoltage & VSM_CH1)       errors |= VSM_ERRORS_VM | VSM_ERRORS_OVERVOLTAGE | VSM_ERRORS_OVERVOLTAGE_CH1;
	if(VitalSignsMonitor.overVoltage & VSM_CH2)       errors |= VSM_ERRORS_VM | VSM_ERRORS_OVERVOLTAGE | VSM_ERRORS_OVERVOLTAGE_CH2;

	VitalSignsMonitor.errors = errors & VitalSignsMonitor.errorMask; // write collected errors to interface

	// disable drivers on overvoltage
	if(errors & (VSM_ERRORS_OVERVOLTAGE | VSM_ERRORS_OVERVOLTAGE_CH1 | VSM_ERRORS_OVERVOLTAGE_CH2))
	{
		Evalboards.driverEnable = DRIVER_DISABLE;     // set global driver enable to disabled
		Evalboards.ch1.enableDriver(DRIVER_DISABLE);  // disable driver for motion controller board
		Evalboards.ch2.enableDriver(DRIVER_DISABLE);  // disable driver for driver
	}

	// set debug LED if not in debug mode
	// set status LED if not in debug mode
	if(!VitalSignsMonitor.debugMode)
	{
		if(VitalSignsMonitor.errors & (~(VSM_BUSY | VSM_BUSY_CH1 | VSM_BUSY_CH2)))
			HAL.LEDs->error.on();
		else
			HAL.LEDs->error.off();

		if(VitalSignsMonitor.errors & (VSM_BUSY | VSM_BUSY_CH1 | VSM_BUSY_CH2))
			VitalSignsMonitor.heartRate = VSM_HEARTRATE_FAST;
		else
			VitalSignsMonitor.heartRate = VSM_HEARTRATE_NORMAL;
	}
}

void vitalsignsmonitor_clearOvervoltageErrors()
{
	VitalSignsMonitor.errors &= ~(VSM_ERRORS_OVERVOLTAGE | VSM_ERRORS_OVERVOLTAGE_CH1 | VSM_ERRORS_OVERVOLTAGE_CH2);
}
