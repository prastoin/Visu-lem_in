/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:34:50 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/13 09:11:16 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbrspace(char *s)
{
	size_t	i;
	size_t	deb;

	i = 0;
	deb = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
		deb++;
	}
	return (deb);
}

static char		*filltab(char *s, size_t deb, int fin)
{
	char	*fresh;
	size_t	i;

	i = 0;
	if (!(fresh = malloc(sizeof(char) * (fin - deb + 1))))
		return (0);
	while (i < (fin - deb))
	{
		fresh[i] = s[deb + i];
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}

char			*ft_strtrim(const char *s)
{
	size_t	deb;
	size_t	fin;
	char	*str;

	if (!(s))
		return (NULL);
	if (!(str = ft_strdup(s)))
		return (0);
	deb = ft_nbrspace(str);
	if (deb == ft_strlen(str))
	{
		str[0] = '\0';
		return (str);
	}
	ft_strrev(str);
	fin = ft_strlen(s) - ft_nbrspace(str);
	ft_strrev(str);
	if (!(str = filltab(str, deb, fin)))
		return (0);
	return (str);
}
