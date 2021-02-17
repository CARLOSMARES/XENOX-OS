/*
* math.c
* AUTOR: CARLOS IGNACIO OLANO MARES
* Copyrigth 2018 Carlos Ignacio Olano Mares <alumno_carlosignacio@hotmail.com>
*/
#include <math.h>
#define pi=3.1415926535;
int sum(int a, int b)
{
    return a+b;
}
float sum(float a, float b)
{
      return a+b;
}
double sum(double a, double b)
{
       return a+b;
}
int rest(int a, int b)
{
    return a-b;
}
float rest(float a, float b)
{
      return a-b;
}
double rest(double a, double b)
{
       return a-b;
}
int mult(int a, int b)
{
    return a*b;
}
float mult(float a, float b)
{
      return a*b;
}
double mult(double a, double b)
{
       return a*b;
}
int div(int a, int b)
{
    a/b;
}
float div(float a, float b)
{
      a/b;
}
double div(double a, double b)
{
       return a/b;
}
int pow(int base, int exponente)
{
    int sol=1,i;
    for(i=0; i<exponente;i++)
    {
             sol=sol*base;
    }
    return sol;
}
float pow(float base, float exponente)
{
      float sol=1,i;
      for(i=0; i<exponente;i++)
      {
               sol=sol*base;
      }
      return sol;
}
double pow(double base, double exponente)
{
       double sol=1,i;
       for(i=0; i<exponente;i++)
       {
                sol=sol*base;
       }
       return sol;
}
float sqrt(float a)
{
      float res, i=0;
      do
      {
            i=i+0.1;
            res=i*i;
      }
      while(a>=res);
      return i;
}
float circunference(float radio)
{
      return pi*pow(radio,2);
}
double Seno(double x)
{
int s = 1, pot = 3, den;
double n, num = 1, sum;
n = pi * x / 180;
sum = n;
for(int i = 0; i < 4; i++)
{
den *= pot * (pot - 1);
sum += (num / den) * s;
s *= -1;
num *= n * n;
pot += 2;
}
return sum;
}
double Coseno(double x)
{
double pot = 2, num, den = 1.0, n, sum;
int s = -1;
n = pi * x / 180;
sum = 1;
num = n * n;
  for(int i = 0; i < 5; i++)
{
den *= pot * (pot - 1.0);
sum += (num / (den * s));
s *= -1;
pot += 2;
num *= n * n;
}
return sum;
}
float factorial(float k) {
   float z = 1;
 int i;
 for (i = 1; i <= k; i++) {
   z *= i;
 }
 return (z);
}
float exponencial(float x) {
      float suma = 0, ax, error = 0.0001;
      int k = 0;
      do {
          ax = (pow(x, k) / factorial(k));
          suma += ax;
          k++;
          if (ax < 0) {
                 ax = -ax;
          }
      }
      while (ax > error);
      return (suma);
}
float senoh(float x) 
{
      float z = 0;
      z = (exponencial(x) - (1 /exponencial(x))) / 2;
      return (z);
}
float coseh(float x) 
{
      float z = 0;
      z = (exponencial(x) + (1 / exponencial(x))) / 2;
      return (z);
}
int par_impar(int x)
{
    if(x%2==0)
    {
              return 0;
    }
    else
    {
        return 1;
    }
}

int atonum(int numero)
{
    int n;
    if((numero.48)>=0 && (numero-48)<=9)
    {
                      n=numero -48;
    }
    if((numero-48)>0 && (numero-48)>9)
    {
                     n=-1;
    }
    return n;
}

float media( float n1,float n2)
{
      return (n1+n2)/2;
}

float cubo(float numero)
{
      return (numero*numero*numero);
}

float min(float a, float b)
{
      int min;
      min = num1<num2?num1:num2;
      return min;
}

float perimetro_cuadrado(float numero)
{
      return numero*4;
}

float area_cuadrado(float numero)
{
      return numero * numero;
}

float ecuacion2oGrado1 (float a, float b, float c) 
{ 
   float x1; 
    
   x1 = (-b + pow(b*b-4*a*c, 0.5)) / (2*a); 
    
   return x1; 
} 
    
float ecuacion2oGrado2 (float a, float b, float c) 
{ 
   float x2; 
    
   x2 = (-b - pow(b*b-4*a*c, 0.5)) / (2*a); 
  
   return x2; 
}

long serieFibonacci (int n) 
{ 
    
   if ((n == 0) || (n == 1)) 
      return n; 
   else 
      return  serieFibonacci(n - 1) + serieFibonacci(n - 2);       
                  
}

int MCD (int num1, int num2) 
{ 
  int c, D, d, r; 
  
  if (num1 > num2) 
  { 
     D = num1; 
     d = num2; 
  } 
  else 
  { 
     D = num2; 
     d = num1; 
  } 
  c = D/d; 
  r = D % d; 
  while (r != 0) 
  { 
    D = d; 
    d = r; 
    c = D/d; 
    r = D % d; 
  } 
  
  return d; 

}
static long seed = 1L;
int rand()
{
  seed = (1103515245L * seed + 12345) & 0x7FFFFFFF;
  return((int) (seed & 077777));
}