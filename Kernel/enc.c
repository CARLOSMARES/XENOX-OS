#include <enc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 80

void encriptarFrase();
void desencriptarFrase();

int largo;
char frase[N];

void encriptarFrase ()
{
    
    largo = strlen(frase);

    int i;

    for(i=0 ; i<largo ; ++i)
    {
        //convierte las minuscalas a mayuscula.
        *(frase + i) = toupper(*(frase + i));

        //descarta los digitos
        if(isalpha(*(frase + i)))
        {
            //verifica los casos especiales X-Y-Z
            if(*(frase + i) > 87)
            {
                *(frase+i) = *(frase+i) - 23;
            }
            else
            {
                *(frase + i) = *(frase + i) + 3;
            }
        }
    }
}

void desencriptarFrase ()
{
    
    largo = strlen(frase);

    int i;

    for(i=0 ; i<largo ; ++i)
    {
        if(isalpha(*(frase + i)))
        {
            if(*(frase + i) < 68)
            {
                *(frase+i)= *(frase+i) + 23;
            }
            else
            {
                *(frase+i)= *(frase+i) - 3;
            }
        }
    }
}