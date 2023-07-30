/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 01:17:49 by ajakob            #+#    #+#             */
/*   Updated: 2023/07/30 17:06:52 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct arg_s
{
	char	*infile;
	char	*cmd1;
	char	*cmd2;
	char	*outfile;
}	t_arg;

char	*find_path(char *cmd, char *env[]);
char	**alloc_arr(char *cmd);
void	ft_free(char **ptr);
void	ft_error(char *str);
int		dup2_close(int fd, int std, int pipefd[]);

#endif