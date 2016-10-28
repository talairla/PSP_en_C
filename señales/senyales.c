#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void funcion_senyal1( int senyal){
	printf("He recibido la señal: %d\n", senyal);
}

void funcion_senyal2( int senyal){
	printf("Me han matado");	
}

int main(int argc, char const *argv[])
{
	int pid_hijo;

	pid_hijo = fork();

	switch(pid_hijo){
		case -1:
			fprintf(stderr, "Error en el fork\n");
			exit(-1);
		break;
		case 0: //Esto es el hijo
			signal(SIGUSR1, funcion_senyal1);
			signal(SIGQUIT, funcion_senyal2);
			pause();
			pause();
			pause();
		break;
		default: //Esto es el padre
			sleep(1);
			kill(pid_hijo, SIGUSR1);
			sleep(1);
			kill(pid_hijo, SIGUSR1);
			sleep(1);
			kill(pid_hijo, SIGQUIT);
			printf("El proceso %d terminó\n",wait(NULL));

		break;
	}
	return 0;
}