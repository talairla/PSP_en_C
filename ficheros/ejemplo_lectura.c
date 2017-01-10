#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char buffer[10];
	int fd; //Descriptor de fichero
	int bytesleidos = 1;

	fd = open("texto.txt", O_RDONLY);

	if (fd == -1){

		fprintf(stderr,"El fichero no se ha podido abrir.\n");
		exit(-1);
	}

	while ( bytesleidos != 0){
		bytesleidos = read ( fd , buffer , 10 );
		fprintf (stdout,"He leído: %s\n", buffer);	
	}

	close(fd);



	return 0;
}