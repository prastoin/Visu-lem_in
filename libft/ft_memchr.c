/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:26:35 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/13 11:39:36 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (n != 0)
	{
		while (i < n)
		{
			if (((char *)s)[i] == (char)c)
				return ((char *)s + i);
			if (((char *)s)[i] == '\0' && (char)c == '\0')
				return ((char *)s + i);
			i++;
		}
	}
	return (NULL);
}
