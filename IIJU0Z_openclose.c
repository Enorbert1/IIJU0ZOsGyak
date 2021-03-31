#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main()
{
     int fdescriptor = open("IIJU0Z.txt", O_RDWR);

     if (fdescriptor == -1)
        {
            perror("Hiba a megnyitásnál.");
            exit(fdescriptor);
        }
        printf("Filedescriptor erteke: %d\n", fdescriptor);
        char buffer[50];
        int readinfo = read(fdescriptor, buffer, 33);
        if(readinfo == -1)
        {
            perror("Az olvasas sikertelen: ");
            exit(readinfo);
        }
        printf("read() erteke: %d\nBeolvasott ertek: %s\n", readinfo, buffer);

        int seekinfo = lseek(fdescriptor, 0, SEEK_SET);
        if(seekinfo == -1)
        {
            perror("Hiba a pozicionalasnal.\n");
            exit(seekinfo);
        }
        printf("Kurzor pozicioja: %d\n", seekinfo);
        strcpy(buffer, "Tesztszoveg");
        int bufferlength = strlen(buffer);
        int writeinfo = write(fdescriptor, buffer, bufferlength);
        if(writeinfo == -1)
        {
            perror("Sikertelen iras");
            exit(writeinfo);
        }
        printf("Write-tal beirt byte-ok szama: %d\n", writeinfo);

     close(fdescriptor);
	return 0;
}


