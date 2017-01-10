#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	double op1, op2;
	double resultado = 0;
	pid_t pid=0;

	if(argc != 3){
		fprintf(stderr, "El número de argumentos del programa no es correcto.\n");
		exit(-1);
	}
	op1 = atof(argv[1]);
	op2 = atof(argv[2]);
		
	pid = fork();

	if (pid == -1){
		fprintf(stderr, "Error en el fork. 1\n");
		exit(-1);
	}

	if (pid == 0){
		resultado = op1+op2;
		printf("Soy el hijo que suma (%d). El resutlado es: %f\n",getpid(), resultado );
	}else{
		pid = fork();
		if (pid == -1){
			fprintf(stderr, "Error en el fork. 2\n");
			exit(-1);
		 	}
		if (pid == 0){
			resultado = op1-op2;
			printf("Soy el hijo que resta (%d). El resutlado es: %f\n", getpid(), resultado );	
		}else{
			pid = fork();
			if (pid == -1){
				fprintf(stderr, "Error en el fork. 3\n");
				exit(-1);
		 	}
			if (pid == 0){
				resultado = op1*op2;
				printf("Soy el hijo que Multiplica (%d). El resutlado es: %f\n",getpid(), resultado );	
			}else{
				pid = fork();
				if (pid == -1){
					fprintf(stderr, "Error en el fork. 4\n");
					exit(-1);
		 		}
				if (pid == 0){
					resultado = op1/op2;
					printf("Soy el hijo que Divide (%d). El resutlado es: %f\n",getpid(), resultado );	
				}else{
					pid = wait(NULL);
					fprintf(stdout, "El hijo %d ha terminado.\n",pid);
					pid = wait(NULL);
					fprintf(stdout, "El hijo %d ha terminado.\n",pid);
					pid = wait(NULL);
					fprintf(stdout, "El hijo %d ha terminado.\n",pid);
					pid = wait(NULL);
					fprintf(stdout, "El hijo %d ha terminado.\n",pid);
				}
			}
		}
	}
	return 0;
}