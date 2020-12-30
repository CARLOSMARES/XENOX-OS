;[BITS 32] ; Se especifica que es de tipo x86 o de 32 bits

;[global start] ; Etiqueta que apunta al binario de inicio del programa
;[extern k_x_main] ; esto esta en el archivo C de Kernel

;start:
;  call k_x_main ;Manda llamar a la funcion principal del kernel

;  cli  ; Detener Interrupciones
;  hlt ; halt the CPU

#define MULTIBOOT_HEADER_MAGIC 0x1BADB002
#define MULTIBOOT_HEADER_FLAGS 0x00000003
#define STACK_SIZE 0x4000

.text
.globl start
start:
	jmp multiboot_entry
	.align 4
multiboot_header:
	.long 0x1BADB002
	.long 0x00000003
	.long -(0x1BADB002+0x00000003)
multiboot_entry:
	movl $(stack + 0x4000), %esp
	call k_x_main
loop: hlt
	jmp loop
.section ".bss"
	.comm stack,0x4000