#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>


int g = 4;

int main(int argc, char const *argv[])
{
	
	pid_t pid;
	int a = 0;
	pid = fork();

	switch (pid){
		case -1: 
			perror("Error en el fork");
			exit(-1);
			break;
		case 0: //hijo
			g++; a++;
			printf("Hijo-> g: %d.    a: %d\n", g,a);
			break;
		default:
			g--; a--;
			printf("Padre-> g: %d.    a: %d\n", g,a);
			break;
	}
	wait(NULL);
	return 0;
}