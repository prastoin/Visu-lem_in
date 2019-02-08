/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:54:29 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/11 15:13:17 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s1)
{
	int		i;
	char	temp;
	int		len;

	len = ft_strlen(s1);
	len--;
	i = 0;
	while (i < len)
	{
		temp = s1[i];
		s1[i] = s1[len];
		s1[len] = temp;
		i++;
		len--;
	}
	return (s1);
}
