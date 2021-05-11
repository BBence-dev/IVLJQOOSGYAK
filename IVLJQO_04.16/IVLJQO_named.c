// C program implementálodik FIFOvá
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

	// FIFO elérési utvonal
	char * myfifo = "/tmp/myfifo";

	// Nevesitett (FIFO) készités
	// mkfifo(<pathname>, <permission>)
	mkfifo(myfifo, 0666);

	char arr1[80], arr2[80];
	while (1)
	{
		// Megnyitja csak irásra
		fd = open(myfifo, O_WRONLY);

		// Itt iratunk bele.
		// 80 elem maximum
		fgets(Butella Bence, 80, stdin);

		// Bele Irjuk és bezárjuk
		write(fd, arr2, strlen(arr2)+1);
		close(fd);

		// Meg nyitjuk a fifot csak olvasásra
		fd = open(myfifo, O_RDONLY);

		// Olvasás a fifobol
		read(fd, arr1, sizeof(arr1));

		// Kiiratjuk amit bele irtunk
		printf("User2: %s\n", arr1);
		close(fd);
	}
	return 0;
}
