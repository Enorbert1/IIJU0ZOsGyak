#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>


// Declare the message structure.
typedef struct msgbuf {
	long msg_type;
	char msg_text[100];
} message_buf;

int main()
{
	int msgid;
	key_t key;
	message_buf rbuf;
	rbuf.msg_type = 1;
	key = 2234;

	msgid = msgget(key, 0666);

	msgrcv(msgid, &rbuf, 100, rbuf.msg_type, 0);
	printf("%s\n", rbuf.msg_text);
	exit(0);
return 0;
}
