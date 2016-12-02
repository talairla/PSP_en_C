#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

typedef struct{
	char nombre[100];
	char apellido[100];
	int edad;
}persona;

void* imprimir(void*);
void* rellenar(void*);

int main(int argc, char const *argv[])
{
	persona p1;
	persona p2;

	pthread_t h1;
	pthread_t h2;
	pthread_t h3;
	pthread_t h4;

	pthread_create(&h1, NULL, rellenar, &p1 );
	pthread_create(&h2, NULL, rellenar, &p2 );
	
	pthread_join(h1,NULL);
	pthread_join(h2,NULL);

	pthread_create(&h3, NULL, imprimir, &p1 );
	pthread_create(&h4, NULL, imprimir, &p2 );	
		
	pthread_join(h3,NULL);
	pthread_join(h4,NULL);

	return 0;
}

void* imprimir(void* parametro){
	
	persona* p=(persona*) parametro;
	printf("Persona:\n\tNombre: %s\n\tApellido: %s\n\tEdad: %d\n\n",
	p->nombre,p->apellido,p->edad);
}

void* rellenar(void* parametro){
	//usleep(100);
	persona* p= (persona*) parametro;
	strcpy(p->nombre,"Juan");
	strcpy(p->apellido,"Pérez");
	p->edad = 25;
}