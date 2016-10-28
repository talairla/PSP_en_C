#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void tratar_controlC(int);
void tratar_controlC2(int);
void tratar_controlC3(int);

int main(int argc, char const *argv[])
{	
	if( signal(SIGINT, tratar_controlC) == SIG_ERR ){
		fprintf(stderr, "Error. No se pudo asociar la señal\n");
	}
	while(1){
		pause();
	}
	return 0;
}

void tratar_controlC(int senyal){
	printf("Has pulsado Control-C, ¿seguro que quieres salir?\n");
	printf("Vuelve a pulsar Control-C para salir.\n");
	signal(SIGINT, tratar_controlC2);
}

void tratar_controlC2(int senyal){
	printf("Pero... ¿seguro, seguro?\n");
	signal(SIGINT, tratar_controlC3);
}

void tratar_controlC3(int senyal){
	printf("Saliendo, la siguiente vez que pulses.\n");
	//devolver al comportamiento por defecto con SIG_DFL.
	signal(SIGINT, SIG_DFL);
}
