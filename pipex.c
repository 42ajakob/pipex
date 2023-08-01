/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:02:20 by ajakob            #+#    #+#             */
/*   Updated: 2023/08/01 14:40:53 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	perror("Error");
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	child(t_arg arg, int pipefd[], char *envp[])
{
	char	**arr;
	char	*cmd;
	int		fd;

	fd = open(arg.infile, O_RDONLY);
	if (fd == -1)
		ft_error("can't open fd1");
	if ((dup2(pipefd[1], STDOUT_FILENO)) == -1)
		ft_error("pipe1dup");
	dup2_close(fd, STDIN_FILENO, pipefd);
	arr = alloc_arr(arg.cmd1);
	if (arr == NULL)
		ft_error("arr1");
	cmd = find_path(arr[0], envp);
	if (cmd == NULL)
	{
		ft_free(arr);
		ft_error("cmd1");
	}
	if ((execve(cmd, arr, envp)) == -1)
	{
		ft_free(arr);
		free(cmd);
		ft_error("Wrong flags");
	}
}

void	second_child(t_arg arg, int pipefd[], char *envp[])
{
	char	**arr;
	char	*cmd;
	int		fd;

	fd = open(arg.outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		ft_error("fd2");
	if ((dup2(pipefd[0], STDIN_FILENO)) == -1)
		ft_error("pipe2dup");
	dup2_close(fd, STDOUT_FILENO, pipefd);
	arr = alloc_arr(arg.cmd2);
	if (arr == NULL)
		ft_error("arr2");
	cmd = find_path(arr[0], envp);
	if (cmd == NULL)
	{
		ft_free(arr);
		ft_error("cmd1");
	}
	if ((execve(find_path(arr[0], envp), arr, envp)) == -1)
	{
		ft_free(arr);
		free(cmd);
		ft_error("cmd2");
	}
}

void	ft_fork(t_arg arg, char *envp[])
{
	int		pipefd[2];
	int		pid2;
	int		pid;

	pipe(pipefd);
	pid = fork();
	if (pid == 0)
		child(arg, pipefd, envp);
	else if (pid > 0)
	{
		pid2 = fork();
		if (pid2 == 0)
			second_child(arg, pipefd, envp);
	}
	if (pid > 0 && pid2 > 0)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		waitpid(pid, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_arg	arg;

	if (argc != 5)
		return (ft_error("argc"), EXIT_FAILURE);
	else if (*envp == NULL && !(access(argv[2], F_OK) == 0)
		&& !(access(argv[3], F_OK) == 0))
		return (ft_error("envp"), EXIT_FAILURE);
	arg.infile = argv[1];
	arg.cmd1 = argv[2];
	arg.cmd2 = argv[3];
	arg.outfile = argv[4];
	ft_fork(arg, envp);
	return (EXIT_SUCCESS);
}
