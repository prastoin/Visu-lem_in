/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 09:25:46 by prastoin          #+#    #+#             */
/*   Updated: 2019/02/12 16:57:46 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#define BUFF_SIZE 4096
#include "libft/libft.h"


char		*ft_read(int fd)
{
	char	buff[BUFF_SIZE];
	int		ret;
	char	*stck;
	int		verif;

	verif = 0;
	stck = ft_strnew(0);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(stck = ft_strjoin(stck, buff)))
			return (NULL);
		verif++;
	}
	if (ret < 0 || verif == 0)
		return (NULL);
	return (stck);
}

int		ft_get_line(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '#')
		i++;
	return (ft_atoi(str + i + ft_strlen("Here is the number of lines required: ")));
}

int		ft_count_instructions(char *str)
{
	int		len;
	int		i;
	int		count;

	count = 0;
	len = ft_strlen(str);
	i = len;
	while (str[i] != '#')
		i--;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == 'L')
			count++;
		i++;
	}
	printf("%d\n", count);
	return (count);
}

int main(void)
{
	int	fd;
	char	*str;
	int		line;
	int		move;

	fd = 0;
	str = ft_read(fd);
	line = ft_get_line(str);
	move = ft_count_instructions(str);
	printf("Required line number was %d did %d\n", line, move);
	return 0;
}
