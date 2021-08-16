#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int len;
	int i;

	if (fd < 0 || s == NULL)
		return ;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
		write(fd, &s[i++], 1);
}
