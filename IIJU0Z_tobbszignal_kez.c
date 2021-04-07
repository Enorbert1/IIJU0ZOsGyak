#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>


void handleSignals(int signo){
	int temp = 0;
	if (signo == SIGQUIT)
        printf("Kaptam egy SIGQUIT -et, erteke: %d\n", SIGQUIT);
	else if(signo == SIGINT)
	{
	printf("Elegemvolt. Ertek: %d\n", SIG_DFL);
	}
}

int main(){
	signal(SIGQUIT, handleSignals);
	signal(SIGINT, handleSignals);

	int i = 0;
	printf("Vegtelen loop elkerulese erdekeben 20 sec -ig fog menni a program.");
	for(i = 0; i < 20; i++)
	{
	sleep(1);
	printf("%d\n", i);
	}
    	return 0;
}
