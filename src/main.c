#include "shell.h"

int	main(void)
{
	char	*input;
	t_list	*command_table;
	t_list	*lexed_args;

	command_table = NULL;
	while (1)
	{
		init_signalhandlers();
		input = readline("\033[0;31msigmashell \033[0;32m> \033[0;37m");
		add_history(input);
		if (input == NULL)
		{
			rl_replace_line("TEST", 0);
			rl_redisplay();
			clear_history();
			exit(EXIT_SUCCESS);
		}
		lexed_args = lexing(input);
		command_table = parse(lexed_args);
		print_lst(command_table);
		ft_lstclear(&command_table, free);
	}
	return (EXIT_SUCCESS);
}

void	print_lst(t_list *command_table)
{
	t_command	*temp;

	while (command_table != NULL)
	{
		temp = (t_command *)command_table->content;
		ft_printf("------------------\n");
		ft_printf("%p\n", temp);
		ft_printf("Command: %s\n", (char *)temp->command);
		ft_printf("Path: %s\n", (char *)temp->path);
		ft_printf("In: %s\n", (char *)temp->in);
		ft_printf("Out: %s\n", (char *)temp->out);
		ft_printf("------------------\n");
		command_table = command_table->next;
	}
}
