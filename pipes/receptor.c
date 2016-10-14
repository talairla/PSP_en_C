#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	
	int fifo;
	char buffer[100];
	fifo = open("./pipe1", O_RDWR);
	if(fifo == -1){
		fprintf(stderr, "Error\n");
	}

	fprintf(stdout, "Esperando mensaje...");
	read(fifo, buffer, sizeof(buffer));
	fprintf(stdout, "¡Hecho!\n\n");
	fprintf(stdout, "Mensaje leído: %s\n", buffer);
	close(fifo);
	
	return 0;
}