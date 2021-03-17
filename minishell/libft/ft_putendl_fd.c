/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:46:43 by fngoc             #+#    #+#             */
/*   Updated: 2021/02/02 12:54:24 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putendl_fd: Выводит строку в указанный файл
** дескриптор, за которым следует новая строка.
*/

void	ft_putendl_fd(char *s, int fd)
{
	int		len;
	int		i;
	char	endl;

	if (fd < 0 || s == NULL)
		return ;
	i = 0;
	endl = '\n';
	len = ft_strlen(s);
	while (i < len)
		write(fd, &s[i++], 1);
	write(fd, &endl, 1);
}
