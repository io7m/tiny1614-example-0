#ifndef CLOCK_CONTROL_H
#define CLOCK_CONTROL_H

#include "integer.h"

typedef struct {
  volatile uint8 MCLKCTRLA;
  volatile uint8 MCLKCTRLB;
  volatile uint8 MCLKLOCK;
  volatile uint8 MCLKSTATUS;
  volatile uint8 RESERVED_A[12];
  volatile uint8 OSC20MCTRLA;
  volatile uint8 OSC20MCALIBA;
  volatile uint8 OSC20MCALIBB;
  volatile uint8 RESERVED_B[5];
  volatile uint8 OSC32KCTRLA;
  volatile uint8 RESERVED_C[3];
  volatile uint8 XOSC32KCTRLA;
} ClockControl;

constexpr uint16 CLKCTRL_ADDRESS = 0x0060;

static_assert(sizeof(ClockControl) == 0x1D, "");

#endif // CLOCK_CONTROL_H
