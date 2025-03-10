#include "pipex.h"

void  execute_command(char *cmd, char **env_vars)
{
  char **args;

  args = ft_split(cmd, ' ');
  if (!args)
    error();
  execve(args[0], args, env_vars);
  error();  
}

void  redirect_in_out(int input_fd, int output_fd)
{
  if (input_fd == -1 || output_fd == -1)
    error();
  dup2(input_fd, STDIN_FILENO);
  dup2(output_fd, STDOUT_FILENO);
  close(input_fd);
  close(output_fd);
}

void  error(void)
{
  perror("Error");
  exit(EXIT_FAILURE);
}
