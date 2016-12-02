#include<stdio.h>
 
 void es_primo(long long int);

 int main(int argc, char const *argv[])
 {
    
   es_primo(961748941);
   es_primo(982451653);
   es_primo(941083987);


   return 0;
 }

void es_primo(long long int n)
{
   int c = 2;
   for ( c = 2 ; c <= n - 1 ; c++ )
   {
      if ( n%c == 0 )
      {
         printf("%lld is not prime.\n", n);
	      break;
      }
   }
   if ( c == n ){
      printf("%lld is prime.\n", n);
   }

 }