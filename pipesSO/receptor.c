#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	
	int tuberia;
	char mensaje[100];
	tuberia = open("./pipe", O_RDWR);
	if(tuberia==-1){
		fprintf(stderr, "Error en la apertura del pipe\n");
		exit(-1);
	}
	fprintf(stderr,"Leyendo mensaje...");
	read(tuberia,mensaje,sizeof(mensaje));
	fprintf(stderr, "¡Hecho!\n\n");
	fprintf(stdout, "El mensajes es: %s\n", mensaje );
	close(tuberia);

	return 0;
}