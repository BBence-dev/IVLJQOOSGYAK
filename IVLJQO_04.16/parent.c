#include <stdio.h>
#include <fcntl.h>

main (int argc, char *argv[],char *env[])
{
	int status, pid, ppid, gpid;
	
	ppid = getpid();        /* Szulo pid-jet elkaptuk */

	if ((pid = fork()) == 0)   
	{ 	/* innen a gyermek processz */
		printf("\n A gyermek pid = %d \n", getpid());
		status = execl(strcat(env[0]+5,"/cs/child"),0);
		if (status == -1)
		{	perror("parent execl failed");
			exit ();
		}
	}

	/* innen a szulo process */
	
	printf("\n %d.sz. szulo var a %d.sz. gyermekre.\n ", ppid,pid);
	if (pid != wait(&status)) perror(" Szulo - varakozas hiba ");
}