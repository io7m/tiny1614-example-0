#include "usart.h"

static constexpr uint8 READY_RECEIVE = 0b10000000;
static constexpr uint8 READY_TRANSMIT = 0b00100000;

void usartInit(USART &u, uint16 baud) {
  u.BAUDH = baud >> 8;
  u.BAUDL = baud & 0xff;

  /*
   * Enable the sender and receiver.
   */

  u.CTRLB = 0b11000000;

  /*
   * Set 8-bit character size.
   */

  u.CTRLC = 0b00000011;
}

void usartPutChar(USART &u, uint8 ch) {
  for (;;) {
    if ((u.STATUS & READY_TRANSMIT) == READY_TRANSMIT) {
      break;
    }
  }
  u.TXDATAL = ch;
}

uint8 usartGetChar(USART &u) {
  for (;;) {
    if ((u.STATUS & READY_RECEIVE) == READY_RECEIVE) {
      break;
    }
  }
  return u.RXDATAL;
}

void usartPutString(USART &u, const char *text) {
  const char *ptr = text;
  for (;;) {
    char c = *ptr;
    if (c == 0) {
      break;
    }
    usartPutChar(u, c);
    ++ptr;
  }
}
