#ifndef TIMER_TYPE_D_H
#define TIMER_TYPE_D_H

#include "integer.h"

typedef struct {
  volatile uint8 CTRLA;
  volatile uint8 CTRLB;
  volatile uint8 CTRLC;
  volatile uint8 CTRLD;
  volatile uint8 CTRLE;
  volatile uint8 RESERVED_A[3];
  volatile uint8 EVCTRLA;
  volatile uint8 EVCTRLB;
  volatile uint8 RESERVED_B[2];
  volatile uint8 INTCTRL;
  volatile uint8 INTFLAGS;
  volatile uint8 STATUS;
  volatile uint8 RESERVED_C;
  volatile uint8 INPUTCTRLA;
  volatile uint8 INPUTCTRLB;
  volatile uint8 FAULTCTRL;
  volatile uint8 RESERVED_D;
  volatile uint8 DLYCTRL;
  volatile uint8 DLYVAL;
  volatile uint8 RESERVED_E[2];
  volatile uint8 DITCTRL;
  volatile uint8 DITVAL;
  volatile uint8 RESERVED_F[4];
  volatile uint8 DBGCTRL;
  volatile uint8 RESERVED_G[3];
  volatile uint16 CAPTUREA;
  volatile uint16 CAPTUREB;
  volatile uint8 RESERVED_H[2];
  volatile uint16 CMPASET;
  volatile uint16 CMPACLR;
  volatile uint16 CMPBSET;
  volatile uint16 CMPBCLR;
} TimerTypeD;

constexpr uint16 TCD0_ADDRESS = 0x0A80;

static_assert(sizeof(TimerTypeD) == 0x30, "");

#endif // TIMER_TYPE_D_H
