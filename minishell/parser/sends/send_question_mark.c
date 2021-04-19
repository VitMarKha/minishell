#include "../../minishell.h"

void	send_question_mark(void)
{
	write(2, "\033[0;35m(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧  \033[0m", 41);
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd(get_var_param(g_params->env, "?"), 2);
	ft_putstr_fd("\n", 2);
}
