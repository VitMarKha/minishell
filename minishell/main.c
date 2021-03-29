#include "logic/logic.h"
#include "parser/parser.h"
#include "libft/libft.h"

/*
** main: запуск программы
*/

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;

	write(1, "Welcome to Minishell Fngoc and Drarlean!\n", 41);

	params = malloc(sizeof (g_list));
	params->env = env_copy(env);

//	export_var("a=\"10\"");
//	export();
	parser();


	// params = malloc(sizeof (g_list));
	// params->env = env_copy(env);
	// pid_t pid;

	// pid = fork();
	// if (pid > 0)
	// {
	// 	int status;
	// 	waitpid(pid, &status, 0);
	// }
	// else
	// {
	// 	exec("pwd", argv, env);
	// }

	// while (1)
	// {

	// }
	return (0);
}
