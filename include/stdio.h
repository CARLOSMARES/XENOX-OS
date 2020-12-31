/*
* stdio.h
* AUTOR: CARLOS IGNACIO OLANO MARES
* Copyrigth 2018 Carlos Ignacio Olano Mares <alumno_carlosignacio@hotmail.com>
*/
#ifndef _STDIO_H
#define _STDIO_H
int printf(char *str, ...);
unsigned int k_xy_printf(char *message, unsigned int x, unsigned int y, int color);
void strcat(char *dest, const char *org);
void cls();
int strlen(const char *text);
int strcmp(const char *s,const char *t);
int strcpy(char *dest,const char *org);
int putchar(char ch);
void *memcpy(void *dest,const void *source,unsigned long length);
void *memset(void *dest, unsigned char value,unsigned long length);
unsigned short *memsetw(unsigned short *dest, unsigned short value,unsigned long length);
unsigned long *memsetl(unsigned long *dest, unsigned int value,unsigned long length);
void sleep(int ms);
int kprintf(int linia,int columna,char *text,char *color);
int puts(char *c);
int atoi(char* palabra); 
char* gets();
unsigned char getch();
int scanf(char *format, unsigned args);
int doscanf( int code, char *funcarg, char *format, char ptr_union *argp);
int isdigit(char c);
#define cli() __asm__("cli")
#define sti() __asm__("sti")

//si hay un panic detenemos el kernel luego de mostrar el Error.
#define panic(msg) ({\
	 asm volatile("cli");\
	printf("Error Irrecuperable del Kernel" + msg); \
	for(;;); \
	__asm__
     (
     	"mov ax, 0"
     	"int 19h	"		// Reboot the system
     );
	})

#define ASSERT(msg) ({\
	 asm volatile("cli");\
	printf(msg); \
	for(;;); \
	__asm__
     (
     	"mov ax, 0"
     	"int 19h	"		// Reboot the system
     );
	})

#define BUFSIZ  1024
#define NFILES  20
#define NULL       0
#define EOF     (-1)
#define CMASK   0377

#define READMODE     1
#define WRITEMODE    2
#define UNBUFF       4
#define _EOF         8
#define _ERR        16
#define IOMYBUF     32
#define PERPRINTF   64
#define STRINGS    128

#ifndef FILE

extern struct _io_buf {
    int     _fd;
    int     _count;
    int     _flags;
    char   *_buf;
    char   *_ptr;
}  *_io_table[NFILES];


#endif	/* FILE */

#define FILE struct _io_buf

#define stdin  (_io_table[0])	
#define stdout 	(_io_table[1])
#define stderr 	(_io_table[2])

#define getchar() 		getc(stdin)
#define putchar(c) 		putc(c,stdout)
#define puts(s)			fputs(s,stdout)
#define fgetc(f)		getc(f)
#define fputc(c,f)		putc(c,f)
#define feof(p) 		(((p)->_flags & _EOF) != 0)
#define ferror(p) 		(((p)->_flags & _ERR) != 0)
#define fileno(p) 		((p)->_fd)
#define rewind(f)		fseek(f, 0L, 0)
#define testflag(p,x)		((p)->_flags & (x))

#define noperprintf(p)		((p)->_flags &= ~PERPRINTF)
#define perprintf(p)		((p)->_flags |= PERPRINTF)

#endif