/*
* stdio.c
* AUTOR: CARLOS IGNACIO OLANO MARES
* Copyrigth 2018 Carlos Ignacio Olano Mares <alumno_carlosignacio@hotmail.com>
*/
#include <stdio.h>
#include <stdarg.h>
#define COLOR_NEGRO 0x00 
#define COLOR_AZUL 0x01 
#define COLOR_VERDE 0x02 
#define COLOR_AZULCLARO 0x03 
#define COLOR_ROJO 0x04 
#define COLOR_ROSA 0x05 
#define COLOR_NARANJA 0x06 
#define COLOR_BLANCO 0x07 
#define COLOR_GRIS 0x08 
#define COLOR_MORADO 0x09 
#define FONDO_AZUL 0x10 
#define FONDO_VERDE	0x20 
#define FONDO_AZULCLARO 0x30 
#define FONDO_ROJO 0x40 
#define FONDO_ROSA 0x50 
#define FONDO_NARANJA 0x06 
#define FONDO_BLANCO 0x70 
#define FONDO_GRIS 0x80 
#define FONDO_MORADO 0x90 
char *__VIDMEM__ = (char *) 0xb8000;
#define ITOA 		0x01
#define LOWER_CASE 	0x02
#define UPPER_CASE 	0x04
#define VIDEO_TEXT 0xB8000
unsigned short *video_txt=(unsigned short *)VIDEO_TEXT;
int printf(char * buf, ...)
{
	char ch;
	int lflags=0;
	int i=0;
	int number_arg;
	char * string;
	char number[20];
	unsigned long len;
	va_list args;
	va_start(args,buf);
	for(;;){
		while((ch = *buf++)!= '%'){
			if(ch=='\0'){va_end(args); return;}
			putchar(ch);
		}
		switch(*buf++){
		case '%': putchar('%');break;
		case '-': putchar(' ');break;
		case 'c': putchar(va_arg(args,char));break;
		case 's':
			string=va_arg(args,char *);
			while(*string!='\0')
				putchar(*string++);
			break;
		case 'i':
		case 'd':
			number_arg=va_arg(args,int);
			if(number_arg == 0){
				putchar('0');
				break;
			}
			i=19;
			for(i=19; number_arg!=0; i--,number_arg/=10)
				number[i]=(number_arg%10)+'0';
			i++;
			while(i<20)
				putchar(number[i++]);
			break;
		case 'x':
			lflags|=ITOA;
			lflags|=LOWER_CASE;
			break;
		case 'X':
			lflags|=ITOA;
			lflags|=UPPER_CASE;
			break;
		case 'p':
			putchar('[');
			number_arg=va_arg(args,unsigned long);
			for(i=7; i>=0; i--,number_arg>>=0x04)
			{
				if((number_arg&0x0F)>9)
					number[i]=(number_arg&0x0F)+'A'-10;
				else
					number[i]=(number_arg&0x0F)+'0';
			}
			i++;
			while(i!=8)
			{
				if(i==4)
					putchar(':');
				putchar(number[i++]);
			}
			putchar(']');
			break;
		default:
			break;
		}
		if(lflags&ITOA){
			number_arg=va_arg(args,unsigned long);
			if(number_arg==0){
				putchar('0');
			}
			else{
				for(i=7; number_arg!=0;
					i--,number_arg=(number_arg>>4)&0x0FFFFFFF)
				{
					if((number_arg&0x0F)>9){
						if(lflags&LOWER_CASE)
							number[i]=(number_arg&0x0F)+'a'-10;
						else
							number[i]=(number_arg&0x0F)+'A'-10;
					}
					else
						number[i]=(number_arg&0x0F)+'0';
				}
				i++;
				while(i<8)
					putchar(number[i++]);
			}
			lflags=0;
		}
	}
}
int putchar(char ch)
{
	static unsigned int crs_y=0;
        static unsigned int crs_x=0;
	unsigned short temp;
	unsigned short blank;
	blank=0x20|(0x0F<<8);
	int i;
	int b;
        int c; //retroceso
        c=0;
	if(ch=='\n'){
		crs_y++;
		crs_x=0;
		return;
	}
	if(ch=='\t'){
		crs_x+=4;
		return;
	}

        if(ch=='\b'){
		crs_x--;
                ch=' ';
                c=1;
	}
        
	if(crs_x==80){
		crs_y++;
		crs_x=0;
	}
	if(crs_y>=25){
		//Move the text one line up.
        memcpy ((void *)VIDEO_TEXT,(void *)(VIDEO_TEXT + 80*2),25 * 80 * 2);
        //Clean the last line.
        memsetw((void *)(VIDEO_TEXT + 24 * 80 * 2), blank, 80);
        crs_y = 24;
	}
	video_txt=(unsigned short *)(VIDEO_TEXT+(crs_y*80+crs_x)*2);
	*video_txt=ch|(0x7<<8);
	c==1 ? : crs_x++;
	return 0;
}
int puts(char *c){
printf(c);
}
void cls()
{
	char *text_video = (char*)0xB8000; //direccion de la video
	int i;

    for(i=0;i<4000;i++){ //toda la pantalla
		*text_video++ = 0x00; //en color negro
    }
}
unsigned int k_xy_printf(char *message, unsigned int x, unsigned int y, int color) 
// El mensaje y su posicion X e Y   
{ 	
	char *vidmem = (char *) 0xb8000; 	unsigned int i = 0; 	
	if((x == 0) && (y == 0))
	{ 		
		i=(0); 	
	}
	else if(y == 0)
	{ 		
		i=(x*2); 	
	}
	else if(x == 0)
	{ 		
		i=(y*2); 	
	}
	else
	{ 		
		i=(y*x*2); 	
	};
	while(*message!=0) 	
	{ 		
		if(*message=='\n') 
		// comprobamos para el caracter especial de nueva linea 		
		{ 			
			y++; 			
			x=0; 			
			if((x == 0) && (y == 0))
			{ 				
				i=(0); 			
			}
			else if(y == 0)
			{ 				
				i=(x*2); 			
			}
			else if(x == 0)
			{ 				
				i=(y*2); 			
			}
			else
			{ 				
				i=(y*x*2); 		
			}; 			
			*message++; 		
		} 
		else 
		{ 			
			if( x >= 80)
			{ 				
				while(x >=80)
				{ 					
					x -= 80; 				
				}; 				
				if((x == 0) && (y == 0))
				{ 					
					i=(0); 				
				}
				else if(y == 0)
				{ 					
					i=(x*2); 				
				}
				else if(x == 0)
				{ 					
					i=(y*2); 				
				}
				else
				{ 					
					i=(y*x*2); 				
				}; 			
			}; 			
			vidmem[i]=*message; 			
			*message++; 			
			i++; 			
			vidmem[i]=color; 			
			i++; 		
		}; 	
	}; 	
	return(1); 
};
int scanf (char *format, unsigned args)
{
	return doscanf (0, stdin, format, &args);
}
int doscanf ( int code, char *funcarg, char *format, unsigned ptr_union *argp)
{
	int             done = 0;	/* number of items done */
	int             base;		/* conversion base */
	long            val;		/* an integer value */
	int             sign;		/* sign flag */
	int             do_assign;	/* assignment suppression flag */
	unsigned        width;		/* width of field */
	int             widflag;	/* width was specified */
	int             longflag;	/* true if long */
	int             done_some;	/* true if we have seen some data */
	int		reverse;	/* reverse the checking in [...] */
	char	       *endbracket;     /* position of the ] in format string */
	rnc_arg = funcarg;
	rnc_code = code;
	rnc ();			/* read the next character */
	if (ic == EOF) {
		done = EOF;
		goto quit;
	}
	while (1) {
		while (iswhite (*format))
			++format;	/* skip whitespace */
		if (!*format)
			goto all_done;	/* end of format */
		if (ic < 0)
			goto quit;	/* seen an error */
		if (*format != '%') {
			while (iswhite (ic))
				rnc ();
			if (ic != *format)
				goto all_done;
			++format;
			rnc ();
			++done;
			continue;
		}
		++format;
		do_assign = 1;
		if (*format == '*') {
			++format;
			do_assign = 0;
		}
		if (isdigit (*format)) {
			widflag = 1;
			for (width = 0; isdigit (*format);)
				width = width * 10 + *format++ - '0';
		} else
			widflag = 0;	/* no width spec */
		if (longflag = (tolower (*format) == 'l'))
			++format;
		if (*format != 'c')
			while (iswhite (ic))
				rnc ();
		done_some = 0;	/* nothing yet */
		switch (*format) {
		case 'o':
			base = 8;
			goto decimal;
		case 'u':
		case 'd':
			base = 10;
			goto decimal;
		case 'x':
			base = 16;
			if (((!widflag) || width >= 2) && ic == '0') {
				rnc ();
				if (tolower (ic) == 'x') {
					width -= 2;
					done_some = 1;
					rnc ();
				} else {
					ugc ();
					ic = '0';
				}
			}
	decimal:
			val = 0L;	/* our result value */
			sign = 0;	/* assume positive */
			if (!widflag)
				width = 0xffff;	/* very wide */
			if (width && ic == '+')
				rnc ();
			else if (width && ic == '-') {
				sign = 1;
				rnc ();
			}
			while (width--) {
				if (isdigit (ic) && ic - '0' < base)
					ic -= '0';
				else if (base == 16 && tolower (ic) >= 'a' && tolower (ic) <= 'f')
					ic = 10 + tolower (ic) - 'a';
				else
					break;
				val = val * base + ic;
				rnc ();
				done_some = 1;
			}
			if (do_assign) {
				if (sign)
					val = -val;
				if (longflag)
					*(argp++)->ulong_p = (unsigned long) val;
				else
					*(argp++)->uint_p = (unsigned) val;
			}
			if (done_some)
				++done;
			else
				goto all_done;
			break;
		case 'c':
			if (!widflag)
				width = 1;
			while (width-- && ic >= 0) {
				if (do_assign)
					*(argp)->chr_p++ = (char) ic;
				rnc ();
				done_some = 1;
			}
			if (do_assign)
				argp++;	/* done with this one */
			if (done_some)
				++done;
			break;
		case 's':
			if (!widflag)
				width = 0xffff;
			while (width-- && !iswhite (ic) && ic > 0) {
				if (do_assign)
					*(argp)->chr_p++ = (char) ic;
				rnc ();
				done_some = 1;
			}
			if (do_assign)		/* terminate the string */
				*(argp++)->chr_p = '\0';	
			if (done_some)
				++done;
			else
				goto all_done;
			break;
		case '[':
			if (!widflag)
				width = 0xffff;

			if ( *(++format) == '^' ) {
				reverse = 1;
				format++;
			} else
				reverse = 0;
			
			endbracket = format;
			while ( *endbracket != ']'  && *endbracket != '\0')
				endbracket++;
			
			if (!*endbracket)
				goto quit;
			
			*endbracket = '\0';	/* change format string */
			while (width-- && !iswhite (ic) && ic > 0 &&
				(index (ic, format) ^ reverse)) {
				if (do_assign)
					*(argp)->chr_p++ = (char) ic;
				rnc ();
				done_some = 1;
			}
			format = endbracket;
			*format = ']';		/* put it back */
			if (do_assign)		/* terminate the string */
				*(argp++)->chr_p = '\0';	
			if (done_some)
				++done;
			else
				goto all_done;
			break;
		}		/* end switch */
		++format;
	}
all_done:
	if (ic >= 0)
		ugc ();		/* restore the character */
quit:
	return done;
}
void strcat(char *dest, const char *org)
{
        while(*dest!=0){
             ++dest;
        }
            while (*org!=0){
             *dest++ = *org++;
            }
}
int strcmp(const char *s,const char *t)
 {
  unsigned char *ss = s;
  unsigned char *tt = t;
  char p;
  int a=0,b=0,c=0;

          while(1){
               a = (int)(p=*ss++);
               b = (int) *tt++;
               c = a - b;
               if(c || !p)break;
          }
  return c;
}
int strcpy(char *dest,const char *org)
 {
 char tk;
 int i=0;
         do{
            *dest++ = tk = *org++;
            i++;
           }while(tk);
 return i;
 }
void *memcpy(void *dest,const void *source,unsigned long length)
{
	unsigned int d0;
	__asm__ __volatile__("rep  movsl"
		: "=S"(source), "=D"(d0)
		: "S"(source), "D"(dest), "c"(length>>2)
	);
	__asm__ __volatile__("rep movsb"
		:
		: "S"(source), "D"(d0), "c"(length&0x03)
	);
	return dest;
}
void *memset(void *dest, unsigned char value,unsigned long length)
{
	unsigned int d0;
	__asm__ __volatile__("rep  stosb"
		: "=D"(d0)
		: "a"(value), "D"(dest), "c"(length)
	);
	return dest;
}
unsigned short *memsetw(unsigned short *dest, unsigned short value,unsigned long length)
{
	unsigned int d0;
	__asm__ __volatile__("rep  stosw"
		: "=D"(d0)
		: "a"(value), "D"(dest), "c"(length)
	);
}
unsigned long *memsetl(unsigned long *dest, unsigned int value,unsigned long length)
{
	unsigned int d0;
	__asm__ __volatile__("rep  stosl"
		: "=D"(d0)
		: "a"(value), "D"(dest), "c"(length)
	);
}
int strlen(const char *text)
{
 int i=0;
          while(*text!=0){ //mientras no sea 0 contamos
               *text++;
               i++;
          }
 return i; //retornamos
}
int isdigit(char c)
{
  if (c >= '0' && c <= '9')
	return(1);
  else
	return(0);
}