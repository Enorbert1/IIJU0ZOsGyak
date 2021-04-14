#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define MSGSIZE 16
char* msg1 = "IIJU0Z";

int main()
{
	char inputbuffer[MSGSIZE];
	int p[2];

	if (pipe(p) < 0)
		exit(1)

	write(p[1], msg1, MSGSIZE);

	read(p[0], inputbuffer, MSGSIZE);
	printf("% s\n", inputbuffer);
return 0;
}

