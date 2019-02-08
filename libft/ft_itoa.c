/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:37:48 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/13 09:12:42 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*cnvchar(char *list, char c, int *i)
{
	list[*i] = c;
	*i = *i + 1;
	return (list);
}

static char		*putnbr(int n, char *list, int *i)
{
	long	nb;
	int		neg;

	nb = n;
	neg = 0;
	if (nb < 0)
	{
		nb = -nb;
		cnvchar(list, '-', i);
	}
	if (nb > 9)
	{
		putnbr(nb / 10, list, i);
		putnbr(nb % 10, list, i);
	}
	else
		cnvchar(list, (nb + '0'), i);
	return (list);
}

static char		*malloclist(char *list, int diz, int n)
{
	int		i;
	int		neg;

	neg = 1;
	i = 0;
	if (n < 0)
	{
		neg = 2;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		diz++;
	}
	if (!(list = (char *)malloc(sizeof(char) * (diz + neg))))
		return (NULL);
	list[diz + neg - 1] = '\0';
	return (list);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*list;
	int		diz;

	diz = 0;
	i = 0;
	list = NULL;
	if ((list = malloclist(list, diz, n)) == NULL)
		return (NULL);
	list = putnbr(n, list, &i);
	return (list);
}
