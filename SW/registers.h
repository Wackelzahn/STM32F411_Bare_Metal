#ifndef REGISTERS_H
#define REGISTERS_H

#include <inttypes.h>



// register RCC (Reset and Clock Control)
struct rcc {
    volatile uint32_t CR, PLLCFGR, CFGR, CIR, AHB1RSTR, AHB2RSTR, AHB3RSTR,
        RESERVED0, APB1RSTR, APB2RSTR, RESERVED1[2], AHB1ENR, AHB2ENR, AHB3ENR,
        RESERVED2, APB1ENR, APB2ENR, RESERVED3[2], AHB1LPENR, AHB2LPENR,
        AHB3LPENR, RESERVED4, APB1LPENR, APB2LPENR, RESERVED5[2], BDCR, CSR,
        RESERVED6[2], SSCGR, PLLI2SCFGR;
  };
  #define RCC ((struct rcc *) 0x40023800)


// register SYSTICK
  struct systick {
    volatile uint32_t CSR, RVR, CVR, CALIB;
  };
  #define SYST ((struct systick *) 0xe000e010)  // 2.2.2


// UART1 register
  struct uart {
    volatile uint32_t SR, DR, BRR, CR1, CR2, CR3, GTPR;
  };
  #define UART1 ((struct uart *) 0x40011000)
  #define UART2 ((struct uart *) 0x40004400)
  #define UART6 ((struct uart *) 0x40011400)


// GPIOA register
  volatile uint32_t *GPIOA_MODER = (volatile uint32_t*)0x40020000U;
  volatile uint32_t *GPIOA_ODR = (volatile uint32_t*)0x40020014U;
  volatile uint32_t *GPIOA_BSRR = (volatile uint32_t*)0x40020018U;
  volatile uint32_t *GPIOA_OTYPER = (volatile uint32_t*)0x40020004U;
  volatile uint32_t *GPIOA_OSPEEDR = (volatile uint32_t*)0x40020008U;
  
// GPIOB register
  volatile uint32_t *GPIOB_MODER = (volatile uint32_t*)0x40020400U;
  volatile uint32_t *GPIOB_ODR = (volatile uint32_t*)0x40020414U;
  volatile uint32_t *GPIOB_BSRR = (volatile uint32_t*)0x40020418U;
  volatile uint32_t *GPIOB_OTYPER = (volatile uint32_t*)0x40020404U;
  volatile uint32_t *GPIOB_OSPEEDR = (volatile uint32_t*)0x40020408U;


#endif