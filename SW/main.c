

// Created: 2025-03-06 16:00:00
// Author: Michael Schneider
// -----------------------------------------------------
// Target Device: STM32F411RE
// -----------------------------------------------------
// Programming Language: C, bare metal
//
// This is a test program for the STM32F411RE to explore
// the capabilities of the STM32F411RE microcontroller.
// The program is intended to create 
//    - an accurate base tick (10ms) (SYSTICK IRQ)
//    - GPIO output
//    - SPI communication
//    - CAN communication
// -----------------------------------------------------

 
#include <inttypes.h>
#include <stdbool.h>
#include "registers.h"

#define BIT(x) (1UL << (x))

static volatile uint32_t pick = 0;

void SysTick_Handler(void) {
  //pick++;
  *GPIOA_ODR ^= (1 << 5);  // Toggle PA5
}

static inline void systick_init(uint32_t ticks) {
  if ((ticks - 1) > 0xffffff) return;    // Systick timer is 24 bit
  SYST->RVR = ticks - 1;
  SYST->CVR = 0;
  SYST->CSR = BIT(0) | BIT(1) | BIT(2);  // Enable systick
  RCC->APB2ENR |= BIT(14);               // Enable SYSCFG
}

static inline void PA5_out_init() {
  RCC->AHB1ENR |= 1 << 0;             // Enable GPIOA clock
  *GPIOA_MODER |= 1 << 10;            // Set PA5 to output mode
  *GPIOA_ODR |= (1 << 5);             // Set PA5
}


int main(void) {
  
  systick_init(8000000 / 1);  // 1s second (STM32F4 runs at 8MHz)
  PA5_out_init();  // Set blue LED to output mode
  while (1) {
  

      }
  return 0;
}

// Startup code
__attribute__((naked, noreturn)) void _reset(void) {
  // memset .bss to zero, and copy .data section to RAM region
  extern long _sbss, _ebss, _sdata, _edata, _sidata;
  for (long *dst = &_sbss; dst < &_ebss; dst++) *dst = 0;
  for (long *dst = &_sdata, *src = &_sidata; dst < &_edata;) *dst++ = *src++;

  main();             // Call main()
  for (;;) (void) 0;  // Infinite loop in the case if main() returns
}

extern void _estack(void);  // Defined in link.ld

// 16 standard and 91 STM32-specific handlers
__attribute__((section(".vectors"))) void (*const tab[16 + 91])(void) = {
  _estack, _reset, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, SysTick_Handler};

