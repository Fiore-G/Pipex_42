/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figarcia <figarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:50:20 by figarcia          #+#    #+#             */
/*   Updated: 2025/03/22 20:50:32 by figarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"

void	child_proc1(int pipe_fd[2], char *infile, char *cmd1, char **env_vars);
void	child_proc2(int pipe_fd[2], char *outfile, char *cmd2, char **env_vars);
void	execute_command(char *cmd, char **env_vars);
void	redirect_in_out(int input_fd, int output_fd);
void	error(void);
char	*find_path_var(char **env_vars);
char	**get_paths_array(char **env_vars);
char	*find_command_in_paths(char *cmd, char **env_vars);
void	free_str_array(char **arr);

#endif
