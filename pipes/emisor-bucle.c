#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int fifo;
	char mensaje[200];
	char entrada[150];
	while(1){
		scanf("%[^\n]s",entrada);
		getchar();
		printf("Enviando: %s: %s\n",argv[1],entrada);
		sprintf(mensaje, "-%s: %s",argv[1],entrada);

		fifo = open("./pipe2", O_RDWR);
		if(fifo == -1){
			fprintf(stderr, "Error.\n");
		}
		fprintf(stdout, "Enviando mensaje...");
		write(fifo, mensaje, sizeof(char)*(strlen(mensaje)+1));
		fprintf(stdout, "¡Hecho!\n\n");
		close(fifo);
	}
	return 0;
}