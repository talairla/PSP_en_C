#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	
	int fifo;
	char mensaje[]="Hola receptor!\0";
	fifo = open("./pipe1", O_RDWR);
	if(fifo == -1){
		fprintf(stderr, "Error.\n");
	}
	fprintf(stdout, "Enviando mensaje...");
	write(fifo, mensaje, sizeof(char)*(strlen(mensaje)+1));
	fprintf(stdout, "¡Hecho!\n\n");
	close(fifo);
	return 0;
}