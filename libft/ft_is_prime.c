/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:46:55 by amerrouc          #+#    #+#             */
/*   Updated: 2018/11/14 14:54:37 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		test_sqrt(int nbr, long int i, int *ptr)
{
	if ((i * i) < nbr)
		test_sqrt(nbr, i + 1, ptr);
	else
	{
		if ((i * i) >= nbr)
			*ptr = i;
	}
}

static int		ft_sqrt_close(int nb)
{
	int i;

	i = 0;
	if (nb <= 0)
		return (0);
	if (nb == 2)
		return (0);
	test_sqrt(nb, i, &i);
	return (i);
}

int				ft_is_prime(int nb)
{
	int i;
	int sqrt;

	sqrt = ft_sqrt_close(nb);
	i = 3;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if ((nb % 2) == 0)
		return (0);
	while (i <= sqrt)
	{
		if ((nb % i) == 0)
			return (0);
		i = i + 2;
	}
	return (1);
}
