#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/sem.h>

int main()
{
	int semid;
	struct sembuf sb[1];
	int nsops = 2;
	int result;
	sb[0].sem_num = 0;
	sb[0].sem_op = -1;
	sb[0].sem_flg = 0;
	result = semop(semid, sb, nsops);
	printf("%d\n", result);
	return 0;
}
