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
	char mensaje[]="Hola clase.";
	char final=EOF;

	fd = open("./fich2.txt", O_WRONLY);

	if (fd == -1){
		fprintf(stderr, "Error!!\n");
	}

	write(fd,mensaje,strlen(mensaje)*sizeof(char));
	write(fd,&final,sizeof(char));
	close(fd);

	return 0;
}