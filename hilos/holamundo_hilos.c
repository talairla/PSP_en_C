#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void* hola(void*);
void* mundo(void*);

int main(int argc, char const *argv[])
{
	pthread_t hilo_hola;
	pthread_t hilo_mundo;

	pthread_create(&hilo_hola, NULL, hola, NULL);
	pthread_create(&hilo_mundo, NULL, mundo, NULL);


	pthread_join(hilo_hola, NULL);
	pthread_join(hilo_mundo, NULL);
	return 0;
}

void* hola(void* parametros){
	char* msg = "Hola";
	int i;
	for (i=0; i<strlen(msg); i++){
		printf("%c\n",msg[i]);
		fflush(stdout);
		usleep(1000000);
	}

	return NULL;
}
void* mundo(void* parametros){
	char* msg = "Mundo";
	int i;
	for (i=0; i<strlen(msg); i++){
		printf("%c\n",msg[i]);
		fflush(stdout);
		usleep(1000000);
	}
	return NULL;
}