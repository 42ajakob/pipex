/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:13:15 by ajakob            #+#    #+#             */
/*   Updated: 2023/07/30 17:06:40 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
}

char	*pathing(char **path_arr, char *cmd)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	while (path_arr[i])
	{
		tmp = ft_strjoin(path_arr[i], "/");
		tmp2 = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(tmp2, F_OK) == 0)
			return (tmp2);
		else
		{
			free(tmp2);
			tmp2 = NULL;
		}
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **env)
{
	int		i;
	char	*path;
	char	**path_arr;
	char	*tmp;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_strdup(env[i] + 5);
			path_arr = ft_split(path, ':');
			free(path);
			tmp = pathing(path_arr, cmd);
			ft_free(path_arr);
			if (tmp)
				return (tmp);
			else
				return (free(tmp), tmp = NULL, NULL);
		}
		i++;
	}
	return (ft_error("Env variable PATH= not found"), NULL);
}

char	**alloc_arr(char *cmd)
{
	char	**arr;

	arr = ft_split(cmd, ' ');
	if (!arr)
		return (NULL);
	return (arr);
}

int	dup2_close(int fd, int std, int pipefd[])
{
	if ((dup2(fd, std)) == -1)
		ft_error("dup2");
	close(fd);
	close(pipefd[0]);
	close(pipefd[1]);
	return (0);
}
