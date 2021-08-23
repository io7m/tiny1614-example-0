#ifndef TIMER_TYPE_A_H
#define TIMER_TYPE_A_H

#include "integer.h"

typedef struct {
  volatile uint8 CTRLA;
  volatile uint8 CTRLB;
  volatile uint8 CTRLC;
  volatile uint8 CTRLD;
  volatile uint8 CTRLECLR;
  volatile uint8 CTRLESET;
  volatile uint8 CTRLFCLR;
  volatile uint8 CTRLFSET;
  volatile uint8 RESERVED_A;
  volatile uint8 EVCTRL;
  volatile uint8 INTCTRL;
  volatile uint8 INTFLAGS;
  volatile uint8 RESERVED_B[2];
  volatile uint8 DBGCTRL;
  volatile uint8 TEMP;
  volatile uint8 RESERVED_C[16];
  volatile uint8 CNTL;
  volatile uint8 CNTH;
  volatile uint8 RESERVED_D[4];
  volatile uint16 PER;
  volatile uint16 CMP0;
  volatile uint16 CMP1;
  volatile uint16 CMP2;
  volatile uint8 RESERVED_E[8];
  volatile uint16 PERBUF;
  volatile uint16 CMP0BUF;
  volatile uint16 CMP1BUF;
  volatile uint16 CMP2BUF;
} TimerTypeANormal;

uint16 timerCount(const volatile TimerTypeANormal &timer) {
  return (((uint16)timer.CNTH) << 8) | ((uint16)timer.CNTL);
}

constexpr uint16 TCA0_ADDRESS = 0x0A00;

static_assert(sizeof(TimerTypeANormal) == 0x3E, "");

#endif // TIMER_TYPE_A_H
