#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define MSGSIZE 16
char* msg1 = "Ersek_Norbert";

int main()
{
	char inputbuffer[MSGSIZE];
	int p[2];
	pipe(p);
	int x = fork();
	if (x < 0)
		exit(1);
	if(x == 0){
	write(p[1], msg1, MSGSIZE);

	read(p[0], inputbuffer, MSGSIZE);
	printf("%s\n", inputbuffer);
	}
return 0;
}

