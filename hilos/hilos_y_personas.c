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

int main(int argc, char const *argv[])
{
	
	persona p1;
	strcpy(p1.nombre,"Juan");
	strcpy(p1.apellido,"Pérez");
	p1.edad = 25;

	pthread_t h1;

	pthread_create(&h1, NULL, imprimir, &p1 );

	pthread_join(h1,NULL);
	

	return 0;
}

void* imprimir(void* parametro){
	
	persona* puntero_p1=(persona*) parametro;

	printf("Persona:\n\tNombre: %s\n\tApellido: %s\n\tEdad: %d\n\n",
	puntero_p1->nombre,puntero_p1->apellido,puntero_p1->edad);
}