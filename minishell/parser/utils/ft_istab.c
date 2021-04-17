/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 09:08:04 by fngoc             #+#    #+#             */
/*   Updated: 2021/04/17 09:08:04 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
** ft_istab: возвращает не нулевое значение
** если найден пробел.
*/

int	ft_istab(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}
