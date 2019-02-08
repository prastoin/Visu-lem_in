/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:29:34 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/13 11:29:53 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count(const char *s, int c)
{
	size_t i;
	size_t max;

	i = 0;
	max = ft_strlen(s);
	while (s[i] != c && s[i])
		i++;
	if (i == max && s[i] != c)
		return (0);
	else
		return (i);
}

char			*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = ft_strdup(s);
	ft_strrev(str);
	i = count(str, c);
	if (c == '\0')
		return ((char *)s + (ft_strlen(s)));
	if (i == 0 && c != s[(ft_strlen(s) - i - 1)])
		return (NULL);
	else
		return ((char *)s + (ft_strlen(s) - i - 1));
}
