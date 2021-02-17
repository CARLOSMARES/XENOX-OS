[BITS 32] ; Se especifica que es de tipo x86 o de 32 bits

[global start] ; Etiqueta que apunta al binario de inicio del programa
[extern k_x_main] ; esto esta en el archivo C de Kernel

start:
  call k_x_main ;Manda llamar a la funcion principal del kernel

  cli  ; Detener Interrupciones
  hlt ; halt the CPU