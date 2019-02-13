/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_visu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 22:07:36 by prastoin          #+#    #+#             */
/*   Updated: 2019/02/13 03:33:43 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	ft_get_coord_max(t_room *room, t_data *data, int nbroom)
{
	int		i;

	i = 0;
	data->x_max = 0;
	data->y_max = 0;
	while (i < nbroom)
	{
		if (data->x_max < room[i].x)
			data->x_max = room[i].x;
		if (data->y_max < room[i].y)
			data->y_max = room[i].y;
		i++;
	}
}

void	ft_print_dbchar(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		printf("=%s\n",tab[i]);
		i++;
	}
}

int			ft_init_shell(t_data *data, t_room *room, t_ant *ant)
{
	int		i;
	int		j;

	j = 0;
	(void)ant;
	i = 0;
	ft_get_coord_max(room, data, data->room);
	if (!(data->jeu = (char **)malloc(sizeof(char *) * 10000)))
		return (-1);
	data->jeu[(data->y_max * 2) + 1] = NULL;
	while (i < ((data->y_max * 2) + 1))
	{
		if (!(data->jeu[i] = (char *)malloc(sizeof(char) * 10000)))
			return (-1);
		data->jeu[i][data->x_max * 3] = '\0';
		j = 0;
		while (data->jeu[i][j])
		{
			data->jeu[i][j] = ' ';
			j++;
		}
		while (j < data->x_max * 5)
		{
			data->jeu[i][j] = '\0';
			j++;
		}
		i++;
	}
	if (!(data->len = (int *)malloc(sizeof(int) * (data->y_max + 1))))
		return (-1);
	j = 0;
	while (j <= data->y_max)
	{
		data->len[j] = 0;
		j++;
	}
	return (0);
}

void		ft_place_room(char **jeu, t_room *room, t_data *data, int curr_room)
{
	int	x;
	int	y;
	int	i;
	int	k;

	k = 0;
	(void)data;
	i = 0;
	y = room[curr_room].y * 2;
	x = room[curr_room].x * 2;
	while (jeu[y][x + k] != ' ')
		k++;
	if (k != 0)
		k++;
	x += k;
	jeu[y][x] = '[';
	while (room[curr_room].name[i])
	{
		jeu[y][x + i + 1] = room[curr_room].name[i];
		i++;
	}
	jeu[y][x + i + 1] = ']';
	if (i > data->x_max)
		jeu[y][x + i * 2] = '\0';
}

int		ft_check_coord(int x, int y, t_room *room, int nbroom)
{
	int		i;

	i = 0;
	while (i < nbroom)
	{
		if (room[i].x  == x && room[i].y == y)
			return (i);
		i++;
	}
	return (-1);
}

void		ft_fill_jeu(char **jeu, t_room *room, t_data *data)
{
	int		x;
	int		y;
	int		index;

	index = 0;
	y = 0;
	while (jeu[y])
	{
		x = 0;
		while (x < (data->x_max + 1))
		{
			index = ft_check_coord(x, y, room, data->room);
			if (index != -1)
				ft_place_room(jeu, room, data, index);
			x++;
		}
		y++;
	}
}

int		ft_check_corner(char **jeu, int x, int y, t_data *data)
{
	printf("%d et %d\n", x, y);
	if (y - 1 >= 0 && x - 1 >= 0 && y + 1 < data->y_max * 2 + 1)
	{
		if (jeu[y - 1][x - 1] != '/' && jeu[y + 1][x + 1] != '/'
				&& jeu[y + 1][x - 1] != '\\' && jeu[y - 1][x + 1] != '\\')
		return (0);
	}
	return (-1);
}

void		ft_place_links(char **jeu, t_room *room, t_data *data, int indexa, int indexb)
{
	int		x1;
	int		y1;
	int		x;
	int		y;
	int		cpt;

	cpt = 0;
	(void)data;
	x1 = room[indexb].x * 2 + 1;
	x = room[indexa].x * 2 + 1;
	y1 = room[indexb].y * 2;
	y = room[indexa].y * 2;
	printf("x1 %d y1 %d\nx  %d y  %d\n", x1, y1, x, y);
	while (y != y1 && jeu[y])
	{
		if (jeu[y][x] == ' ')
		{
			if ((y == y1 - 1 || y == y1 + 1 ) && x < x1)
				jeu[y][x] = '/';
			else if ((y == y1 - 1 || y == y1 + 1 ) && x > x1)
				jeu[y][x] = '\\';
			else
				jeu[y][x] = '|';
			cpt++;
		}
		if (y > y1)
			y--;
		else
			y++;
	}
	while (x != x1 && jeu[y][x])
	{
		if (jeu[y][x] == ' ')
			jeu[y][x] = cpt == 1 ? '_' : '-';
			if (y == y1 - 1 || y == y1 + 1 || x == x1 - 1 || x == x1 + 1)
			if (ft_check_corner(jeu, x, y, data) == 0 && jeu[y][x] == '-')
				jeu[y][x] = ' ';
		if (x >= x1)
		{
			cpt = 1;
			x--;
		}
		else
			x++;
	}
	ft_print_dbchar(jeu);
}

int		ft_get_links(t_room *room, t_data *data)
{
	int		i;
	int		len;
	int		indexa;
	int		indexb;

	while ((nbr_space(data->map[data->step1], '-') != 1) || data->map[data->step1][0] == '#')
		data->step1++;
	i = data->step1;
	printf("%s\n", data->map[data->step1]);
	while (data->map[i][0] != 'L' && data->map[i])
	{
		if (data->map[i][0] != '#')
		{
			len = ft_len_to_c(data->map[i], '-');
			indexa = ft_index_for(ft_strndup(data->map[i], len), room, data->room);
			indexb = ft_index_for(ft_strdup(data->map[i] + len + 1), room, data->room);
			printf("indexa %s indexb %s\n", room[indexa].name , room[indexb].name);
			if (indexa != -1 && indexb != -1)
				ft_place_links(data->jeu, room, data, indexa, indexb);
		}
		i++;
	}
	return (0);
}

int		ft_shell_visu(t_data *data, t_room *room, t_ant *ant)
{
	//	ft_print_dbchar(data->map);
	if ((ft_init_shell(data, room, ant)) == -1)
		return (-1);
	//	ft_print_dbchar(data->jeu);
	ft_fill_jeu(data->jeu, room, data);
	ft_get_links(room, data);
	//	ft_place_links(data->jeu, room, data);
	//	ft_print_struc(room, data->room);
	ft_print_dbchar(data->jeu);
	return (0);
}
