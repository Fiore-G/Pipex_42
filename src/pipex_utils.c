#include "pipex.h"

void  error(void)
{
  perror("Error");
  exit(EXIT_FAILURE);
}

char  *find_path_var(char **env_vars)
{
  int  i;

  i = 0;
  while(env_vars[i])
    {
      if (ft_strncmp(env_vars[i], "PATH=", 5) == 0)
        return (env_vars[i] + 5);
      i++;
    }
  return (NULL);
}

char  **get_paths_array(char **env_vars)
{
  char  *path_env;
  
  path_env = find_path_var(env_vars);
  if (!path_env)
    return (NULL);
  return (ft_split(path_env, ':'));
}

char  *find_command_in_paths(char *cmd, char **env_vars)
{
  char  **paths;
  char  *cmd_path;
  char  *full_path;
  int              i;

  i = 0;
  paths = get_paths_array(env_vars);
  if (!paths)
    return (NULL);
  while (paths[i])
  {
    full_path = ft_strjoin(paths[i], "/");
    cmd_path = ft_strjoin(full_path, cmd);
    free(full_path);
    if (access(cmd_path, X_OK) == 0)
    {
      free_str_array(paths);
      return (cmd_path);
    }
    free(cmd_path);
    i++;
  }
  free_str_array(paths);
  return (NULL);
}

void  free_str_array(char **arr)
{
  int  i;

  i = 0;
  if (!arr)
    return ;
  while (arr[i])
    free(arr[i++]);
  free(arr);
}
