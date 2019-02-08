/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:57:32 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/14 15:27:34 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	temp;
	size_t	i;

	i = 0;
	if ((char *)dst < (char *)src)
	{
		while (i < n)
		{
			temp = ((char *)src)[i];
			((char *)dst)[i] = temp;
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			temp = ((char *)src)[n - 1];
			((char *)dst)[n - 1] = temp;
			n--;
		}
	}
	return ((char *)dst);
}
