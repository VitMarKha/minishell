#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	size_t	i;

	p = NULL;
	i = 0;
	if (s && f && (p = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
	{
		while (s[i])
		{
			p[i] = f(i, s[i]);
			++i;
		}
		p[i] = '\0';
	}
	return (p);
}
