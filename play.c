/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 00:47:31 by fbecerri          #+#    #+#             */
/*   Updated: 2019/02/09 01:48:00 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		ft_get_index_start(t_room *room, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->room)
	{
		if (room[i].start_end == 1)
			data->index_start = i;
		if (room[i].start_end == 2)
			data->index_end = i;
		i++;
	}
	return (0);
}

t_ant	*ft_init_ant(t_data *data, t_room *room)
{
	int		i;
	t_ant	*ant;

	i = 0;
	ft_get_index_start(room, data);
	if (!(ant = (t_ant *)malloc(sizeof(t_ant) * data->fourmis)))
		return (NULL);
	while (i < data->fourmis)
	{
		ant[i].curr = 0;
		ant[i].previous = data->index_start;
		ant[i].coup = 0;
		i++;
	}
	return (ant);
}

void	ft_put_red_square(t_data *data, t_room *room, int i)
{
	int x;
	int y;

	x = data->zm + room[i].x * data->zm;
	y = data->zm2 + room[i].y * data->zm2;
	mlx_put_image_to_window(data->mlx, data->win, data->img, x, y);
	mlx_string_put(data->mlx, data->win, x, y, 0xFFFFFF, room[i].name);
}

void	ft_put_green_square(t_data *data, t_room *room, int i)
{
	int x;
	int y;

	x = data->zm + room[i].x * data->zm;
	y = data->zm2 + room[i].y * data->zm2;
	mlx_put_image_to_window(data->mlx, data->win, data->img2, x, y);
	mlx_string_put(data->mlx, data->win, x, y, 0xFFFFFF, room[i].name);
}

int		ft_play_cut(t_room *room, t_data *data, t_ant *ant, int y)
{
	int		curr_ant;
	int		i;

	i = 0;
	printf("%s\n", data->map[y]);
	while (data->map[y][i])
	{
		if (data->map[y][i] == 'L')
			i++;
		curr_ant = ft_atoi(data->map[y] + i);
		i += ft_lennbr(curr_ant) + 1;
		printf("i = %d et len = %ld\n", i, ft_strlen(data->map[y]));
		if (ant[curr_ant - 1].previous != data->index_start)
			ft_put_red_square(data, room, ant[curr_ant - 1].previous);
		ant[curr_ant - 1].curr = ft_index_for_links(data->map[y] + i, room, data->room, ft_len_to_c(data->map[y] + i, ' '));
		i += ft_len_to_c(data->map[y] + i, ' ');
		if (ant[curr_ant - 1].curr != data->index_end)
			ft_put_green_square(data, room, ant[curr_ant - 1].curr);
//		i += ft_lennbr(ant[curr_ant - 1].curr);
		i += i < (int)ft_strlen(data->map[y]) ? 1 : 0;
		ant[curr_ant - 1].previous = ant[curr_ant - 1].curr;
	}
	return (0);
}

int		ft_play(t_data *data)
{
	static int	i;

	if (!(i))
	{
		while (data->map[i][0] != 'L')
			i++;
	}
	if (data->map[i])
		ft_play_cut(data->room2, data, data->ant, i);
	else
		exit(0);
	i++;
	return (0);
}
