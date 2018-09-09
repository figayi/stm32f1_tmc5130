#include "IOMap.h"
#include "HAL.h"
#include "stm32f10x.h"

static void init(void);

IOPinMapTypeDef IOMap =
{

	.init   = init,
		#if 0
	.ID_CLK =  // IOPinTypeDef ID_CLK
	{
		.setBitRegister      = &(GPIOC->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOC->BRR) ,  // __IO uint16 *resetBitRegister
		.port                = GPIOC,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_9,       // uint32 pinBitWeight
		.bit                 = 9,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_Out_OD,        // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.ID_CH0 =  // IOPinTypeDef ID_CH0
	{
		.setBitRegister      = &(GPIOC->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOC->BRR) ,  // __IO uint16 *resetBitRegister
		.port                = GPIOC,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_0,       // uint32 pinBitWeight
		.bit                 = 0,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.ID_CH1 =  // IOPinTypeDef ID_CH1
	{
		.setBitRegister      = &(GPIOC->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOC->BRR) ,  // __IO uint16 *resetBitRegister
		.port                = GPIOC,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_1,       // uint32 pinBitWeight
		.bit                 = 1,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.DIO0 =  // IOPinTypeDef DIO0
	{
		.setBitRegister      = &(GPIOA->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOA->BRR) ,  // __IO uint16 *resetBitRegister
		.port                = GPIOA,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_0,       // uint32 pinBitWeight
		.bit                 = 0,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.DIO1 =  // IOPinTypeDef DIO1
	{
		.setBitRegister      = &(GPIOA->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOA->BRR) ,  // __IO uint16 *resetBitRegister
		.port                = GPIOA,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_1,       // uint32 pinBitWeight
		.bit                 = 1,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.DIO2 =  // IOPinTypeDef
	{
		.setBitRegister      = &(GPIOA->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOA->BRR) ,  // __IO uint16 *resetBitRegister
		.port                = GPIOA,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_2,       // uint32 pinBitWeight
		.bit                 = 2,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.DIO3 =  // IOPinTypeDef DIO3
	{
		.setBitRegister      = &(GPIOA->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOA->BRR) ,  // __IO uint16 *resetBitRegister
		.port                = GPIOA,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_3,       // uint32 pinBitWeight
		.bit                 = 3,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.DIO4 =  // IOPinTypeDef DIO4
	{
		.setBitRegister      = &(GPIOA->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOA->BRR) ,  // __IO uint16 *resetBitRegister
		.port                = GPIOA,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_4,       // uint32 pinBitWeight
		.bit                 = 4,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.DIO5 =  // IOPinTypeDef DIO5
	{
		.setBitRegister      = &(GPIOA->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOA->BRR) ,  // __IO uint16 *resetBitRegister
		.port                = GPIOA,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_5,       // uint32 pinBitWeight
		.bit                 = 5,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.AIN0 =  // IOPinTypeDef AIN0
	{
		.setBitRegister      = &(GPIOA->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOA->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOA,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_7,       // uint32 pinBitWeight
		.bit                 = 7,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_AIN,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.AIN1 =  // IOPinTypeDef AIN1
	{
		.setBitRegister      = &(GPIOB->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOB->BRR),   // __IO uint16 *resetBitRegister
		.port                = GPIOB,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_0,       // uint32 pinBitWeight
		.bit                 = 0,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_AIN,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.AIN2 =  // IOPinTypeDef AIN2
	{
		.setBitRegister      = &(GPIOB->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOB->BRR),   // __IO uint16 *resetBitRegister
		.port                = GPIOB,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_1,       // uint32 pinBitWeight
		.bit                 = 1,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_AIN,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.DIO6 =  // IOPinTypeDef DIO6
	{
		.setBitRegister      = &(GPIOE->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOE->BRR),   // __IO uint16 *resetBitRegister
		.port                = GPIOE,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_8,       // uint32 pinBitWeight
		.bit                 = 8,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.DIO7 =  // IOPinTypeDef DIO7
	{
		.setBitRegister      = &(GPIOE->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOE->BRR),   // __IO uint16 *resetBitRegister
		.port                = GPIOE,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_9,       // uint32 pinBitWeight
		.bit                 = 9,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.DIO8 =  // IOPinTypeDef DIO8
	{
		.setBitRegister      = &(GPIOE->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOE->BRR),   // __IO uint16 *resetBitRegister
		.port                = GPIOE,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_10,      // uint32 pinBitWeight
		.bit                 = 10,               // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.DIO9 =  // IOPinTypeDef DIO9
	{
		.setBitRegister      = &(GPIOE->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOE->BRR),   // __IO uint16 *resetBitRegister
		.port                = GPIOE,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_11,      // uint32 pinBitWeight
		.bit                 = 11,               // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.DIO10 =  // IOPinTypeDef DIO10
	{
		.setBitRegister      = &(GPIOE->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOE->BRR),   // __IO uint16 *resetBitRegister
		.port                = GPIOE,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_12,      // uint32 pinBitWeight
		.bit                 = 12,               // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.DIO11 =  // IOPinTypeDef DIO11
	{
		.setBitRegister      = &(GPIOE->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOE->BRR),   // __IO uint16 *resetBitRegister
		.port                = GPIOE,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_13,      // uint32 pinBitWeight
		.bit                 = 13,               // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.CLK16 =  // IOPinTypeDef CLK16
	{
		.setBitRegister      = &(GPIOE->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOE->BRR),   // __IO uint16 *resetBitRegister
		.port                = GPIOA,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_8,       // uint32 pinBitWeight
		.bit                 = 8,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_AF_PP,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.SPI2_CSN0 =  // IOPinTypeDef SPI2_CSN0
	{
		.setBitRegister      = &(GPIOE->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOE->BRR),   // __IO uint16 *resetBitRegister
		.port                = GPIOE,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_15,      // uint32 pinBitWeight
		.bit                 = 15,               // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_Out_PP,        // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.SPI2_CSN1 =  // IOPinTypeDef SPI2_CSN1
	{
		.setBitRegister      = &(GPIOB->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOB->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOB,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_11,      // uint32 pinBitWeight
		.bit                 = 11,               // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_Out_PP,        // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.SPI2_CSN2 =  // IOPinTypeDef SPI2_CSN2
	{
		.setBitRegister      = &(GPIOB->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOB->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOB,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_12,      // uint32 pinBitWeight
		.bit                 = 12,               // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_Out_PP,        // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.SPI2_SCK =  // IOPinTypeDef SPI2_SCK
	{
		.setBitRegister      = &(GPIOB->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOB->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOB,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_13,      // uint32 pinBitWeight
		.bit                 = 13,               // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_AF_PP,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.SPI2_SDO =  // IOPinTypeDef SPI2_SDO
	{
		.setBitRegister      = &(GPIOB->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOB->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOB,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_14,      // uint32 pinBitWeight
		.bit                 = 14,               // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_AF_PP,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.SPI2_SDI =  // IOPinTypeDef SPI2_SDI
	{
		.setBitRegister      = &(GPIOB->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOB->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOB,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_15,      // uint32 pinBitWeight
		.bit                 = 15,               // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_AF_PP,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.SPI1_CSN =  // IOPinTypeDef SPI1_CSN
	{
		.setBitRegister      = &(GPIOA->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOA->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOA,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_15,      // uint32 pinBitWeight
		.bit                 = 15,               // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_Out_PP,        // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.SPI1_SCK =  // IOPinTypeDef SPI1_SCK
	{
		.setBitRegister      = &(GPIOC->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOC->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOC,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_10,      // uint32 pinBitWeight
		.bit                 = 10,               // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_AF_PP,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.SPI1_SDI =  // IOPinTypeDef SPI1_SDI
	{
		.setBitRegister      = &(GPIOC->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOC->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOC,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_12,      // uint32 pinBitWeight
		.bit                 = 12,               // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_AF_PP,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.SPI1_SDO =  // IOPinTypeDef SPI1_SDO
	{
		.setBitRegister      = &(GPIOC->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOC->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOC,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_11,      // uint32 pinBitWeight
		.bit                 = 11,               // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_AF_PP,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.DIO12 =  // IOPinTypeDef DIO12
	{
		.setBitRegister      = &(GPIOD->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOD->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOD,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_0,       // uint32 pinBitWeight
		.bit                 = 0,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.DIO13 =  // IOPinTypeDef DIO13
	{
		.setBitRegister      = &(GPIOD->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOD->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOD,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_1,       // uint32 pinBitWeight
		.bit                 = 1,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.DIO14 =  // IOPinTypeDef DIO14
	{
		.setBitRegister      = &(GPIOD->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOD->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOD,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_2,       // uint32 pinBitWeight
		.bit                 = 2,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.DIO15 =  // IOPinTypeDef DIO15
	{
		.setBitRegister      = &(GPIOD->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOD->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOD,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_3,       // uint32 pinBitWeight
		.bit                 = 3,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.DIO16 =  // IOPinTypeDef DIO016
	{
		.setBitRegister      = &(GPIOD->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOD->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOD,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_4,       // uint32 pinBitWeight
		.bit                 = 4,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.DIO17 =  // IOPinTypeDef DIO017
	{
		.setBitRegister      = &(GPIOD->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOD->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOD,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_5,       // uint32 pinBitWeight
		.bit                 = 5,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.DIO18 =  // IOPinTypeDef DIO18
	{
		.setBitRegister      = &(GPIOD->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOD->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOD,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_6,       // uint32 pinBitWeight
		.bit                 = 6,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.DIO19 =  // IOPinTypeDef DIO19
	{
		.setBitRegister      = &(GPIOD->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOD->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOD,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_7,       // uint32 pinBitWeight
		.bit                 = 7,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.WIRELESS_TX =  // IOPinTypeDef WIRELESS_TX
	{
		.setBitRegister      = &(GPIOD->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOD->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOD,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_8,       // uint32 pinBitWeight
		.bit                 = 8,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_AF_PP,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.WIRELESS_RX =  // IOPinTypeDef WIRELESS_RX
	{
		.setBitRegister      = &(GPIOD->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOD->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOD,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_9,       // uint32 pinBitWeight
		.bit                 = 9,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_AF_PP,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.WIRELESS_NRST =  // IOPinTypeDef WIRELESS_NRST
	{
		.setBitRegister      = &(GPIOD->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOD->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOD,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_10,      // uint32 pinBitWeight
		.bit                 = 10,               // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_Out_PP,        // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.RS232_TX =  // IOPinTypeDef RS232_TX
	{
		.setBitRegister      = &(GPIOC->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOC->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOC,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_6,       // uint32 pinBitWeight
		.bit                 = 6,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_AF_PP,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.RS232_RX =  // IOPinTypeDef RS232_RX
	{
		.setBitRegister      = &(GPIOC->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOC->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOC,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_7,       // uint32 pinBitWeight
		.bit                 = 7,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_AF_PP,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.USB_V_BUS =  // IOPinTypeDef USB_V_BUS
	{
		.setBitRegister      = &(GPIOA->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOA->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOA,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_9,       // uint32 pinBitWeight
		.bit                 = 9,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,    // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.USB_V_DM =  // IOPinTypeDef USB_V_DM
	{
		.setBitRegister      = &(GPIOA->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOA->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOA,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_11,      // uint32 pinBitWeight
		.bit                 = 11,               // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_AF_PP,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,    // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.USB_V_DP =  // IOPinTypeDef USB_V_DP
	{
		.setBitRegister      = &(GPIOA->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOA->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOA,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_12,      // uint32 pinBitWeight
		.bit                 = 12,               // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_AF_PP,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,    // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.VM_MEAS =  // IOPinTypeDef VM_MEAS
	{
		.setBitRegister      = &(GPIOC->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOC->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOC,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_2,       // uint32 pinBitWeight
		.bit                 = 2,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_AIN,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},
#endif

        .LED_STAT =  // IOPinTypeDef LED_STAT
        {
            .setBitRegister      = &(GPIOC->BSRR),  // __IO uint16 *setBitRegister
            .resetBitRegister    = &(GPIOC->BRR),  // __IO uint16 *resetBitRegister
            .port                = GPIOC,            // GPIO_TypeDef *port
            .bitWeight           = GPIO_Pin_4,       // uint32 pinBitWeight
            .bit                 = 0,                // unsigned char bit
            .resetConfiguration  =
            {
                .GPIO_Mode   = GPIO_Mode_Out_PP,        // GPIOMode_TypeDef GPIO_Mode
    //          .GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
                .GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
    //          .GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
            }
        },	
				
        .KEY_STAT =  // IOPinTypeDef LED_STAT
        {
            .setBitRegister      = &(GPIOC->BSRR),  // __IO uint16 *setBitRegister
            .resetBitRegister    = &(GPIOC->BRR),  // __IO uint16 *resetBitRegister
            .port                = GPIOC,            // GPIO_TypeDef *port
            .bitWeight           = GPIO_Pin_13,       // uint32 pinBitWeight
            .bit                 = 0,                // unsigned char bit
            .resetConfiguration  =
            {
            	.GPIO_Mode   = GPIO_Mode_IPU,        // GPIOMode_TypeDef GPIO_Mode
            //			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
            	.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
            //			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
            }
        },

#if 0

	.LED_ERROR =  // IOPinTypeDef LED_ERROR
	{
		.setBitRegister      = (__IO uint16*)&(GPIOE->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = (__IO uint16*)&(GPIOE->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOE,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_1,       // uint32 pinBitWeight
		.bit                 = 1,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_Out_PP,        // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.EXTIO_2 =  // IOPinTypeDef EXTIO_2
	{
		.setBitRegister      = &(GPIOE->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOE->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOE,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_3,       // uint32 pinBitWeight
		.bit                 = 3,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.EXTIO_3 =  // IOPinTypeDef EXTIO_3
	{
		.setBitRegister      = &(GPIOE->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOE->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOE,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_4,       // uint32 pinBitWeight
		.bit                 = 4,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.EXTIO_4 =  // IOPinTypeDef EXTIO_4
	{
		.setBitRegister      = &(GPIOE->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOE->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOE,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_5,       // uint32 pinBitWeight
		.bit                 = 5,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.EXTIO_5 =  // IOPinTypeDef EXTIO_5
	{
		.setBitRegister      = &(GPIOC->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOC->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOC,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_4,       // uint32 pinBitWeight
		.bit                 = 4,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.EXTIO_6 =  // IOPinTypeDef EXTIO_6
	{
		.setBitRegister      = &(GPIOC->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOC->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOC,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_5,       // uint32 pinBitWeight
		.bit                 = 5,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.EXTIO_7 =  // IOPinTypeDef EXTIO_7
	{
		.setBitRegister      = &(GPIOC->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOC->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOC,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_5,       // uint32 pinBitWeight
		.bit                 = 5,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.EEPROM_SCK =  // IOPinTypeDef EEPROM_SCK
	{
		.setBitRegister      = &(GPIOB->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOB->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOB,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_3,       // uint32 pinBitWeight
		.bit                 = 3,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_AF_PP,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.EEPROM_SI =  // IOPinTypeDef EEPROM_SI
	{
		.setBitRegister      = &(GPIOB->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOB->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOB,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_4,       // uint32 pinBitWeight
		.bit                 = 4,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_AF_PP,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.EEPROM_SO =  // IOPinTypeDef EEPROM_SO
	{
		.setBitRegister      = &(GPIOB->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOB->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOB,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_5,       // uint32 pinBitWeight
		.bit                 = 5,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_AF_PP,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.EEPROM_NCS =  // IOPinTypeDef
	{
		.setBitRegister      = &(GPIOB->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOB->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOB,            // GPIO_TypeDef *port
		.bitWeight           = GPIO_Pin_6,       // uint32 pinBitWeight
		.bit                 = 6,                // unsigned char bit
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_Out_PP,        // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.MIXED0 =  // !!! DUMMY -> NOT IN HADWARE !!!
	{
		.setBitRegister      = &(GPIOA->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOA->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOB,            // GPIO_TypeDef *port
		.bitWeight           = DUMMY_BITWEIGHT,  // invalid
		.bit                 = -1,               // invalid
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.MIXED1 =  // !!! DUMMY -> NOT IN HADWARE !!!
	{
		.setBitRegister      = &(GPIOA->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOA->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOB,            // GPIO_TypeDef *port
		.bitWeight           = DUMMY_BITWEIGHT,  // invalid
		.bit                 = -1,               // invalid
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.MIXED2 =  // !!! DUMMY -> NOT IN HADWARE !!!
	{
		.setBitRegister      = &(GPIOA->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOA->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOB,            // GPIO_TypeDef *port
		.bitWeight           = DUMMY_BITWEIGHT,  // invalid
		.bit                 = -1,               // invalid
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.MIXED3 =  // !!! DUMMY -> NOT IN HADWARE !!!
	{
		.setBitRegister      = &(GPIOA->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOA->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOB,            // GPIO_TypeDef *port
		.bitWeight           = DUMMY_BITWEIGHT,  // invalid
		.bit                 = -1,               // invalid
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.MIXED4 =  // !!! DUMMY -> NOT IN HADWARE !!!
	{
		.setBitRegister      = &(GPIOA->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOA->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOB,            // GPIO_TypeDef *port
		.bitWeight           = DUMMY_BITWEIGHT,  // invalid
		.bit                 = -1,               // invalid
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.MIXED5 =  // !!! DUMMY -> NOT IN HADWARE !!!
	{
		.setBitRegister      = &(GPIOA->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOA->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOB,            // GPIO_TypeDef *port
		.bitWeight           = DUMMY_BITWEIGHT,  // invalid
		.bit                 = -1,               // invalid
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.MIXED6 =  // !!! DUMMY -> NOT IN HADWARE !!!
	{
		.setBitRegister      = &(GPIOA->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOA->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOB,            // GPIO_TypeDef *port
		.bitWeight           = DUMMY_BITWEIGHT,  // invalid
		.bit                 = -1,               // invalid
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	},

	.DUMMY =  // IOPinTypeDef
	{
		.setBitRegister      = &(GPIOA->BSRR),  // __IO uint16 *setBitRegister
		.resetBitRegister    = &(GPIOA->BRR),  // __IO uint16 *resetBitRegister
		.port                = GPIOB,            // GPIO_TypeDef *port
		.bitWeight           = DUMMY_BITWEIGHT,  // invalid
		.bit                 = -1,               // invalid
		.resetConfiguration  =
		{
			.GPIO_Mode   = GPIO_Mode_IPU,         // GPIOMode_TypeDef GPIO_Mode
//			.GPIO_OType  = GPIO_OType_PP,        // GPIOSpeed_TypeDef GPIO_Speed
			.GPIO_Speed  = GPIO_Speed_50MHz,     // GPIOOType_TypeDef GPIO_OType
//			.GPIO_PuPd   = GPIO_PuPd_NOPULL      // GPIOPuPd_TypeDef GPIO_PuPd
		}
	}
	#endif
};

static void init()
{
    //Ĭ������Ϊ�ߵ�ƽ
//	HAL.IOs->config->reset(&HAL.IOs->pins->ID_CLK);
//	HAL.IOs->config->reset(&HAL.IOs->pins->ID_CH0);
//	HAL.IOs->config->reset(&HAL.IOs->pins->ID_CH1);
//	HAL.IOs->config->reset(&HAL.IOs->pins->DIO0);
//	HAL.IOs->config->reset(&HAL.IOs->pins->DIO1);
//	HAL.IOs->config->reset(&HAL.IOs->pins->DIO2);
//	HAL.IOs->config->reset(&HAL.IOs->pins->DIO3);
//	HAL.IOs->config->reset(&HAL.IOs->pins->DIO4);
//	HAL.IOs->config->reset(&HAL.IOs->pins->DIO5);
//	HAL.IOs->config->reset(&HAL.IOs->pins->AIN0);
//	HAL.IOs->config->reset(&HAL.IOs->pins->AIN1);
//	HAL.IOs->config->reset(&HAL.IOs->pins->AIN2);
//	HAL.IOs->config->reset(&HAL.IOs->pins->DIO6);
//	HAL.IOs->config->reset(&HAL.IOs->pins->DIO7);
//	HAL.IOs->config->reset(&HAL.IOs->pins->DIO8);
//	HAL.IOs->config->reset(&HAL.IOs->pins->DIO9);
//	HAL.IOs->config->reset(&HAL.IOs->pins->DIO10);
//	HAL.IOs->config->reset(&HAL.IOs->pins->DIO11);
//	HAL.IOs->config->reset(&HAL.IOs->pins->SPI2_CSN0);
//	HAL.IOs->config->reset(&HAL.IOs->pins->SPI2_CSN1);
//	HAL.IOs->config->reset(&HAL.IOs->pins->SPI2_CSN2);
//	HAL.IOs->config->reset(&HAL.IOs->pins->SPI2_SCK);
//	HAL.IOs->config->reset(&HAL.IOs->pins->SPI2_SDO);
//	HAL.IOs->config->reset(&HAL.IOs->pins->SPI2_SDI);
//	HAL.IOs->config->reset(&HAL.IOs->pins->SPI1_CSN);
//	HAL.IOs->config->reset(&HAL.IOs->pins->SPI1_SCK);
//	HAL.IOs->config->reset(&HAL.IOs->pins->SPI1_SDI);
//	HAL.IOs->config->reset(&HAL.IOs->pins->SPI1_SDO);
//	HAL.IOs->config->reset(&HAL.IOs->pins->DIO12);
//	HAL.IOs->config->reset(&HAL.IOs->pins->DIO13);
//	HAL.IOs->config->reset(&HAL.IOs->pins->DIO14);
//	HAL.IOs->config->reset(&HAL.IOs->pins->DIO15);
//	HAL.IOs->config->reset(&HAL.IOs->pins->DIO16);
//	HAL.IOs->config->reset(&HAL.IOs->pins->DIO17);
//	HAL.IOs->config->reset(&HAL.IOs->pins->DIO18);
//	HAL.IOs->config->reset(&HAL.IOs->pins->DIO19);
//	HAL.IOs->config->reset(&HAL.IOs->pins->WIRELESS_TX);
//	HAL.IOs->config->reset(&HAL.IOs->pins->WIRELESS_RX);
//	HAL.IOs->config->reset(&HAL.IOs->pins->WIRELESS_NRST);
//	HAL.IOs->config->reset(&HAL.IOs->pins->RS232_TX);
//	HAL.IOs->config->reset(&HAL.IOs->pins->RS232_RX);
//	HAL.IOs->config->reset(&HAL.IOs->pins->USB_V_BUS);
//	HAL.IOs->config->reset(&HAL.IOs->pins->USB_V_DM);
//	HAL.IOs->config->reset(&HAL.IOs->pins->USB_V_DP);
//	HAL.IOs->config->reset(&HAL.IOs->pins->VM_MEAS);
		HAL.IOs->config->reset(&HAL.IOs->pins->LED_STAT);
    HAL.IOs->config->reset(&HAL.IOs->pins->KEY_STAT);
//	HAL.IOs->config->reset(&HAL.IOs->pins->LED_ERROR);
//	HAL.IOs->config->reset(&HAL.IOs->pins->EXTIO_2);
//	HAL.IOs->config->reset(&HAL.IOs->pins->EXTIO_3);
//	HAL.IOs->config->reset(&HAL.IOs->pins->EXTIO_4);
//	HAL.IOs->config->reset(&HAL.IOs->pins->EXTIO_5);
//	HAL.IOs->config->reset(&HAL.IOs->pins->EXTIO_6);
//	HAL.IOs->config->reset(&HAL.IOs->pins->EXTIO_7);
//	HAL.IOs->config->reset(&HAL.IOs->pins->EEPROM_SCK);
//	HAL.IOs->config->reset(&HAL.IOs->pins->EEPROM_SI);
//	HAL.IOs->config->reset(&HAL.IOs->pins->EEPROM_SO);
//	HAL.IOs->config->reset(&HAL.IOs->pins->EEPROM_NCS);
//	HAL.IOs->config->reset(&HAL.IOs->pins->CLK16);
}
