#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main()
{
if(fork()==0)
{
	execl("./child","child",(char*) NULL);
}
else
	wait(NULL);
return 0;
}

