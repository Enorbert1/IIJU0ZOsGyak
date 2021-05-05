#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include<unistd.h>
int pipefd[2];
void handler(){
	char szoveg[32];
	strcpy(szoveg,"szovegecske\0");   // feltoltom a buffert a kuldeni kivant stringgel
	  write(pipefd[1], szoveg, strlen(szoveg));
}

int main() {
     	// 2 eleme tomb, mert ket vege lesz a csonek, ezert ket valtozo neki
     pid_t cpid;	// gyerkoc pidje lesz benne
     char buf;		// bufferke
     	// masik buffer a kuldendo szovegnek
     int ret;

     if (pipe(pipefd) == -1) {	// krealunk csovezeteket, es a ket fd a pipefd-ben lesz tarolva
	   perror("pipe");
	   exit(-1);
     }

     

     cpid = fork();
     if (cpid == -1) {
	   perror("fork");
	   exit(-1);
     }

     if (cpid == 0) {    /* gyerek vagyok */
	   printf("%d: gyerek vagyok\n",getpid());
	  close(pipefd[0]);    /* itt meg az olvaso veget csukjuk le, mert irni fogunk */

	   signal(SIGALRM, (void (*)()) handler);
	pause();
	   close(pipefd[1]);    /* lecsukom a csatorna fedelet, a masik oldalon EOF lesz */

   	   exit(0);	// kilep

     } else {	/* szulo vagyok */
	   printf("%d: szulo vagyok\n",getpid());
		close(pipefd[1]);    /* a gyerek csak olvasni fog, ezert az iras fd-t le is csukom */
   	   while (read(pipefd[0], &buf, 1) > 0) {	// olvasunk a cso kimeneterol, amig van mit (1 byteonkent)
		 printf("%c",buf);
	   }
	   printf("\n%d:lezartak a cso masik oldalat\n",getpid());

	   close(pipefd[0]);	/* na itt becsukom mar az olvaso veget is */

	   wait(NULL);    /* varjunk gyerekre */

	   exit(0);
     }
	
}
