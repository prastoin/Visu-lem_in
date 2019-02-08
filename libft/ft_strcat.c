/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:30:40 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/09 17:14:02 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	if (dst[i] == '\0')
	{
		while (src[j])
		{
			dst[i] = src[j];
			i++;
			j++;
			if (src[j] == '\0')
			{
				dst[i] = '\0';
				return (dst);
			}
		}
	}
	return (dst);
}
