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
system(command);
return 0;
}
