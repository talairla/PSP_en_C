#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void tratar_senyal(int);
void tratar_senyalHijo(int);

int main(int argc, char const *argv[])
{
	pid_t pid;
	int i;
	pid = fork();

	switch (pid){
		case -1:
			fprintf(stderr, "Error en el fork\n");
			exit(-1);
		case 0:
			signal(SIGINT,tratar_senyalHijo);
			fprintf(stdout, "Soy el hijo. Mi pid: %d\n",getpid());
			while(1){
				system("ping -c 1 8.8.8.8 > fich_ping.txt");
				kill(getppid(),SIGUSR1);
				sleep(2);
			}
			break;
		default:

			signal(SIGUSR1,tratar_senyal);
			fprintf(stdout, "Soy el padre. Mi pid: %d\n",getpid());
			for(i = 0; i<5; i++){
				pause();
			}
			kill(pid,SIGINT);
	}		

	return 0;
}

void tratar_senyal(int cod_senyal){
	fprintf(stdout, "=========Fichero fich_ping.txt=========\n");
	system("cat fich_ping.txt");
	fprintf(stdout, "=======================================\n\n\n");

}

void tratar_senyalHijo(int cod_senyal){

	fprintf(stderr, "Mi padre me dice que pare...\n");
	exit(-1);

}