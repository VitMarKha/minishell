/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:07:29 by fngoc             #+#    #+#             */
/*   Updated: 2021/02/02 12:55:40 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_tolower: выполняет преобразование прописных букв в строчные.
*/

int	ft_tolower(int c)
{
	return ((c >= 65 && c <= 90) ? (c + 32) : c);
}
