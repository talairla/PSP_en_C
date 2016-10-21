#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "./mi_hora.h"

int main(int argc, char const *argv[])
{
	
	int fifo;
	char buffer[100];
	int retorno_mknod;
	retorno_mknod = mknod("./pipe2", S_IFIFO|0666, 0);
	if (retorno_mknod == -1){
		fprintf(stderr, "Error al crear el pipe2\n");
		exit(-1);
	}

	while(1){
		fifo = open("./pipe2", O_RDONLY);
		if(fifo == -1){
			fprintf(stderr, "Error\n");
		}
		read(fifo, buffer, sizeof(buffer));
		imprimir_hora();
		fprintf(stdout, " %s\n",buffer);
		close(fifo);
	}
	return 0;
}