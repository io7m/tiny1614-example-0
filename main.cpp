#include "clockControl.h"
#include "integer.h"
#include "io.h"
#include "timerTypeA.h"
#include "usart.h"

static ClockControl *const CLKCTRL = (ClockControl *)CLKCTRL_ADDRESS;
static IORegister *const PORTA = (IORegister *)PORTA_ADDRESS;
static IORegister *const PORTB = (IORegister *)PORTB_ADDRESS;
static IORegister *const PORTC = (IORegister *)PORTC_ADDRESS;
static TimerTypeANormal *const TCA0 = (TimerTypeANormal *)TCA0_ADDRESS;
static USART *const USART0 = (USART *)USART0_ADDRESS;

constexpr uint16 ONE_SECOND = 39063;

void sleep(uint16 ticks) {

  /*
   * Enable the clock. Use a /64 prescaler to scale the peripheral clock.
   * With the peripheral clock already scaled to 2.5mhz, this yields a ~39
   * khz clock.
   */

  {
    uint8 config = 0;
    config |= (0b101 << 1);
    config |= 0b1;
    TCA0->CTRLA = config;
  }

  TCA0->CNTH = 0;
  TCA0->CNTL = 0;

  for (;;) {
    if (timerCount(*TCA0) >= ticks) {
      return;
    }
  }
}

int main(void) {

  /*
   * Select the internal 20mhz oscillator as the main clock source. This
   * actually just specifies to use the internal oscillator; the fuses actually
   * specify 20mhz and that is the factory default for this IC.
   */

  CLKCTRL->MCLKCTRLA = 0b00000000;

  /*
   * Enable a /8 prescaler for the peripheral clock. With the CPU clock at
   * 20mhz, this yields a 2.5mhz peripheral clock.
   */

  {
    uint8 clock = 0;
    clock |= (0b0010) << 1;
    clock |= 0b1;
    CLKCTRL->MCLKCTRLB = clock;
  }

  /*
   * Pin 0 of port B is unused.
   * Pin 1 of port B is an output (LED).
   * Pin 2 of port B is an output (TXD).
   * Pin 3 of port B is an input (RXD).
   */

  PORTB->DIR = 0b0110;
  PORTB->OUT = 0b0000;

  auto &usart0 = *USART0;
  usartInit(usart0, 9600);
  usartPutString(usart0, "i: start\r");

  for (;;) {
    usartPutString(usart0, "i: tick\r");
    PORTB->OUT |= 0b10;
    sleep(ONE_SECOND);
    PORTB->OUT &= ~0b10;
    sleep(ONE_SECOND);
  }
  return 0;
}
