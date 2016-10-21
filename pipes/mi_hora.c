#include "mi_hora.h"
#include <stdio.h>
#include <time.h>

void imprimir_hora(){
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime ( &rawtime );
	printf("(%2d:%2d:%2d)",timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
}

