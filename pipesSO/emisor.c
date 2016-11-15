#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	
	int tuberia;
	char mensaje[]="Hola receptor!\0";
	tuberia = open("./pipe", O_RDWR);
	if(tuberia==-1){
		fprintf(stderr, "Error en la apertura del pipe\n");
		exit(-1);
	}
	fprintf(stderr,"Enviando mensaje...");
	write(tuberia,mensaje,sizeof(char)*( strlen(mensaje)+1 ));
	fprintf(stderr, "¡Hecho!\n\n");
	close(tuberia);

	return 0;
}