#include "pipex.h"

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
