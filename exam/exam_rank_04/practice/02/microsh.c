# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <string.h>

# define ERR_EXE "error: cannot execute "
# define ERR_CD_NODIR "error: cd: cannot change directory to "
# define ERR_CD_BADARG "error: cd: bad arguments\n"
# define ERR_EXEPT "error: fatal\n"

size_t	ft_strlen(char *str)
{
	size_t	i = 0;

	if (str == NULL)
		return (0);
	while(str[i])
		i++;
	return (i);
}

int main(int argc, char **argv, char **envp)
{
	int		pipes[2];
	int		process_count = 0;
	int		command_count = 0;
	int		i = 1;
	int		prev_infd = 0;
	int		infd = 0;
	int		outfd = 1;
	pid_t	pid[500];

	if (argc < 2)
		return (0);
	while (i < argc)
	{
		command_count = 0;
		char	*cmd[500];
		while (i < argc && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
		{
			cmd[command_count] = argv[i];
			command_count++;
			i++;
			cmd[command_count] = 0;
		}
		if (command_count == 0)
		{
			i++;
			continue ; 
		}
		if (i < argc && !strcmp(argv[i], "|"))
		{	if (pipe(pipes) < 0)
			{
				write(2, ERR_EXEPT, ft_strlen(ERR_EXEPT));
				exit(0);
			}
			prev_infd = pipes[0];
			outfd = pipes[1];
			i++;
		}
		if (!strcmp(cmd[0], "cd"))
		{
			if (command_count != 2)
				write(2, ERR_CD_BADARG, ft_strlen(ERR_CD_BADARG));
			else if (chdir(cmd[1]) < 0)
			{
				write(2, ERR_CD_NODIR, ft_strlen(ERR_CD_NODIR));
				write(2, cmd[1], ft_strlen(cmd[1]));
				write(2, "\n", 1);
			}
		}
		else
		{
			pid[process_count] = fork();
			if (pid[process_count] < 0)
			{
				write(2, ERR_EXEPT, ft_strlen(ERR_EXEPT));
				exit(0);
			}
			if (pid[process_count] == 0)
			{
				dup2(infd, 0);
				dup2(outfd, 1);
				if (prev_infd != 0)
					close(prev_infd);
				if (infd != 0)
					close(infd);
				if (outfd != 1)
					close(outfd);
				execve(cmd[0], cmd, envp);
				write(2, ERR_EXE, ft_strlen(ERR_EXE));
				write(2, cmd[0], ft_strlen(cmd[0]));
				write(2, "\n", 1);
				exit(0);
			}
			else
			{
				if (outfd != 1)
					close(outfd);
				if (infd != 0)
					close(infd);
				infd = prev_infd;
				process_count++;
			}
		}
		if (i >= argc || (i < argc && !strcmp(argv[i], ";")))
		{
			while(process_count)
			{
				waitpid(pid[process_count], 0, 0);
				process_count--;
			}
			infd = 0;
			prev_infd = 0;
			outfd = 1;
			i++;
		}
	}
}
