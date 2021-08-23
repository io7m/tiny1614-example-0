#ifndef IO_H
#define IO_H

#include "integer.h"

typedef struct IORegister {
  volatile uint8 DIR;
  volatile uint8 DIR_SET;
  volatile uint8 DIR_CLR;
  volatile uint8 DIR_TGL;
  volatile uint8 OUT;
  volatile uint8 OUT_SET;
  volatile uint8 OUT_CLR;
  volatile uint8 OUT_TGL;
  volatile uint8 IN;
  volatile uint8 INTFLAGS;

  volatile uint8 RESERVED_A[6];

  volatile uint8 PIN0CTRL;
  volatile uint8 PIN1CTRL;
  volatile uint8 PIN2CTRL;
  volatile uint8 PIN3CTRL;
  volatile uint8 PIN4CTRL;
  volatile uint8 PIN5CTRL;
  volatile uint8 PIN6CTRL;
  volatile uint8 PIN7CTRL;
} IORegister;

constexpr uint16 PORTA_ADDRESS = 0x400;
constexpr uint16 PORTB_ADDRESS = 0x420;
constexpr uint16 PORTC_ADDRESS = 0x440;

static_assert(sizeof(IORegister) == 0x18, "");

#endif // IO_H
