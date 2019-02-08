/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:08:53 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/17 17:13:23 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*fresh;
	size_t		i;

	i = 0;
	if (!(s))
		return (NULL);
	if (s[0] == '\0')
		return (NULL);
	if (!(fresh = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		fresh[i] = ((char *)s)[start + i];
		i++;
	}
	fresh[len] = '\0';
	return (fresh);
}
