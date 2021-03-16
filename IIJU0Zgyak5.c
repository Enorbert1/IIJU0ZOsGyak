#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
int pid, status;
if(pid = fork() < 0) perror("forkhiba");
else if(pid == 0)
	exit(7);
if(wait(&status)!=pid) perror("wait hiba");
if(WIFEXITED(status))
	printf("Normalis veg, visszakapott ertek: %d\n", WEXITSTATUS(status));

if(pid = fork() < 0) perror("forkhiba");
else if(pid == 0)
        abort();
if(wait(&status)!=pid) perror("wait hiba");
if(WIFSIGNALED(status))
        printf("Abnormalis veg, visszakapott ertek: %d\n", WTERMSIG(status));
return 0;
}
