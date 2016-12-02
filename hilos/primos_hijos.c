#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define NHIJOS 3
 
 void es_primo(long long int);

 int main(int argc, char const *argv[])
 {    
   long n_primos[3]={961748941,982451653,941083987};
   int i;
   pid_t pid;

   for (i=0;i<NHIJOS;i++){
      pid=fork();
      switch (pid){
         case -1:
            break;
         case 0:
            es_primo(n_primos[i]);
            break;
         default:
            fprintf(stdout, "Hijo %d lanzado\n", i);
      }
   }
   for (i=0;i<NHIJOS;i++){
      wait(NULL);
   }
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