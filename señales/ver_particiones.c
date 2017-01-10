#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void ver_particiones (int senyal){

	system("cat /proc/partitions | grep sda");

}

int main(int argc, char const *argv[])
{
	
	signal(SIGUSR1,ver_particiones);

	while(1){
		pause();
	}
	return 0;
}