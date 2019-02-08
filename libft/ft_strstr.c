/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:01:37 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/10 16:09:49 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *tofind)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (tofind[0] == '\0')
		return ((char *)(s1));
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i + j] == tofind[j])
		{
			if (tofind[j + 1] == '\0')
				return ((char *)(s1 + i));
			j++;
		}
		i++;
	}
	return (0);
}
