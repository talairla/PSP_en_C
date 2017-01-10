#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef struct 
{
	char nombre[10];
	int edad;
}persona;

void* cumplir(void*);

int main(int argc, char const *argv[])
{
	pthread_t h1;
	persona p1;
	strcpy(p1.nombre,"Juan");
	p1.edad = 50;
	printf("Edad: %d\n",p1.edad);
	persona *p2 = &p1;

	p2->edad=40;

	printf("Edad: %d\n",p1.edad);

	pthread_create(&h1, NULL, cumplir, p2 );
		
	pthread_join(h1,NULL);
	printf("Edad: %d\n",p1.edad);
	return 0;

}

void* cumplir(void* parametro){

	persona* persona1 = (persona*) parametro;
	persona1->edad= (persona1->edad) + 1;
	fprintf(stdout, "%s ha cumplido años",persona1->nombre);
}
