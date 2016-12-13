#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void* hola(void*);
void* mundo(void*);
void* imprimir(void*);

typedef struct{
	char texto[100];
}cadena_100;

int main(int argc, char const *argv[])
{
	int parametro1 = 25;
	pthread_t hilo_hola;
	pthread_t hilo_mundo;

	cadena_100 msg1;
	cadena_100 msg2;
	strcpy(msg1.texto,"Hola");
	strcpy(msg2.texto,"Mundo");
	cadena_100* parametro = &msg1;

	pthread_create(hilo_hola, NULL ,  , parametro);

	pthread_join(hilo_hola, NULL);
	pthread_join(hilo_mundo, NULL);
	return 0;
}
////SIN ACABAR///
void* imprimir(void* parametros){
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