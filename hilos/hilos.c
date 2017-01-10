#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* incrementar(void*);
void* decrementar(void*);

int a = 5;

int main(int argc, char const *argv[])
{

	pthread_t h1;
	pthread_t h2;

	pthread_create(&h1, NULL, incrementar, NULL );
	pthread_create(&h2, NULL, decrementar, NULL );

	printf("%d\n", a );

	pthread_join(h1,NULL);

	printf("%d\n", a );

	pthread_join(h2,NULL);

	printf("%d\n", a );

	printf("FINAL\n");

	return 0;
}

void* incrementar(void* parametros){
	a++;
	printf("hilo1\n");
}

void* decrementar(void* parametros){
	a--;
	printf("hilo2\n");
}