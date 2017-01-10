#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char saludo[] = "Un saludo!!!\n";
	char buffer[10];
	int fd; //Descriptor de fichero
	int bytesleidos = 1;

	fd = open("texto_escrito.txt", O_WRONLY | O_CREAT, 0777);

	if (fd == -1){

		fprintf(stderr,"El fichero no se ha podido abrir.\n");
		exit(-1);
	}

	write(fd, saludo, strlen(saludo) );

	close(fd);



	return 0;
}