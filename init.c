/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 23:14:53 by fbecerri          #+#    #+#             */
/*   Updated: 2019/02/09 02:54:29 by fbecerri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		ft_fill_info(char *str, t_room *room, t_data *data)
{
	int len;

	len = 0;
	while (str[len] != ' ')
		len++;
	room->name =ft_strndup(str, len);
	room->slot = 0;
	room->x = ft_atoi(&(str[len]));
	room->start_end = 0;
	data->x_extrem = room->x > data->x_extrem ? room->x : data->x_extrem;
	//	printf ("%d len =%d\n", room->x, len);
	len += ft_lennbr(room->x);
	//	printf ("%d len =%d\n", room->x, len);
	room->y = ft_atoi(&(str[len + 1]));
	data->y_extrem = room->y > data->y_extrem ? room->y : data->y_extrem;
	return (0);
}

int		ft_fill_room(t_data *data, t_room *room)
{
	int i;
	int cmt;
	int start_end[2];

	i = 0;
	while (data->map[i][0] == '#')
		i++;
	printf ("%s\n", data->map[i]);
	data->fourmis = ft_atoi(data->map[i]);
	i++;
	cmt = 0;
	while (cmt < data->room)
	{
		if (data->map[i][0] != '#')
		{
			ft_fill_info(data->map[i], &room[cmt], data);
			cmt++;
		}
		else
		{
			printf ("commentaire %s\n", data->map[i]);
			if (ft_strcmp("##start", data->map[i]) == 0)
			{
				printf ("cmt = %d\n", cmt);
				start_end[0] = cmt;
			}
			if (ft_strcmp("##end", data->map[i]) == 0)
			{
				start_end[1] = cmt;
				printf ("cmtend = %d\n", cmt);
			}
		}
		i++;
	}
	//	room[start_end[0]].name = ft_strdup("START");
	//	room[start_end[1]].name = ft_strdup("END");
	printf("start_end = %d\n", start_end[0]);
	room[start_end[0]].start_end = 1;
	room[start_end[1]].start_end = 2;
	//	ft_print_struc(room, data->room);

	return (0);
}

t_room	*ft_init_complete(t_data *data)
{
	t_room *room;

	ft_nbr_room(data);
	printf ("%d\n", data->room);
	if (!(room = (t_room*)malloc(sizeof(t_room) * (data->room))))
		return (NULL);
	ft_fill_room(data, room);
	printf("%d\n", data->room);
	return (room);
}

void	ft_circle(int x, int y, int rayon, t_data *data, int color)
{
	int x2;
	int y2;

	y2 = -rayon;
	while (y2 < rayon)
	{
		x2 = -rayon;
		while (x2 < rayon)
		{
			if (((x2 / (double)rayon) * (x2 / (double)rayon) + (y2 / (double)rayon) * (y2 / (double)rayon)) <= 1)
			{
				data->img_ptr2[(y2 + y) * (SCREEN_X) + (x2 + x)] = color;
				data->img_ptr[(y2 + y) * (SCREEN_X) + (x2 + x)] = color;
			}
			x2++;
		}
		y2++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img2, 0, 0);
/*	mlx_pixel_put(data->mlx, data->win, x, y, 0xFFFF00);
	mlx_pixel_put(data->mlx, data->win, x + 1, y, 0xFFFF00);
	mlx_pixel_put(data->mlx, data->win, x - 1, y, 0xFFFF00);
	mlx_pixel_put(data->mlx, data->win, x, y + 1, 0xFFFF00);
	mlx_pixel_put(data->mlx, data->win, x + 1, y + 1, 0xFFFF00);
	mlx_pixel_put(data->mlx, data->win, x - 1, y + 1, 0xFFFF00);
	mlx_pixel_put(data->mlx, data->win, x, y - 1, 0xFFFF00);
	mlx_pixel_put(data->mlx, data->win, x + 1, y - 1, 0xFFFF00);
	mlx_pixel_put(data->mlx, data->win, x - 1, y - 1, 0xFFFF00);*/
}

void	ft_init_sqare(t_data *data, t_room *room)
{
	int x;
	int y;
	int i;

	i = 0;
	while (i < data->room)
	{
		x = data->zm + room[i].x * data->zm;
		y = data->zm2 + room[i].y * data->zm2;
		printf ("room[%d] x= %d y= %d\n", i, x, y);
		if (room[i].start_end == 0)
			ft_circle(x, y, SCREEN_X / (data->room * SIZE * 2), data, 0xFFFFFF);
		else if (room[i].start_end == 1)
			ft_circle(x, y, SCREEN_X / (data->room * SIZE * 2), data, 0x0000FF);
		else
			ft_circle(x, y, SCREEN_X / (data->room * SIZE * 2), data, 0xFF0000);
		i++;
	}
}

t_room			*ft_init(t_data *data)
{
	int k;
	t_room *room;

	k = -1;
	if (!(data->map = ft_read()))
		return (NULL);
	//	while (data->map[++k])
	//		printf("map = %s\n", data->map[k]);
	if (!(room =ft_init_complete(data)))
		return (NULL);
	if (!(data->mlx = mlx_init()))
		return (NULL);
	if (!(data->win = mlx_new_window(data->mlx, SCREEN_X, SCREEN_Y, "Visu lem_in fbecerri prastoin")))
		return (NULL);
	data->zm = SCREEN_X / (data->x_extrem + 5);
	data->zm2 = SCREEN_Y / (data->y_extrem + 5);
	printf("data zm =%d\n", data->zm);
	data->img = mlx_new_image(data->mlx, SCREEN_X, SCREEN_Y);
	data->img_ptr = (int *)mlx_get_data_addr(data->img, &k, &k, &k);
	data->img2 = mlx_new_image(data->mlx, SCREEN_X, SCREEN_Y);
	data->img_ptr2 = (int *)mlx_get_data_addr(data->img2, &k, &k, &k);
	ft_init_join(data, room);
	ft_init_sqare(data, room);
	return (room);
}
