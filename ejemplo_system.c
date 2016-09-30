#include <stdlib.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
	if (argc != 2){
		fprintf(stderr, "El uso del programa es:\n\t%s comando_a_ejecutar\n", argv[0] );
		exit(-1);
	}else{
		int retorno;
		retorno = system(argv[1]);
		if (retorno == -1){
			fprintf(stderr, "El valor de retorno es -1, algo fue mal.\n");
			exit(-1);
		}else{
			fprintf(stdout, "El valor de retorno es:\n%i\n", retorno );
			return 0;
		}
	}
}
