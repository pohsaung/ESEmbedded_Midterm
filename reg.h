#ifndef REG_H
#define REG_H

//REG OPERATIONS

#define UINT32_1 ((uint32_t)1)

#define REG(addr) (*((volatile uint32_t *)(addr)))

#define CLEAR_MASK(highest_bit, lowest_bit) (((highest_bit) - (lowest_bit)) >= 31 ? (uint32_t)0xFFFFFFFF : ~(((UINT32_1 << ((highest_bit) - (lowest_bit) + 1)) - 1) << (lowest_bit)))

#define WRITE_BITS(addr, highest_bit, lowest_bit, data) (REG(addr) = (REG(addr) & CLEAR_MASK(highest_bit, lowest_bit)) | ((uint32_t)(data) << (lowest_bit)))

#define SET_BIT(addr, bit) (REG(addr) |= UINT32_1 << (bit))
#define CLEAR_BIT(addr, bit) (REG(addr) &= ~(UINT32_1 << (bit)))

#define READ_BIT(addr, bit) ((REG(addr) >>(bit))&UINT32_1)

//FLASH
#define FLASH_BASE 0x40023c00
 
#define FLASH_ACR_OFFSET 0x00//access control reg
#define PRFTEN_BIT 8 //prefetch enable
#define LATENCY_2_BIT 2
#define LATENCY_1_BIT 1
#define LATENCY_0_BIT 0
//the ratio of the c[u period to the flash access time

//RCC
#define RCC_BASE 0x40023800

#define RCC_CR_OFFSET 0x00 //clock control reg
#define PLLRDY_BIT 25 //PLL ready
#define PLLON_BIT 24  //PLL enable
#define HSERDY_BIT 17 //HSE ready
#define HSEON_BIT 16  //HSE enable

#define HSION_BIT 0 //HSI
#define HSIRDY_BIT 1

#define RCC_PLLCFGR_OFFSET 0x04 //PLL configeration reg 設定

#define PLLSRC_BIT 22 //PLL input source 0=HSI 1=HSE

//Fout=Fin*n/mp

#define PLLP_1_BIT 17
#define PLLP_0_BIT 16
/*
00=2
01=4
10=6
11=8
*/

#define PLLN_8_BIT 14
#define PLLN_0_BIT 6
/*
50<=N<=432
*/

#define PLLM_5_BIT 5
#define PLLM_0_BIT 0
/*
2<=M<=63
*/

#define RCC_CFGR_OFFSET 0x08 //clock configeration
#define MCO2_1_BIT 31
#define MCO2_0_BIT 30
//select MCO2 output sorce
//11=PLL
#define MCO2PRE_2_BIT 29
#define MCO2PRE_0_BIT 27
// MCO2 prescaler
#define SWS_1_BIT 3
#define SWS_0_BIT 2
/*
是否設定好了
10 for PLL
*/
#define SW_1_BIT 1
#define SW_0_BIT 0
/*
10=select PLL as system clock
*/

#define RCC_AHB1ENR_OFFSET 0x30
#define GPIO_EN_BIT(port) (port)

//GPIO
#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2
#define GPIO_PORTD 3

#define GPIO_BASE(port) (0x40020000 + 0x400 * (port))

#define GPIOx_MODER_OFFSET 0x00
#define MODERy_1_BIT(y) ((y)*2 + 1)
#define MODERy_0_BIT(y) ((y)*2)

#define GPIOx_OTYPER_OFFSET 0x04
#define OTy_BIT(y) (y)

#define GPIOx_OSPEEDR_OFFSET 0x08
#define OSPEEDRy_1_BIT(y) ((y)*2 + 1)
#define OSPEEDRy_0_BIT(y) ((y)*2)

#define GPIOx_PUPDR_OFFSET 0x0C
#define PUPDRy_1_BIT(y) ((y)*2 + 1)
#define PUPDRy_0_BIT(y) ((y)*2)

#define GPIOx_BSRR_OFFSET 0x18
#define BRy_BIT(y) ((y) + 16) //reset
#define BSy_BIT(y) (y) //set

#endif
