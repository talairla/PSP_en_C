#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int fd; //File descriptor. Descriptor de fichero.
	char mensaje[]="Hola clase.\n";
	int char_escritos=1;
	int longitud;

	fd = open("./fich2.txt", O_WRONLY | O_TRUNC);

	if (fd == -1){
		fprintf(stderr, "Error!!\n");
		exit(-1);
	}
	longitud = strlen(mensaje);
	while ( char_escritos != 0){
		char_escritos = write(fd,mensaje,longitud*sizeof(char));
		longitud = longitud - char_escritos;
	}
	close(fd);

	return 0;
}