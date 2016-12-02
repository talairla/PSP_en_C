#include <stdio.h>
#include <pthread.h>
 
 void es_primo(long);

 void* funcion_hilo(void*);

 typedef struct{

   long num;

 }entero_largo;

 int main(int argc, char const *argv[])
 {    
   
   entero_largo n1;
   entero_largo n2;
   entero_largo n3;

   n1.num=961748941;
   n2.num=982451653;
   n3.num=941083987;

   pthread_t h1, h2, h3;

   pthread_create(&h1, NULL, funcion_hilo, &n1);
   pthread_create(&h2, NULL, funcion_hilo, &n2);
   pthread_create(&h3, NULL, funcion_hilo, &n3);

   pthread_join(h1,NULL);
   pthread_join(h2,NULL);
   pthread_join(h3,NULL);

   return 0;
 }

void* funcion_hilo(void* param){

   entero_largo* str_ent = (entero_largo*) param;
   es_primo(str_ent->num);

}

void es_primo(long n)
{
   int c = 2;
   for ( c = 2 ; c <= n - 1 ; c++ )
   {
      if ( n%c == 0 )
      {
         printf("%ld is not prime.\n", n);
	      break;
      }
   }
   if ( c == n ){
      printf("%ld is prime.\n", n);
   }
 }