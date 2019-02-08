/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:16:47 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/20 14:26:08 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i[2];
	char	*fresh;
	int		l[2];

	if (!(s1 && s2))
		return (NULL);
	i[0] = 0;
	l[0] = ft_strlen(s1);
	l[1] = ft_strlen(s2);
	i[1] = 0;
	if (!(fresh = (char *)malloc(sizeof(char) * (l[0] + l[1] + 1))))
		return (NULL);
	while (i[0] < (l[0]))
	{
		fresh[i[0]] = s1[i[0]];
		i[0]++;
	}
	while (i[0] < (l[0] + l[1]))
	{
		fresh[i[0]] = s2[i[1]];
		i[1]++;
		i[0]++;
	}
	fresh[i[0]] = '\0';
	return (fresh);
}
