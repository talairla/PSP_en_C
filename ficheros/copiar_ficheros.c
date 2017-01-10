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
	int fd1, fd2; //Descriptor de fichero
	int bytesleidos = -1;

	fd1 = open("./fichero1.txt", O_RDONLY);
	fd2 = open("./fichero2.txt", O_WRONLY | O_CREAT, S_IRWXU | S_IRGRP);

	if (fd1 == -1){
		fprintf(stderr,"El fichero de lectura no se ha podido abrir.\n");
		exit(-1);
	}

	if (fd2 == -1){
		fprintf(stderr,"El fichero de escritura no se ha podido abrir.\n");
		exit(-1);
	}

	while ( bytesleidos != 0 ){
		bytesleidos = read ( fd1 , buffer , 10 );
		write(fd2, buffer, bytesleidos);
	}

	close(fd1);
	close(fd2);
	
	return 0;
}