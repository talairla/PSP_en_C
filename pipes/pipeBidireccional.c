#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int pipe_padreHijo[2];
	int pipe_hijoPadre[2];
	char buffer[100];
	pid_t pid;
	int retorno;

	retorno = pipe(pipe_padreHijo);
	if(retorno == -1){
		fprintf(stderr, "error! creando el pipe padreHijo\n" );
		exit(-1);
	}

	retorno = pipe(pipe_hijoPadre);
	if(retorno == -1){
		fprintf(stderr, "error! creando el pipe hijoPadre\n" );
		exit(-1);
	}

	pid=fork();

	switch(pid){
		case -1: //Caso de error
			fprintf(stderr, "No se ha podido crear el proceso hijo");
			exit(-1);
			break;
		case 0: //Proceso hijo
			close(pipe_hijoPadre[0]);
			close(pipe_padreHijo[1]);
			fprintf(stdout, "Soy el hijo voy a escribir en el pipe %d...\n", pipe_hijoPadre[1]);
			sleep(2);
			char mensaje[] = "Hola, soy tu hijo.\0";
			write(pipe_hijoPadre[1], mensaje, (strlen(mensaje)+1)*sizeof(char) );
			read(pipe_padreHijo[0], buffer, sizeof(buffer) );
			fprintf(stdout, "Soy el hijo. He recibido el siguiente mensaje: %s\n",buffer);

			break;
		default:
			close(pipe_hijoPadre[1]);
			close(pipe_padreHijo[0]);
			char mensaje1[] = "Yo soy tu padre.\0";
			fprintf(stdout, "Hola soy el padre voy a leer del pipe...\n");
			write( pipe_padreHijo[1], mensaje1, (strlen(mensaje1)+1)*sizeof(char));
			read( pipe_hijoPadre[0], buffer, sizeof(buffer));
			fprintf(stdout,"Mensaje leído: %s\n", buffer );
			wait(NULL);
			break;
	}
return 0;
}