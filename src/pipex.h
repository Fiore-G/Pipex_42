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

void  pipex(char *argv[]);
void  execute_command(char *cmd, char **env_vars);
void  redirect_in_out(int input_fd, int output_fd);
void  handle_errors(const char *msg);

#endif
