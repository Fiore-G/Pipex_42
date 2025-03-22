#include "pipex.h"

void	error(void)
{
  perror("Error");
	exit(EXIT_FAILURE);
}

char	*find_path_var(char **env_vars)
{
	int	i;
	
	i = 0;
	while(env_vars[i])
	{
		if (ft_strncmp(env_vars[i], "PATH=", 5) == 0)
			return (env_vars[i] + 5);
		i++;
	}
	return (NULL);
}

char	**get_paths_array(char **env_vars)
{
	char	*path_env;
	char	**paths;
  
	path_env = find_path_var(env_vars);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		error();
	return (paths);
}

char	*find_command_in_paths(char *cmd, char **env_vars)
{
	char  **paths;
	char  *cmd_path;
	char  *full_path;
	int              i;
	
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	paths = get_paths_array(env_vars);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = ft_strjoin(paths[i], "/");
		if (!full_path)
			return (free_str_array(paths), NULL);
		cmd_path = ft_strjoin(full_path, cmd);
		free(full_path);
		if (!cmd_path)
			return (free_str_array(paths), NULL);
		if (access(cmd_path, X_OK) == 0)
			return (free_str_array(paths), cmd_path);
		free(cmd_path);
		i++;
	}
	free_str_array(paths);
	return (NULL);
}

void	free_str_array(char **arr)
{
	int	i;
	
	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
