/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figarcia <figarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:29:21 by figarcia          #+#    #+#             */
/*   Updated: 2025/03/22 20:49:35 by figarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_command(char *cmd, char **env_vars)
{
	char	*cmd_path;
	char	**args;

	if (!*cmd)
		error();
	args = ft_split(cmd, ' ');
	if (!args)
		error();
	cmd_path = find_command_in_paths(args[0], env_vars);
	if (!cmd_path)
	{
		free_str_array(args);
		perror("Command not found");
		_exit(127);
	}
	execve(cmd_path, args, env_vars);
	perror("execve failed");
	free_str_array(args);
	free(cmd_path);
	_exit(127);
}

void	redirect_in_out(int input_fd, int output_fd)
{
	if (input_fd == -1 || output_fd == -1)
		error();
	if (dup2(input_fd, STDIN_FILENO) == -1
		|| dup2(output_fd, STDOUT_FILENO) == -1)
		error();
	close(input_fd);
	close(output_fd);
}

void	child_proc1(int pipe_fd[2], char *infile, char *cmd1, char **env_vars)
{
	int	input_fd;

	input_fd = open(infile, O_RDONLY);
	if (input_fd == -1)
		error();
	close(pipe_fd[0]);
	redirect_in_out(input_fd, pipe_fd[1]);
	close(pipe_fd[1]);
	execute_command(cmd1, env_vars);
}

void	child_proc2(int pipe_fd[2], char *outfile, char *cmd2, char **env_vars)
{
	int	output_fd;

	output_fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (output_fd == -1)
		error();
	close(pipe_fd[1]);
	redirect_in_out(pipe_fd[0], output_fd);
	close(pipe_fd[0]);
	execute_command(cmd2, env_vars);
}

int	main(int argc, char **argv, char **env_vars)
{
	int		pipe_fd[2];
	int		status[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5 || pipe(pipe_fd) == -1)
		error();
	pid1 = fork ();
	if (pid1 == -1)
		error();
	if (pid1 == 0)
		child_proc1(pipe_fd, argv[1], argv[2], env_vars);
	pid2 = fork();
	if (pid2 == -1)
		error();
	if (pid2 == 0)
		child_proc2(pipe_fd, argv[4], argv[3], env_vars);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, &status[0], 0);
	waitpid(pid2, &status[1], 0);
	if (WIFEXITED(status[1]))
		exit (WEXITSTATUS(status[1]));
	return (0);
}
