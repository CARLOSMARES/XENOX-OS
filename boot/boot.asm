[BITS 32]

[global start]
[extern k_x_main] ; this is in the c file

start:
  call k_x_main

  cli  ; stop interrupts
  hlt ; halt the CPU
