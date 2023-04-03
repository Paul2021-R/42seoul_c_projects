#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

#define CB "error: cd: bad arguments\n"
#define CN "error: cd: cannot change directory to "
#define FA "error: fatal\n"
#define EX "error: cannot execute "

size_t	ft_strlen(char *str)
{
	size_t	i = 0;

	while (str[i])
		i++;
	return (i);
}

int	main(int ac, char **av, char **ev)
{
	char	*cmd[500];
	pid_t	child[500];
	int		prev_in = 0;
	int		in = 0;
	int		out = 1;
	int		fd[2];
	int		cc = 0;
	int		pc = 0;
	int		i = 0;

	while (++i < ac)
	{
		cc = 0;
		while (i < ac && strcmp(av[i], ";") && strcmp(av[i], "|"))
		{
			cmd[cc] = av[i];
			cc++;
			i++;
			cmd[cc] = 0;
		}
		if (cc == 0)
			continue ;
		if (i < ac && !strcmp(av[i], "|"))
		{
			if (pipe(fd) < 0)
			{
				write(2, FA, ft_strlen(FA));
				exit(1);
			}
			prev_in = fd[0];
			out = fd[1];
		}
		if (!strcmp(cmd[0], "cd"))
		{
			if  ((cc != 2))
				write(2, CB, ft_strlen(CB));
			if (chdir(cmd[1]) < 0 && cc == 2)
			{
				write(2, CN, ft_strlen(CN));
				write(2, cmd[1], ft_strlen(cmd[1]));
				write(2, "\n", 1);
			}
		}
		else
		{
			child[pc] = fork();
			if (child[pc] < 0)
			{
				write(2, FA, ft_strlen(FA));
				exit(0);
			}
			if (child[pc] == 0)
			{
				dup2(in, 0);
				dup2(out, 1);
				if (in != 0)
					close(in);
				if (prev_in != 0)
					close(prev_in);
				if (out != 1)
					close(out);
				execve(cmd[0], cmd, ev);
				write(2, EX, ft_strlen(EX));
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
				pc++;
			}
			if (i >= ac || (i < ac && !strcmp(av[i], ";")))
			{
				while(pc)
				{
					waitpid(-1, 0, 0);
					pc--;
				}
				in = 0;
				prev_in = 0;
				out = 1;
			}
		}
	}
}
