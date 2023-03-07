#include "shell.h"

static char	*lower_str(char *str);

int	builtin_controller_child(t_command *cmd, char **env)
{
	char	*str;

	(void)env;
	str = lower_str(cmd->command);
	if (str == NULL)
		return (0);
	if (!ft_strncmp(str, "echo", 5))
		return (free(str), ft_echo(cmd->options), 1);
	if (!ft_strncmp(str, "pwd", 4))
		return (free(str), ft_pwd(cmd->options), 1);
	if (!ft_strncmp(str, "env", 4))
		return (free(str), ft_env(env), 1);
	return (free(str), 0);
}

int	builtin_controller_parent(t_command *cmd, char ***env)
{
	char	*str;

	str = lower_str(cmd->command);
	if (str == NULL)
		return (0);
	if (!ft_strncmp(str, "cd", 3))
		return (free(str), ft_cd(cmd->options, *env), 1);
	if (!ft_strncmp(str, "export", 7))
		return (free(str), 1);
	if (!ft_strncmp(str, "unset", 6))
		return (free(str), ft_unset(env, cmd->options), 1);
	if (!ft_strncmp(str, "exit", 5))
		return (free(str), 1);
	return (free(str), 0);
}

static char	*lower_str(char *str)
{
	size_t	i;
	char	*res;

	i = 0;
	res = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	while (str[i])
	{
		res[i] = ft_tolower(str[i]);
		i++;
	}
	return (res);
}

int	update_env(char **env, char *varname, char *value)
{
	size_t	i;

	i = 0;
	while (env && env[i] && i < ft_stra_len(env))
	{
		if (ft_strncmp(varname, env[i], ft_strlen(varname)) == 0)
		{
			free(env[i]);
			env[i] = ft_strjoin(varname, value);
		}
		i++;
	}
	if (env && env[i] && ft_strncmp(varname, env[i], ft_strlen(varname)))
		env = add_to_environment(env, varname, value);
	return (EXIT_SUCCESS);
}

char	**add_to_environment(char **env, char *varname, char *value)
{
	size_t		i;
	char		**res;

	i = 0;
	if (env == NULL)
		return (NULL);
	res = malloc((ft_stra_len(env) + 2) * sizeof(char *));
	while (env[i] != NULL)
	{
		res[i] = env[i];
		i++;
	}
	res[i] = ft_strjoin(varname, value);
	i++;
	res[i] = NULL;
	free(env);
	return (res);
}
