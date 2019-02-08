/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:58:21 by prastoin          #+#    #+#             */
/*   Updated: 2019/02/08 21:45:46 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		ft_init_complete(t_data *data)
{
	int		y;
	char	**map;

	map = data->map;
	y = 0;
	data->nbroom = 0;
	while (map[y][0] == '#')
		y++;
	data->nbfourmis = ft_atoi(map[0]);
	y++;
	while (map[y][0] != '\n')
	{
		if (map[y][0] != '#')
		{
			if (ft_nbr_c(map[y], ' ') == 2)
			{
				if (data->nbroom == 0)
					data->first_room = y;
				data->nbroom++;
			}
			else if (ft_nbr_c(map[y], '-') == 1)
			{
				data->first_link = y;
				break;
			}
		}
		else if (map[y][0] == '#' && map[y][1] == '#')
		{
			if (ft_strcmp("##start", map[y]) == 0)
				data->start = y;
			else if (ft_strcmp("##end", map[y]) == 0)
				data->end = y;
		}
		y++;
	}
	data->end_map = y;
	return (0);
}

int	ft_init(t_data *data)
{
	if (!(data->map = ft_read()))
		return (-1);
	else
		ft_init_complete(data);
	if (!(data->mlx = mlx_init()))
		return (-1);
	if (!(data->win = mlx_new_window(data->mlx, SCREEN_X, SCREEN_Y, "Visu lem_in fbecerri prastoin")))
		return (-1);
	return (0);
}

int		ft_init_room_links(t_room *room, t_data *data)
{
	int		y;
	char	**map;
	int		index;
	int		len;
	int		len2;
	int		indexa;
	int		indexb;

	len2 = 0;
	len = 0;
	index = 0;
	map = data->map;
	y = 0;
	while (y < data->end_map)
	{
		if (map[y][0] != '#')
		{
			len = ft_len_to_c(map[y], '-');
			indexa = ft_index_for(ft_strndup(map[y], len), room, data->nbroom);
			len2 = ft_len_to_c(map[y] + len + 1, '\0');
			indexb = ft_index_for(ft_strndup(map[y] + len + 1, len2), room, data->nbroom);
			room[indexa].index[room[indexa].links] = indexb;
			room[indexb].index[room[indexb].links] = indexa;
			room[indexa].links++;
			room[indexb].links++;
		}
		y++;
	}
	return (0);
}

t_room	*ft_init_room(t_data *data)
{
	t_room *room;
	char	**map;
	int		i;
	int		y;
	int		len;

	len = 0;
	y = data->first_room;
	map = data->map;
	i = 0;
	if (!(room = malloc(sizeof(t_room) * data->nbroom)))
		return (NULL);
	while (y < data->first_link)
	{
		if (map[y][0] != '#')
		{
			len = ft_len_to_c(map[y], ' ');
			room[i].name = ft_strndup(map[y], len);
			room[i].x = ft_atoi(map[y] + len);
			room[i].y = ft_atoi(map[y] + 1 + len + ft_lennbr(room[i].x));
			printf("x = %d y = %d\n", room[i].x, room[i].y);
			room[i].links = 0;
			room[i].slot = 0;
			if (y - 1 == data->start)
				room[i].start_end = 1;
			else if (y - 1 == data->end)
				room[i].start_end = 2;
			else
				room[i].start_end = 0;
			i++;
		}
		y++;
	}
	return (room);
}

