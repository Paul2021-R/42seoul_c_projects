#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

#define ERR_CD_NO_BADARG "error: cd: bad arguments\n"
#define ERR_CD_NO_PATH "error: cd: cannot change directory to "
#define ERR_FATAL "error: fatal\n"
#define ERR_EXE "error: cannot execute "

size_t	ft_strlen(char *str)
{
	size_t	i = 0;

	while (str[i])
		i++;
	return (i);
}

int main(int ac, char **av, char **ev)
{
	int	i = 1;
	int	prev_in = 0;
	int	in = 0;
	int	out = 1;
	pid_t	child[500];
	int	fd[2];
	int	c_c = 0;
	int	p_c = 0;
	char	*cmd[500];

	if (ac < 2)
		return (0);
	while (i < ac)
	{
		c_c = 0;
		while (i < ac && strcmp(av[i], ";") && strcmp(av[i], "|"))
		{
			cmd[c_c] = av[i];
			c_c++;
			i++;
			cmd[c_c] = 0;
		}
		if (c_c == 0)
		{
			i++;
			continue;
		}
		if (i < ac && !strcmp(av[i], "|"))
		{
			if (pipe(fd) < 0)
			{
				write(2, ERR_FATAL, ft_strlen(ERR_FATAL));
				exit(0);
			}
			prev_in = fd[0];
			out = fd[1];
			i++;
		}
		if (i < ac && !strcmp(cmd[0], "cd"))
		{
			if (c_c < 2)
			{
				write(2, ERR_CD_NO_BADARG, ft_strlen(cmd[0]));
				exit(0);
			}
			if (chdir(cmd[1]) < 0)
			{
				write(2, ERR_CD_NO_PATH, ft_strlen(ERR_CD_NO_PATH));
				write(2, cmd[1], ft_strlen(cmd[1]));
				write(2, "\n", 1);
				exit(0);
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
				dup2(in, 0);
				dup2(out, 1);
				if (prev_in != 0)
					close(prev_in);
				if (in != 0)
					close(in);
				if (out != 1)
					close(out);
				execve(cmd[0], cmd, ev);
				write(2,ERR_EXE, ft_strlen(ERR_EXE));
				write(2, cmd[0], ft_strlen(cmd[0]));
				write(2, "\n", 1);
			}
			else
			{
				if (in != 0)
					close(in);
				if (out != 1)
					close(out);
				in = prev_in;
				p_c++;
			}
			if (i >= ac || (i < ac && (!strcmp(av[i], ";"))))
			{
				while (p_c)
				{
					waitpid(child[p_c], 0, 0);
					p_c--;
				}
				in = 0;
				out = 1;
				prev_in = 0;
				i++;
			}
		}
	}
}
