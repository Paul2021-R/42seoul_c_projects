#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

#define ERR_CD_BADARG "error: cd: bad arguments\n"
#define ERR_CD_NOPATH "error: cd: cannot change directory to "
#define ERR_FATAL "error: fatal\n"
#define ERR_EXE "error: cannot execute "

size_t	ft_strlen(char *str)
{
	size_t	i = 0;

	while (str[i])
		i++;
	return (i);
}

int	main(int ac, char **ag, char **ev)
{
	int		i = 1;
	int		prev_in = 0;
	int		in = 0;
	int		out = 1;
	int		fd[2];
	int		p_c = 0;
	int		c_c = 0;
	char	*cmd[500];
	pid_t	child[500];

	if (ac < 2)
		return (0);
	while (i < ac)
	{
		c_c = 0;
		while (i < ac && strcmp(ag[i], ";") && strcmp(ag[i], "|"))
		{
			cmd[c_c] = ag[i];
			i++;
			c_c++;
			cmd[c_c] = 0;
		}
		if (c_c == 0)
		{
			i++;
			continue ;
		}
		if (i < ac && !strcmp(ag[i], "|"))
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
		if (!strcmp(cmd[0], "cd"))
		{
			if (c_c != 2)
			{
				write(2, ERR_CD_BADARG, ft_strlen(ERR_CD_BADARG));
				exit(0);
			}
			if (chdir(cmd[1]) < 0)
			{
				write(2, ERR_CD_NOPATH, ft_strlen(ERR_CD_NOPATH));
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
			if (child[p_c] == 0)
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
				write(2, ERR_EXE, ft_strlen(ERR_EXE));
				write(2, cmd[0], ft_strlen(cmd[0]));
				write(2, "\n", 1);
				exit(0);
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
			if (i >= ac || !strcmp(ag[i], ";"))
			{
				while (p_c)
				{
					waitpid(child[p_c], 0, 0);
					p_c--;
				}
				i++;
				prev_in = 0;
				in = 0;
				out = 1;
			}
		}
	}
}