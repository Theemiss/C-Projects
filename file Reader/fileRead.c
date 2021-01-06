#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - Program Read File And Display it
 * Descreption: Read file parent send data to child and display it
 * Return 0 Succes -1 On Failure
 * Command: gcc -Wall -Werror -Wextra -pedantic *.c -o Reader
 */
int main (int argc, char **argv)
{
    int fd[2];
    pid_t childpid;
    char string[50];
    char readbuffer[100];
    FILE *fp;

// main program also Parent process //

    if (argc < 2)
    {
        printf("Usage : %s Filename",argv[0]);
        return (-1);
    }
 
    fp = fopen(argv[1], "r");
    pipe(fd);
    char var[100];

    if ((childpid = fork()) == -1) {
        perror("fork");
        exit(1);
    }

    if (childpid != 0) {
        /* Child process closes up input side of pipe */
        close(fd[0]);
        

        // scanning from file
        while (fscanf(fp, "%s\n", string) != EOF) {
            strcat(var, string);
        }

        /* Send "string" through the output side of pipe */
        write(fd[1], var, (strlen(var) + 1));
        close(fd[1]);
        // exit(0);

#if 1
        waitpid(childpid,NULL,0);
#endif
    }

    else {
        /* Parent process closes up output side of pipe */

        close(fd[1]);


        read(fd[0], readbuffer, sizeof(readbuffer));
        printf("%s\n", readbuffer);

        close(fd[0]);
    }

    return (0);
}

