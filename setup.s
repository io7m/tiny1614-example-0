.text

__stackPointerH  = 0x3e
__stackPointerL  = 0x3d
__statusRegister = 0x3f

.global __setup

__setup:
  # Clear the status register
  eor r1,r1
  out __statusRegister,r1

  # Configure the stack pointer to start at 0x3fff
  ldi r29,0x3f
  out __stackPointerH,r29
  ldi r29,0xff
  out __stackPointerL,r29

  # Execute main
  call main
  nop
  nop
  nop
  nop

