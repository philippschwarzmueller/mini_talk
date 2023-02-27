#include "shell.h"

void	reset_cmd(char **command, char **options, int *in, int *out)
{
	command[0] = NULL;
	options[0] = NULL;
	*in = 0;
	*out = 0;
}

t_command	*create_cmd(char *command, char *options, int in, int out)
{
	t_command	*cmd;

	cmd = malloc(sizeof(*cmd));
	if (!cmd)
		return (NULL);
	cmd->command = command;
	cmd->options = options;
	cmd->path = NULL;
	cmd->in = in;
	cmd->out = out;
	return (cmd);
}

struct s_state	init_state(void)
{
	struct s_state	state;

	state.pipe = false;
	state.option = false;
	state.command = false;
	state.redirect = false;
	state.last = false;
	return (state);
}
