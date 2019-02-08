/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:28:47 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/13 11:24:57 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	max;

	i = 0;
	max = ft_strlen(s);
	while (s[i] != c && s[i])
		i++;
	if (i == max && s[i] != c)
		return (0);
	else
		return ((char *)(s + i));
}
