#include "microshell.h"
#include <stdio.h>

extern char **environ;

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	int		i = 1;
	int		fd[2];
	int		command_count = 0;
	int		process_count = 0;
	int		p_in = 0;
	int		in = 0;
	int		out = 1;
	pid_t	pid[500];

	if (argc < 2)
		return (0);
	while (i < argc)
	{
		char	*cmd[500];
		command_count = 0;
		while (i < argc && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
		{
			cmd[command_count] = argv[i];
			i++;
			command_count++;
			cmd[command_count] = 0;
		}
		if (command_count == 0)
		{
			i++;
			continue;
		}
		if (i < argc && !strcmp(argv[i], "|"))
		{
			if (pipe(fd) < 0)
			{
				write(2, ERR_EXEPT, ft_strlen(ERR_EXEPT));
				exit(0);
			}
			p_in = fd[0];
			out = fd[1];
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
				dup2(in, 0);
				dup2(out, 1);
				if (p_in != 0)
					close(p_in);
				if (in != 0)
					close(in);
				if (out != 1)
					close(out);
				execve(cmd[0], cmd, environ);
				write(2, ERR_EXE, ft_strlen(ERR_EXE));
				write(2, cmd[0], ft_strlen(cmd[0]));
				write(2, "\n", 1);
				exit(0);
			}
			else
			{
				if (out != 1)
					close(out);
				if (in != 0)
					close(in);
				in = p_in;
				process_count++;
			}
			if (i >= argc || (i < argc && !strcmp(argv[i], ";")))
			{
				while (process_count)
				{
					waitpid(pid[process_count], 0, 0);
					process_count--;
				}
				in = 0;
				p_in = 0;
				out = 1;
				i++;
			}
		}
	}
	return (0);
}
