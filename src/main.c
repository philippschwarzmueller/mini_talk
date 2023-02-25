#include "shell.h"

int	main(void)
{
	char	*input;
	t_list	*lst;

	lst = NULL;
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
		lst = analyzer(input);
		print_lexed_lst(lst);
		ft_lstclear(&lst, del_token);
	}
	return (EXIT_SUCCESS);
}
