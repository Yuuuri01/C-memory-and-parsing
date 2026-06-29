# include <sys/wait.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


int pipe_chain(char **cmds[])
{
    int pipefd[2];// pipfd[1] = read | pipfd[2] = write
    int i = 0;
    pid_t pid2;
    int prev_fd = STDIN_FILENO; // start standard input
    

    while(cmds[i])
    {
        if(cmds[i + 1] != NULL)
        {
            if(pipe(pipefd) == -1)
                return 1;
        }
        pid2 = fork();
        if(pid2 == -1)
            return 1;
        else if(pid2 == 0)//child
        {
            if(prev_fd != STDIN_FILENO)
            {
                dup2(prev_fd, STDIN_FILENO);
                close(prev_fd);
            }

            if(cmds[i + 1] != NULL)
            {
                dup2(pipefd[1], STDOUT_FILENO);
                close(pipefd[0]);
                close(pipefd[1]);
            }
            execvp(cmds[i][0], cmds[i]);
            exit(1);
        }
        else//parent
        {
            if(prev_fd != STDIN_FILENO)
                close(prev_fd);
            if(cmds[i + 1] != NULL)
            {
                close(pipefd[1]);
                prev_fd = pipefd[0];
            }
        }
        i++;
    }

    while(i-- > 0)
        wait(NULL);
    return 0;
}
int main(void)
{
    // كنصاوبو الـ cmds بحال اللي كيسيفط الـ hatchy
    char *cmd1[] = {"ls", NULL};
    char *cmd2[] = {"grep", "c", NULL}; // كيقلب على ملفات فيها حرف 'c'
    char **cmds[] = {cmd1, cmd2, NULL};

    printf("Starting pipe_chain...\n");
    
    if (pipe_chain(cmds) == 0)
        printf("Success!\n");
    else
        printf("Failed!\n");

    return (0);
}