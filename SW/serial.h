#ifndef SERIAL_H
#define SERIAL_H

#include <inttypes.h>
#include "registers.h"

#define BIT(x) (1UL << (x))

static inline void uart_init(struct uart *uart, unsigned long baud) {
  
  // enable clock for UART
  if (uart == UART1) RCC->APB2ENR |= BIT(4);
  if (uart == UART2) RCC->APB1ENR |= BIT(17);
  if (uart == UART6) RCC->APB1ENR |= BIT(18);
  
  uart->CR1 = 0;  // Disable UART
  uart->BRR = 8000000 / baud;  // Set baud rate
  uart->CR1 = BIT(3) | BIT(2) | BIT(0);  // Enable UART, RX, TX
}




#endif
