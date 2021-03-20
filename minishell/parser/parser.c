#include "parser.h"
#include "../libft/libft.h"

void	check_for_command(char *line, int size)
{
	char	*p;

	if ((p = ft_strnstr("echo", line, size)) != NULL)
		printf("Делаем команду echo\n");
	if ((p = ft_strnstr("cd", line, size)) != NULL)
		printf("Делаем команду cd\n");
	if ((p = ft_strnstr("pwd", line, size)) != NULL)
		printf("Делаем команду pwd\n");
	if ((p = ft_strnstr("export", line, size)) != NULL)
		printf("Делаем команду export\n");
	if ((p = ft_strnstr("unset", line, size)) != NULL)
		printf("Делаем команду unset\n");
	if ((p = ft_strnstr("env", line, size)) != NULL)
		printf("Делаем команду env\n");
	if ((p = ft_strnstr("exit", line, size)) != NULL)
		printf("Делаем команду exit\n");
}

/*
** set_line: установка линиии в историю.
*/

void set_line(char *str, int fd)
{
	if (write(fd, str, 1) != (int)ft_strlen(str))
		error("Failed to write a string to a file");
}

/*
** get_line: считываем линию.
*/

void	get_line(char *str, int fd, int *coll_backspace)
{
	int len;

	len = read(0, str, 100);
	str[len] = 0;
	if (!strcmp(str, "\e[A")) //стрелочка вверх
	{
		tputs(restore_cursor, 1, ft_putchar);
		tputs(tigetstr("ed"), 1, ft_putchar);
		write(1, "previous", 8);
	}
	else if (!strcmp(str, "\e[B")) //стрелочка вниз
	{
		tputs(restore_cursor, 1, ft_putchar);
		tputs(tigetstr("ed"), 1, ft_putchar);
		write(1, "next", 4);
	}
	else if (!strcmp(str, "\177")) //клавиша backspase
	{
		tputs(cursor_left, 1, ft_putchar);
		tputs(tgetstr("dc", 0), 1, ft_putchar);
		set_line(str, fd);
		write(1, str, len);
		++*coll_backspace;
	}
	else // печать символа
	{
		write(1, str, len);
		set_line(str, fd);
	}
}

/*
** make_file: создаем фаил с иторией.
*/

int make_file(void)
{
	int fd;

	if (!(fd = open("minishell_history", O_CREAT, S_IWRITE | S_IREAD)))
		error("Error when creating a file with the history");
	if (!(fd = open("minishell_history", O_RDWR | O_TRUNC)))
		error("An error occurred while opening the history file");
	return (fd);
}

// void delet_backspace(int fd, int *coll_backspace)
// {
	
// }

/*
** parser: запуск парсера.
*/

void	parser(void)
{
	int		fd;
	char	str[2000];
	int		coll_backspace;
	struct	termios term;

	coll_backspace = 0;
	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &term);
	tgetent(0, "xterm-256color");
	fd = make_file();
	while (strcmp(str, "\4"))
	{
		tputs(save_cursor, 1, &ft_putchar);
		write(1, "\033[0;35m$minishell: \033[0m", 23);
		get_line(str, fd, &coll_backspace);
		while (strcmp(str, "\n") && strcmp(str, "\4"))
			get_line(str, fd, &coll_backspace);
	}
	write(1, "\n", 1);
	printf("coll: %d\n", coll_backspace);
	term.c_lflag |= ~(ECHO);
	term.c_lflag |= ~(ICANON);
}
