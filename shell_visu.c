/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_visu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 22:07:36 by prastoin          #+#    #+#             */
/*   Updated: 2019/02/18 10:59:14 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		ft_shell_tracertrait(t_data *data, int xstart, int ystart, int x1, int y1, char **jeu)
{
	const int	x_inc = xstart < x1 ? 1 : -1;
	const int	y_inc = ystart < y1 ? 1 : -1;
	const int	dx = x1 > xstart ? x1 - xstart : xstart - x1;
	const int	dy = y1 >ystart ? y1 - ystart : ystart - y1;
	int			e[2];
	int			save_x;
	int			save_y;
	int			verif;

	verif = 0;
	e[0] = dx > dy ? dx / 2 : -dy / 2;
	save_x = xstart;
	save_y = ystart;
	while (xstart != x1 || ystart != y1)
	{
		printf("xstart %d et ystart %d xmax =%d ymax = %d\n", x1, y1, data->x_max * 4 + 4, data->y_max * 4);
		if (ystart >= 0 && ystart < (data->y_max * 4) &&
				y1 < (data->y_max * 4) && y1 >= 0 && xstart >= 0 &&
				xstart <= (data->x_max * 4 + 4) && x1 <= (data->x_max * 4 + 4) && x1 > 0)
		{
			printf("je trace\n");
			if (jeu[ystart][xstart] == ' ')
			{
				if (save_y != ystart)
				{
					if (save_x == xstart)
						jeu[ystart][xstart] = '|';
					if (save_y < ystart && save_x < xstart)
						jeu[ystart][xstart] = '\\';
					if (save_y < ystart && save_x > xstart)
						jeu[ystart][xstart] = '/';
					if (save_y > ystart && save_x > xstart)
						jeu[ystart][xstart] = '\\';
					if (save_y > ystart && save_x < xstart)
						jeu[ystart][xstart] = '/';
					verif = 1;
				}
				else
				{
					if (verif != 1)
					{
						if (xstart < save_x)
							jeu[ystart][xstart] = '=';
						else if (xstart > save_x)
						{
							if (jeu[ystart + y_inc][xstart] == ' ')
							jeu[ystart + y_inc][xstart] = '_';
						}
					}
					verif = 0;
				}
				save_x = xstart;
				save_y = ystart;
			}
		}
		if ((e[1] = e[0]) > -dx)
		{
			e[0] -= dy;
			xstart += x_inc;
		}
		if (e[1] < dy)
		{
			e[0] += dx;
			ystart += y_inc;
		}
	}
	return (0);
}

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
	int		k;
	int		count;

	count = 0;
	k = 0;
	i = 0;
	while (tab[i])
	{
		k = 0;
		count = 0;
		while(tab[i][k])
		{
			if (tab[i][k] != ' ' && tab[i][k] != '\0')
				count++;
			k++;
		}
		if (count != 0)
			printf("%s\n",tab[i]);
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
	if (!(data->jeu = (char **)malloc(sizeof(char *) * (data->y_max * 8 + 1))))
		return (-1);
	data->jeu[data->y_max * 8] = NULL;
	while (i < ((data->y_max * 8)))
	{
		if (!(data->jeu[i] = (char *)malloc(sizeof(char) * (data->x_max * 8 + 1))))
			return (-1);
		data->jeu[i][data->x_max * 6] = '\0';
		j = 0;
		while (data->jeu[i][j])
		{
			data->jeu[i][j] = ' ';
			j++;
		}
		while (j < data->x_max * 8)
		{
			data->jeu[i][j] = '\0';
			j++;
		}
		i++;
	}
	return (0);
}

void		ft_place_room(char **jeu, t_room *room, t_data *data, int curr_room)
{
	int	x;
	int	y;
	int	i;
	int	k;

	k = 1;
	(void)data;
	i = 0;
	y = room[curr_room].y * 4;
	x = room[curr_room].x * 4;
	while (jeu[y][x + k] && jeu[y][x + k] != ' ')
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
//	if (i > data->x_max)
//		jeu[y][x + i * 2] = '\0';
}

void		ft_fill_jeu(char **jeu, t_room *room, t_data *data)
{
	int		y;

	y = 0;
	while (y < data->room)
	{
		ft_place_room(jeu, room, data, y);
		y++;
	}
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
	while (data->map[i] && data->map[i][0] != 'L')
	{
		if (data->map[i][0] != '#')
		{
			len = ft_len_to_c(data->map[i], '-');
			indexa = ft_index_for(ft_strndup(data->map[i], len), room, data->room);
			indexb = ft_index_for(ft_strdup(data->map[i] + len + 1), room, data->room);
			if (indexa != -1 && indexb != -1)
				printf("indexa %s indexb %s\n", room[indexa].name , room[indexb].name);
			if (indexa != -1 && indexb != -1)
				ft_shell_tracertrait(data, ((room[indexa].x * 4) + 4), (room[indexa].y * 4), ((room[indexb].x * 4) + 4), (room[indexb].y * 4), data->jeu);
		}
		i++;
	}
	return (0);
}

int		ft_shell_visu(t_data *data, t_room *room, t_ant *ant)
{
	if ((ft_init_shell(data, room, ant)) == -1)
		return (-1);
	ft_fill_jeu(data->jeu, room, data);
	ft_get_links(room, data);
	ft_print_dbchar(data->jeu);
	return (0);
}
