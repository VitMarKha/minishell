/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_fix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 09:08:57 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 09:08:58 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
** ft_strjoin_fix: чистит первый аргумент.
*/

char	*ft_strjoin_fix(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	if (!(p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		++i;
	}
	free(s1);
	while (s2[j] != '\0')
	{
		p[i] = s2[j];
		++i;
		++j;
	}
	p[i] = '\0';
	return (p);
}
