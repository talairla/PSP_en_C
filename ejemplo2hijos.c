#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	
	pid_t pid1, pid2, pid3, pid_ret1, pid_ret2;

	pid1 = getpid();

	pid2 = fork();

	if (pid2 == -1){
		fprintf(stderr, "Error en el fork\n" );
		exit(-1);
	}
	if (pid2 == 0){
		fprintf(stdout, "Hola soy el primer hijo. Mi Pid es:%d\n",getpid());
	}
	else{
		fprintf(stdout, "Hola soy el padre. Mi Pid es %d y el de mi hijo es: %d\n", pid1, pid2);
		pid3 = fork();
		if (pid3 == -1){
			fprintf(stderr, "Error en el fork\n" );
			exit(-1);
		}
		if (pid3 == 0){
			fprintf(stdout,"Hola soy el segundo hijo. Mi Pid: %d \n",getpid());
		}else{
			fprintf(stdout,"soy el padre, voy a esperar a un hijo\n");
			pid_ret1 = wait( NULL );
			fprintf(stdout, "El hijo %d ha terminado\n", pid_ret1);
			pid_ret2 = wait( NULL );
			fprintf(stdout, "El hijo %d ha terminado\n", pid_ret2);
		}
		
	}

}