/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:57:30 by prastoin          #+#    #+#             */
/*   Updated: 2018/11/14 13:44:15 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char		*ft_strcapitalize(char *str)
{
	int		i;
	char	*stock;

	stock = "rien";
	i = 0;
	stock = ft_strlowcase(str);
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i - 1] >= 'a' && str[i - 1] <= 'z')
				i++;
			else if (str[i - 1] >= '0' && str[i - 1] <= '9')
				i++;
			else
			{
				str[i] = str[i] - 32;
				i++;
			}
		}
		i++;
	}
	return (str);
}
