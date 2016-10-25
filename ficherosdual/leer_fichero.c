#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	int fd; //File descriptor. Descriptor de fichero.
	char buffer[15];

	fd = open("./fich1.txt", O_RDONLY);

	if (fd == -1){
		fprintf(stderr, "Error!!\n");
	}
	read(fd, buffer, 15*sizeof(char));
	fprintf(stdout, "%s\n", buffer );
	close(fd);

	return 0;
}