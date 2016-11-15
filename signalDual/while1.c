#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int segundos=0;
void controlar_senyal(int cod_senyal){
	switch(cod_senyal){
		case SIGINT:
			fprintf(stdout, "Hola\n");	
		break;
		case SIGALRM:
			system("clear");
			segundos++;
			printf("%.2d:%.2d\n",segundos/60,segundos%60);
			if(segundos == 5){
				signal(SIGALRM,SIG_DFL);
			}
		break;
			
	}
	
}

int main(int argc, char const *argv[])
{
	signal( SIGINT, controlar_senyal );
	signal( SIGALRM, controlar_senyal);
	while(1){
		alarm(1);	
		pause();
	}
	return 0;
}