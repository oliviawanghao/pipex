/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/16 13:59:06 by hwang         #+#    #+#                 */
/*   Updated: 2022/04/20 16:01:12 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	execute_cmd(char *cmd, char **envp)
{
	char	**split_cmd;
	char	*path;

	split_cmd = ft_split(cmd, ' ');
	if (ft_strchr(split_cmd[0], '/'))
	{
		path = ft_strdup(split_cmd[0]);
		if (execve(path, get_argv(split_cmd), envp) < 0)
			no_path_found(path);
	}
	else
		exec_no_path(split_cmd, envp);
}

void	child_process(int *fd, char **argv, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		error();
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execute_cmd(argv[2], envp);
}

void	parent_process(int *fd, char **argv, char **envp)
{
	int	outfile;

	outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		error();
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(outfile, STDOUT_FILENO);
	execute_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (argc == 5)
	{
		if (pipe(fd) < 0)
			error();
		pid = fork();
		if (pid < 0)
			perror("Fork");
		if (pid == 0)
			child_process(fd, argv, envp);
		else
		{
			parent_process(fd, argv, envp);
			waitpid(pid, NULL, 0);
		}
	}
	else
	{
		ft_putstr_fd("Wrong argument\n", 1);
		exit(1);
	}
	return (0);
}
