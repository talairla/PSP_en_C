#include <stio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void funcion_senyal( int senyal){

	printf("He recibido la señal: %d\n", senyal);

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
			signal(SIGUSR1, funcion_senyal);
			while(1);
		break;
		default: //Esto es el padre
			sleep(1);
			kill(pid_hijo, SIGUSR1);
			sleep(1);
			kill(pid_hijo, SIGUSR1);
		break;
	}
	return 0;
}