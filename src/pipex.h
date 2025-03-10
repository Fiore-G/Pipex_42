#ifndef PIPEX_H
#define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>

int  main(int argc, char **argv, char **env_vars);
void  child_process_1(int pipe_fd[2], char *infile, char *cmd1, char **env_vars);
void  child_process_2(int pipe_fd[2], char *outfile, char *cmd2, char **env_vars);
void  execute_command(char *cmd, char **env_vars);
void  redirect_in_out(int input_fd, int output_fd);
void  error(void);
char  *find_path_var(char **env_vars);
char  *get_paths_array(char **env_vars);
char  *find_command_in_paths(char *cmd, char **env_vars);
void  free_str_array(char **arr);

#endif
