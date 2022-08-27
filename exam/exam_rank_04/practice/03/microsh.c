#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>

#define ERR_CD_BADARG "error: cd: bad argumnets\n"
#define ERR_CD_NOPATH "error: cd: cannot change directory to "
#define ERR_FATAL "error: fatal\n"
#define ERR_EXECVE_NO "error: cannot execute "

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(int ac, char **av, char **ev)
{
	int i = 1;
	int	pipes[2];
	int infd = 0;
	int outfd = 1;
	int prev_infd = 0;
	int p_c = 0;
	int c_c = 0;
	pid_t child[500];
	char *cmd[500];

	if (ac < 2)
		return (0);
	while (i < ac)
	{
		c_c = 0;
		while (i < ac && strcmp(av[i], ";") && strcmp(av[i], "|"))
		{
			cmd[c_c] = av[i];
			i++;
			c_c++;
			cmd[c_c] = 0;
		}
		if (c_c == 0)
		{
			i++;
			continue ;
		}
		if (i < ac && !strcmp(av[i], "|"))
		{
			if (pipe(pipes) < 0)
			{
				write(2, ERR_FATAL, ft_strlen(ERR_FATAL));
				exit(0);
			}
			prev_infd = pipes[0];
			outfd = pipes[1];
			i++;
		}
		if (!strcmp(cmd[0], "cd"))
		{
			if (c_c != 2)
				write(2, ERR_CD_BADARG, ft_strlen(ERR_CD_BADARG));
			if (chdir(cmd[1]) < 0)
			{
				write(2, ERR_CD_NOPATH, ft_strlen(ERR_CD_NOPATH));
				write(2, cmd[1], ft_strlen(cmd[1]));
				write(2, "\n", 1);
			}
		}
		else
		{
			child[p_c] = fork();
			if (child[p_c] < 0)
			{
				write(2, ERR_FATAL, ft_strlen(ERR_FATAL));
				exit(0);
			}
			else if (child[p_c] == 0)
			{
				dup2(infd, 0);
				dup2(outfd, 1);
				if (prev_infd != 0)
					close(prev_infd);
				if (infd != 0)
					close(infd);
				if (outfd != 1)
					close(outfd);
				execve(cmd[0], cmd, ev);
				write(2, ERR_EXECVE_NO, ft_strlen(ERR_EXECVE_NO));
				write(2, cmd[0], ft_strlen(cmd[0]));
				write(2, "\n", 1);
				exit(0);
			}
			else
			{
				if (infd != 0)
					close(infd);
				if (outfd != 0)
					close(outfd);
				infd = prev_infd;
				p_c++;
			}
			if (i >= ac || (i < ac && !strcmp(av[i], ";")))
			{
				while (p_c)
				{
					waitpid(child[p_c], 0, 0);
					p_c--;
				}
				infd = 0;
				outfd = 1;
				prev_infd = 0;
				i++;
			}
		}
	}
}
