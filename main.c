/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 09:23:37 by prastoin          #+#    #+#             */
/*   Updated: 2019/02/13 02:05:07 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"


int		ft_tracertrait(t_data *data, int x, int y)
{
	const int	x_inc = data->xstart < x ? 1 : -1;
	const int	y_inc = data->ystart < y ? 1 : -1;
	const int	dx = x > data->xstart ? x - data->xstart : data->xstart - x;
	const int	dy = y > data->ystart ? y - data->ystart : data->ystart - y;
	int			e[2];

	e[0] = dx > dy ? dx / 2 : -dy / 2;
	while (data->xstart != x || data->ystart != y)
	{
		if (data->ystart >= 0 && data->ystart < SCREEN_Y &&
				y < SCREEN_Y && y >= 0 && data->xstart >= 0 &&
				data->xstart < SCREEN_X && x < SCREEN_X && x > 0)
			data->img_ptr2[data->ystart * SCREEN_X + data->xstart] = 0xFFFFFF;
		if ((e[1] = e[0]) > -dx)
		{
			e[0] -= dy;
			data->xstart += x_inc;
		}
		if (e[1] < dy)
		{
			e[0] += dx;
			data->ystart += y_inc;
		}
	}
	return (0);
}

int	deal_key(int key, t_data *data)
{
	if (key == KEY_RIGHT && data->oto == 0)
		ft_play(data);
	if (key == KEY_LEFT && data->oto == 0)
		ft_inv_play(data);
	if (key == KEY_ESC)
		exit (0);
	if (key == KEY_SPACE)
	{
		data->time = time(NULL);
		data->oto = data->oto == 0 ? 1 : 0;
	}
	(void)data;
	return (0);
}


char		*ft_reading(void)
{
	char	buff[BUFF_SIZE];
	int		ret;
	int		check;
	char	*str;

	check = 0;
	str = ft_strnew(0);
	while ((ret = read(0, buff, BUFF_SIZE - 1)) > 0)
	{
		buff[ret] = '\0';
		check++;
		if (!(str = ft_strjoin(str, buff)))
			return (NULL);
	}
	if (ret < 0 || check == 0)
		return (NULL);
	return (str);
}

char		**ft_read(void)
{
	char	*str;
	char	**map;

	if (!(str = ft_reading()))
		return (NULL);
	if (!(map = ft_strsplit(str, '\n')))
		return (NULL);
	return (map);
}

void	ft_init_join(t_data *data, t_room *room)
{
	int y;
	int len;
	char	**map;
	int		indexa;
	int		indexb;

	map = data->map;
	y = 0;
	while (nbr_space(map[y], '-') != 1 || map[y][0] == '#')
		y++;
	while (map[y][0] != 'L' && map[y])
	{
		if (map[y][0] != '#')
		{
			len = ft_len_to_c(map[y], '-');
			indexa = ft_index_for(ft_strndup(map[y], len), room, data->room);
			indexb = ft_index_for(ft_strdup(map[y] + len + 1), room, data->room);
			printf("map[%d] = %s\n", y, map[y]);
			printf("indexa = %d -- indexb = %d\n", indexa, indexb);
			data->xstart = data->zm + room[indexa].x * data->zm;
			data->ystart = data->zm2 + room[indexa].y * data->zm2;
			ft_tracertrait(data, (data->zm + room[indexb].x * data->zm), (data->zm2 + room[indexb].y * data->zm2));
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img2, 0,  0);
	printf ("first join %d\n", data->x_extrem / SIZE);
}

int		auto_play(t_data *data)
{
	mlx_string_put(data->mlx, data->win, data->xpos[0] - 22, data->ypos[0] - 10, 0xFFFFFF, "START");
	mlx_string_put(data->mlx, data->win, data->xpos[1] - 14, data->ypos[1] - 10, 0xFFFFFF, "END");
	if (data->time != time(NULL) && data->oto == 1)
	{
		ft_play(data);
		data->time = time(NULL);
	}
	return (0);
}

void	ft_init_data(t_data *data)
{
	data->room = 0;
	data->x_extrem= 0;
	data->y_extrem= 0;
	data->time = time(NULL);
	data->oto = 0;
	data->room = 0;
}

int main(int argc, char **argv)
{
	t_data	data;
	t_room	*room;
	t_ant	*ant;

	(void)argv;
	ft_init_data(&data);
	if (!(room = ft_init(&data, argc)))
		return (-1);
	if (!(ant = ft_init_ant(&data, room)))
		return (-1);
	data.ant = ant;
	data.room2 = room;
	if (argc > 1)
	{
		ft_shell_visu(&data, room, ant);
		exit(0);
	}
	mlx_key_hook(data.win, deal_key, &data);
	mlx_loop_hook(data.mlx, auto_play, &data);
	mlx_loop(data.mlx);
	return 0;
}
