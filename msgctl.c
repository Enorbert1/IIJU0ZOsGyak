#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(){
int msgid;
msgid= msgget(2234, 0666);
msgctl(msgid, IPC_RMID, NULL);
printf("Uzenet torolve\n");


return 0;
}
