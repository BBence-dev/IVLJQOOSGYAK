#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
    pid_t pid;
    int pipomfd[2];
    int ret;
    char buf [20];
    
    ret = pipe(pipomfd);
    
    if(ret == -1)
    {
        perror("pipe");
        exit(1);
    }
    
    pid=fork();
    
    if(pid == 0)
    {
        /* Gyerek processz*/
        close(pipomfd[0]);
        write(pipomfd[1],"IVLJQO", 7);
    }
    else
    /* Szülö processz*/
    close(pipomfd[1]);
    read(pipomfd[0],buf,15);
    printf("buf:%s\n",buf);
}