#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char const *argv[])
{
	
	int fd[2];  //Pipe
	char buffer[40];
	pid_t pid;
	int retorno;
	int enviados=0;

	retorno = pipe(fd); //Creo el pipe!

	if (retorno == -1){
		fprintf(stderr, "Error en el pipe\n");
		exit(-1);
	}

	pid = fork();

	switch(pid){
		case -1:
			fprintf(stderr, "Error en el fork\n");
			exit(-1);
			break;
		case 0: //Proceso hijo.
			fprintf(stdout, "Soy el hijo\n");
			char mensaje[]  = "Hola, soy tu hijo.";
			char mensaje2[]  = "¿Qué tal?.\0";
			enviados = write(fd[1], mensaje, ( strlen(mensaje) )*sizeof(char) );
			fprintf(stdout, "Enviados %d caracteres del mensaje 1\n",enviados);
			enviados = write(fd[1], mensaje2, ( strlen(mensaje2)+1 )*sizeof(char) );
			fprintf(stdout, "Enviados %d caracteres del mensaje 2\n",enviados);
			break;
		default: //Proceso padre.
			fprintf(stdout, "Soy el padre\n" );
			sleep(2);
			read( fd[0], &buffer, sizeof(buffer));
			fprintf(stdout, "%s\n", buffer );
			wait(NULL);
	}

	return 0;
}