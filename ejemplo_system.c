#include <stdlib.h>
#include <stdio.h>

int main(){

	int retorno_system;
	fprintf(stdout, "Ejecutando comando mediante system...\n");
	retorno_system = system("firefox");
	fprintf(stdout, "El comando ha devuelto el siguiente valor de retorno:\n\t%d\n",retorno_system);
  return 0;

}
