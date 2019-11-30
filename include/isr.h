/*
* isr.h
* AUTOR: CARLOS IGNACIO OLANO MARES
* Copyrigth 2018 Carlos Ignacio Olano Mares <alumno_carlosignacio@hotmail.com>
*/
//definimos las IRQ//
#define IRQ0 32
#define IRQ1 33
#define IRQ2 34
#define IRQ3 35
#define IRQ4 36
#define IRQ5 37
#define IRQ6 38
#define IRQ7 39
#define IRQ8 40
#define IRQ9 41
#define IRQ10 42
#define IRQ11 43
#define IRQ12 44
#define IRQ13 45
#define IRQ14 46
#define IRQ15 47
//Registros..fundamental para el kernel, de aqui controlamos la syscall,etc//
typedef struct registers
{
    unsigned int ds;                  
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax; 
    unsigned int int_no, err_code;    
    unsigned int eip, cs, eflags, useresp, ss; 
} registros;

typedef void (*registros_isr)(registros*);
void register_interrupt_handler(unsigned char n, registros_isr handler);