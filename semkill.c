#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int main()
{
	sem_t sem;
	sem_init(&sem, 0, 0);
	int value;
	sem_getvalue(&sem, &value);
	printf("%d\n", value);
	sem_destroy(&sem);
	return 0;
}
