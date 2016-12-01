#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void* hola(void*);
void* mundo(void*);

int main(int argc, char const *argv[])
{
	int parametro1 = 25;
	pthread_t hilo_hola;
	pthread_t hilo_mundo;

	pthread_create(&hilo_hola, NULL, hola, &parametro1);
	pthread_create(&hilo_mundo, NULL, mundo, NULL);

	pthread_join(hilo_hola, NULL);
	pthread_join(hilo_mundo, NULL);
	return 0;
}

void* hola(void* parametros){
	char* msg = "Hola";
	int i;
	fprintf(stderr, "En la posicion %p se encuentra el entero: %d\n",
					 parametros, *( (int*) parametros ) );

	for (i=0; i<strlen(msg); i++){
		printf("%c\n",msg[i]);
		fflush(stdout);
		//usleep(1000000);
	}

	return NULL;
}
void* mundo(void* parametros){
	char* msg = "Mundo";
	int i;
	for (i=0; i<strlen(msg); i++){
		printf("%c\n",msg[i]);
		fflush(stdout);
		//usleep(1000000);
	}
	return NULL;
}