// C program implement�lodik FIFOv�
//Ez az Oldal ir majd olvas
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int fd;

	// FIFO el�r�si utvonal
	char * myfifo = "/tmp/myfifo";

	// Nevesitett (FIFO) k�szit�s
	// mkfifo(<pathname>, <permission>)
	mkfifo(myfifo, 0666);

	char arr1[80], arr2[80];
	while (1)
	{
		// Megnyitja csak ir�sra
		fd = open(myfifo, O_WRONLY);

		// Itt iratunk bele.
		// 80 elem maximum
		fgets(Butella Bence, 80, stdin);

		// Bele Irjuk �s bez�rjuk
		write(fd, arr2, strlen(arr2)+1);
		close(fd);

		// Meg nyitjuk a fifot csak olvas�sra
		fd = open(myfifo, O_RDONLY);

		// Olvas�s a fifobol
		read(fd, arr1, sizeof(arr1));

		// Kiiratjuk amit bele irtunk
		printf("User2: %s\n", arr1);
		close(fd);
	}
	return 0;
}
