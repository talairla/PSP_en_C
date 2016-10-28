#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void tratar_alarm(int);

int minutos = 0;
int segundos = 0;

int main(int argc, char const *argv[])
{
	signal(SIGALRM, tratar_alarm);
	while(1){
		alarm(2);
		pause();
	}
	return 0;
}

void tratar_alarm(int senyal){
	system("clear");
	fprintf(stdout, "%.2d:%.2d\n", minutos, segundos);
	segundos=(segundos+2)%60;
	if (segundos == 0){
		minutos=(minutos+1)%60;
	}
}