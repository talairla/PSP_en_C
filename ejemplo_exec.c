#include <unistd.h> //Librería para execl
#include <stdio.h> //Librería para fprintf

int main(){

	int retorno_execl;
	fprintf(stdout, "Ejecutando xed vía execl...\n");
	retorno_execl = execl("/usr/bin/xed","xed", (char *)NULL);
	sleep(1);
	fprintf(stderr, "xed acabó con el siguiente valor de retorno: \n\t%d.",retorno_execl);
	sleep(1);
	return 0;
}
