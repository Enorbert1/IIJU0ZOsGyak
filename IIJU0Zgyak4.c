#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
if(fork() == 0)
{
execlp("ls", "-lh", "/home/pi/temp");
}
else
{
wait(NULL);
printf("Gyerek halott.\n");
}
return 0;
}
