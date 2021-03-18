/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:53:23 by fngoc             #+#    #+#             */
/*   Updated: 2021/02/02 12:53:52 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_lstsize: возвращает длину списка.
*/

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*p;

	i = 0;
	p = lst;
	while (p != NULL)
	{
		p = p->next;
		++i;
	}
	return (i);
}