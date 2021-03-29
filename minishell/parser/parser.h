#ifndef PARSER_H

# define PARSER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <term.h>
# include <fcntl.h>
# include <errno.h>
#include "../libft/libft.h"

typedef struct s_parser
{
    char	**map_history;
	char	**map_comand;
	int		len_map;
	char	*buf;
	char	*str;
	int		len_str;
	int		backspace;
    int		step_history;
	int		flag_step_history_next;
	int		flag_step_history_previou;
}               t_parser;

void    parser(void);

void    error(char *str);

int     ft_putchar(int c);

struct  termios init(void);

int     make_file(void);

int     ft_strcmp(const char *str1, const char *str2);

void	set_line(char const *str, int fd, t_parser *p);

int		is_arrow(char const *buf);

int		ft_istab(char c);

void	free_map(char **map);

char    *delet_last_char(char *str, int coll_backspace);

char	*ft_strjoin_char_free(char *s1, char c);

void	get_history_next(t_parser *p);

void	get_history_previous(t_parser *p);

char	*check_bufer(t_parser *p);

void	send_command_execute(char **map_comand);

void	check_command(char *line, t_parser *p);

#endif
