/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:13:15 by ajakob            #+#    #+#             */
/*   Updated: 2023/07/27 14:20:35 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**pathing(char *path, char **path_arr, char *cmd)
{
	char	*tmp;
	int		i;

	i = 0;
	while (path_arr[i])
	{
		tmp = ft_strjoin(path_arr[i], "/");
		free(path_arr[i]);
		path_arr[i] = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path_arr[i], F_OK) == 0)
		{
			free(path);
			return (&path_arr[i]);
		}
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char *env[])
{
	int		i;
	char	*path;
	char	**path_arr;
	char	**tmp;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_strdup(env[i] + 5);
			path_arr = ft_split(path, ':');
			tmp = pathing(path, path_arr, cmd);
			if (tmp)
				return (*tmp);
			free(path);
			free(path_arr);
			free(tmp);
			return (NULL);
		}
		i++;
	}
	return (NULL);
}

char	**alloc_arr(char *cmd)
{
	char	**arr;

	arr = ft_split(cmd, ' ');
	if (!arr)
		return (NULL);
	return (arr);
}
