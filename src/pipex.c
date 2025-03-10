#include "pipex.h"

void  redirect_in_out(int input_fd, int output_fd)
{
  if (input_fd == -1 || output_fd == -1)
    error();
  if (dup2(input_fd, STDIN_FILENO) == -1 || dup2(output_fd, STDOUT_FILENO) == -1)
    error();
  close(input_fd);
  close(output_fd);
}

void  execute_command(char *cmd, char **env_vars)
{
  char  *cmd_path;
  char **args;

  args = ft_split(cmd, ' ');
  if (!args)
    error();
  cmd_path = find_command_in_paths(args[0], env_vars);
  if (!cmd_vars)
  {
    free_str_array(args);
    error();
  }
  execve(cmd_path, args, env_vars);
  free_str_array(args);
  free(cmd_path);
  error();  
}
