/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:01:37 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/10 16:41:55 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *tofind, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (tofind[0] == '\0')
		return ((char *)s1);
	while (i <= len && s1[i])
	{
		j = 0;
		while (s1[i + j] == tofind[j] && (i + j) < len)
		{
			if (tofind[j + 1] == '\0')
				return ((char *)(s1 + i));
			j++;
		}
		i++;
	}
	return (0);
}
