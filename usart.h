#ifndef USART_H
#define USART_H

#include "integer.h"

typedef struct {
  volatile uint8 RXDATAL;
  volatile uint8 RXDATAH;
  volatile uint8 TXDATAL;
  volatile uint8 TXDATAH;
  volatile uint8 STATUS;
  volatile uint8 CTRLA;
  volatile uint8 CTRLB;
  volatile uint8 CTRLC;
  volatile uint8 BAUDL;
  volatile uint8 BAUDH;
  volatile uint8 RESERVED_A;
  volatile uint8 DBGCTRL;
  volatile uint8 EVCTRL;
  volatile uint8 TXPLCTRL;
  volatile uint8 RXPLCTRL;
  volatile uint8 RESERVED_B;
} USART;

constexpr uint16 USART0_ADDRESS = 0x0800;

static_assert(sizeof(USART) == 0x10, "");

void usartInit(USART &u, uint16 baud);
void usartPutChar(USART &u, uint8 ch);
void usartPutString(USART &u, const char *text);
uint8 usartGetChar(USART &u);

#endif // USART_H
