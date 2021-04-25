#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10

struct msg_buffer{
	long msg_type;
	char msg_text[100];
}message;
int main(){
key_t key;
int msgid;

key = 2234;
msgid = msgget(key, 0666 | IPC_CREAT);
message.msg_type = 1;
strcpy(message.msg_text,"hello");

msgsnd(msgid, &message, sizeof(message), 0);


return 0;
}
