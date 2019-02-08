/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:22:56 by prastoin          #+#    #+#             */
/*   Updated: 2019/01/23 13:14:39 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_line(char **lus)
{
	char	*occ;
	char	*tmp;
	char	*line;

	occ = ft_strchr(*lus, '\n');
	tmp = NULL;
	if (occ != NULL)
	{
		if (!(line = ft_strndup(*lus, occ - *lus)))
			return (NULL);
		tmp = *lus;
		if (!(*lus = ft_strdup(occ + 1)))
			return (NULL);
		free(tmp);
	}
	else if (!(line = ft_strdup(*lus)))
		return (NULL);
	if (!((*lus) && tmp))
	{
		free(*lus);
		*lus = NULL;
	}
	return (line);
}

static char	*reading(int fd, char **lus, char *buf)
{
	ssize_t	ret;
	char	*tmp;

	ret = 1;
	tmp = NULL;
	while ((ft_strchr(*lus, '\n') == NULL) && ret > 0)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
		if (ret > 0)
		{
			tmp = *lus;
			buf[ret] = '\0';
			if (!(*lus = ft_strjoin(*lus, buf)))
				return (NULL);
			free(tmp);
			tmp = NULL;
		}
	}
	free(buf);
	return (*lus);
}

int			get_next_line(const int fd, char **line)
{
	static char	*lus[OPEN_MAX];
	char		*buf;

	if ((fd < 0) || (BUFF_SIZE <= 0) || (fd >= OPEN_MAX))
		return (-1);
	if (!(buf = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if (!(lus[fd]))
		if (!(lus[fd] = ft_strnew(0)))
			return (-1);
	if (!(reading(fd, lus + fd, buf)))
		return (-1);
	if (*(lus[fd]))
	{
		if (!(*line = ft_line(lus + fd)))
			return (-1);
		return (1);
	}
	return (0);
}
