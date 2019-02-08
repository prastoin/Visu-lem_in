/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:54:47 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/17 17:15:25 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char *s, char c)
{
	int	i;
	int	count_words;
	int	is_words;

	i = 0;
	count_words = 0;
	is_words = 0;
	while (s[i])
	{
		if (is_words == 0 && s[i] != c)
		{
			is_words = 1;
			count_words++;
		}
		else if (is_words == 1 && s[i] == c)
			is_words = 0;
		i++;
	}
	return (count_words);
}

static int	ft_len_words(char *s, int c, int k)
{
	int	len;

	len = 0;
	while (s[k] != c && s[k])
	{
		len++;
		k++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		k;
	int		nbr_words;
	char	**tab;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	nbr_words = ft_countwords((char *)s, c);
	if (!(tab = (char**)malloc(sizeof(char *) * (nbr_words + 1))))
		return (NULL);
	while (nbr_words > 0)
	{
		while (s[k] == c && s[k])
			k++;
		if (!(tab[i] = ft_strsub((char *)s, k, ft_len_words((char *)s, c, k))))
			return (NULL);
		k += ft_len_words((char *)s, c, k);
		i++;
		nbr_words--;
	}
	tab[i] = NULL;
	return (tab);
}
