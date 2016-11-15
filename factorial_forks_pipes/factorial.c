#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int fd[2]; //declaramos el pipe
	int retorno;
	unsigned long long int resultado = 1;
	int objetivo;
	int medio_objetivo;
	int i;
	pid_t pid;

	if (argc != 2){
		fprintf(stderr, "El número de parámetros tiene que ser 1\n");
		exit(-1);
	}
	objetivo = atoi(argv[1]);
	if(objetivo > 20){
		fprintf(stderr, "El número es demasiado grande. Máx: 20\n" );
		exit(-1);
	}

	retorno = pipe(fd);
	if (retorno == -1){
		fprintf(stderr, "Error en el pipe\n");
		exit(-1);
	}

	medio_objetivo = objetivo / 2;

	pid = fork();

	switch(pid){

		case -1:
			fprintf(stderr, "Error en fork\n");
			exit(-1);
			break;
		case 0: //hijo, la parte alta del factorial
			for(i=objetivo;i>medio_objetivo;i--){
				resultado = resultado * i;
			}
			fprintf(stdout, "Hijo: A mí me ha salido: %llu\n",resultado );
			close(fd[0]);
			write(fd[1], &resultado ,sizeof(unsigned long long int));
			close(fd[1]);
			break;
		default: //padre la parte baja del factorial
			for(i=medio_objetivo;i>0;i--){
				resultado = resultado * i;
			}
			fprintf(stdout, "Padre: A mí me ha salido: %llu\n",resultado );
			//Esperar resultado del hijo
			unsigned long long int resultado_hijo;
			//Multiplicar los diferentes resultados.
			close(fd[1]);
			read(fd[0], &resultado_hijo, sizeof(unsigned long long int));
			close(fd[0]);
			wait(NULL);
			resultado = resultado * resultado_hijo;
			fprintf(stdout, "El factorial de %d es: %llu \n", objetivo, resultado);
			return 0;
	}
}