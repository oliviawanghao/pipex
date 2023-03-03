/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/16 13:59:41 by hwang         #+#    #+#                 */
/*   Updated: 2022/04/19 18:30:50 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_argv(char **split_cmd)
{
	char	*str;

	str = ft_strdup(ft_strrchr(split_cmd[0], '/') + 1);
	split_cmd[0] = str;
	free(split_cmd[0]);
	return (split_cmd);
}

void	no_path_found(char *path)
{
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": No such file or directory", 2);
	ft_putstr_fd("\n", 2);
	exit(127);
}

char	**get_paths(char *cmd, char **envp)
{
	int		i;
	int		size;
	char	**paths;

	size = 0;
	while (envp[size])
		size++;
	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (i == size)
		no_path_found(cmd);
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*path;
	char	*part_path;

	paths = get_paths(cmd, envp);
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	exec_no_path(char **split_cmd, char **envp)
{
	char	*path;
	int		i;

	i = -1;
	path = find_path(split_cmd[0], envp);
	if (!path)
	{
		ft_putstr_fd("Error: command not found: ", 2);
		ft_putstr_fd(split_cmd[0], 2);
		ft_putstr_fd("\n", 2);
		while (split_cmd[++i])
			free(split_cmd[i]);
		free(split_cmd);
		exit(127);
	}
	if (execve(path, split_cmd, envp) < 0)
		error();
}
