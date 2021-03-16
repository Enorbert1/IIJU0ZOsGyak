#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
char command[50];
pid_t pid = 12435;
scanf("%s", command);
int status=system(command);
waitpid(pid, &status, 0);
if(WIFEXITED(status))
{
	if(WEXITSTATUS(status)==0)
	{
	printf("Jo ");
	printf("%d\n", WEXITSTATUS(status));
	}
	else if(WEXITSTATUS(status)== 127)
	{
	printf("Nem jo ");
	printf("%d\n", WEXITSTATUS(status));
	}
}
return 0;
}
