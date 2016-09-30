#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	pid_t pid_hijo;

	fprintf(stdout, "Antes del fork:\n");
	fprintf(stdout, "\tPID proceso actual: %d\n", getpid() );
	fprintf(stdout, "\tPID proceso padre: %d\n\n=====\n\n", getppid());

	pid = fork();

	if (pid == -1){
		fprintf(stderr, "Error en el fork()\n");
		exit(-1);
	}
	if (pid == 0){ //Nos encontramos en el proceso hijo.
		fprintf(stdout, "En el Hijo. PID:%d\n", getpid());
		fprintf(stdout, "En el Hijo. PPID:%d\n", getppid());
		sleep(5);
	}else{  //Este será el proceso padre.
		fprintf(stdout, "En el Padre. PID:%d\n", getpid());
		fprintf(stdout, "En el Padre. PPID:%d\n", getppid());
		pid_hijo = wait( NULL );
		fprintf(stdout, "En el Padre. Mi hijo con pid: %d, ha finalizado\n", pid_hijo);
	}

	return 0;
}