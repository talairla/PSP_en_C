#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void tratar_alarm(int);
void parar_ctrl_c(int);
void reiniciar_ctrl_z(int);

int minutos = 0;
int segundos = 0;
int incremento = 1;

int main(int argc, char const *argv[])
{
	signal(SIGALRM, tratar_alarm);
	signal(SIGINT, parar_ctrl_c);
	signal(SIGTSTP, reiniciar_ctrl_z);
	while(1){
		alarm(1);
		pause();
	}
	return 0;
}

void tratar_alarm(int senyal){
	system("clear");
	fprintf(stdout, "%.2d:%.2d\n", minutos, segundos);
	segundos=(segundos+incremento)%60;
	if (segundos == 0){
		minutos=(minutos+incremento)%60;
	}
}

void parar_ctrl_c(int senyal){
	incremento = (incremento+1)%2;
}
void reiniciar_ctrl_z(int senyal){
	segundos = 0;
	minutos = 0;
}