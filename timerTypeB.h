#ifndef TIMER_TYPE_B_H
#define TIMER_TYPE_B_H

#include "integer.h"

typedef struct {
  volatile uint8 CTRLA;
  volatile uint8 CTRLB;
  volatile uint8 RESERVED_A[2];
  volatile uint8 EVCTRL;
  volatile uint8 INTCTRL;
  volatile uint8 INTFLAGS;
  volatile uint8 STATUS;
  volatile uint8 DBGCTRL;
  volatile uint8 TEMP;
  volatile uint16 CNT;
  volatile uint16 CCMP;
} TimerTypeB;

constexpr uint16 TCB0_ADDRESS = 0x0A40;
constexpr uint16 TCB1_ADDRESS = 0x0A50;

static_assert(sizeof(TimerTypeB) == 0x0E, "");

#endif // TIMER_TYPE_A_H
