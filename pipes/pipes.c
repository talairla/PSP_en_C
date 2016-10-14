#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int fd[2];
	char buffer[100];
	pid_t pid;
	int retorno;

	retorno = pipe(fd);
	if(retorno == -1){
		fprintf(stderr, "error! creando el pipe\n" );
		exit(-1);
	}

	pid=fork();

	switch(pid){
		case -1: //Caso de error
			fprintf(stderr, "No se ha podido crear el proceso hijo");
			exit(-1);
			break;
		case 0: //Proceso hijo
			close(fd[0]);
			fprintf(stdout, "Soy el hijo voy a escribir en el pipe...\n");
			sleep(2);
			char mensaje[] = "Hola, soy tu hijo.\0";
			write(fd[1], mensaje, (strlen(mensaje)+1)*sizeof(char) );
			break;
		default:
			close(fd[1]);
			fprintf(stdout, "Hola soy el padre voy a leer del pipe...\n");
			read( fd[0], &buffer, sizeof(buffer));
			fprintf(stdout,"Mensaje leído: %s\n", buffer );
			wait(NULL);
			break;
	}
return 0;
}