/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecerri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 23:14:53 by fbecerri          #+#    #+#             */
/*   Updated: 2019/02/08 23:46:13 by fbecerri         ###   ########.fr       */
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

void	ft_init_sqare(t_data *data, t_room *room)
{
	int x;
	int y;
	int zm;
	int zm2;
	int i;

	y = 0;
	while (y < SCREEN_Y / (data->room* SIZE))
	{
		x = 0;
		while (x < SCREEN_X / (data->room * SIZE))
		{
			data->img_ptr[y * (SCREEN_X / (data->room * SIZE)) + x] = 0xFF0000;
			data->img_ptr2[y * (SCREEN_X / (data->room * SIZE)) + x] = 0x00FF00;
			data->img_ptr3[y * (SCREEN_X / (data->room * SIZE)) + x] = 0x0000FF;
			x++;
		}
		y++;
	}
	i = 0;
	zm = SCREEN_X / (data->x_extrem + 5);
	zm2 = SCREEN_X / (data->y_extrem + 5);

	while (i < data->room)
	{
		x = zm + room[i].x * zm;
		y = zm2 + room[i].y * zm2;
		printf ("room[%d] x= %d y= %d\n", i, x, y);
		if (room[i].start_end == 0)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->img, x, y);
			mlx_string_put(data->mlx, data->win, x, y, 0xFFFFFF, room[i].name);
		}
		else
		{
			mlx_put_image_to_window(data->mlx, data->win, data->img3, x, y);
			mlx_string_put(data->mlx, data->win, x, y, 0xFFFFFF, room[i].name);
		}
		i++;
	}
	printf ("i = %d\n", i);
}

int	ft_init(t_data *data)
{
	int k;
	t_room *room;

	k = -1;
	if (!(data->map = ft_read()))
		return (-1);
	//	while (data->map[++k])
	//		printf("map = %s\n", data->map[k]);
	if (!(room =ft_init_complete(data)))
		return (-1);
	if (!(data->mlx = mlx_init()))
		return (-1);
	if (!(data->win = mlx_new_window(data->mlx, SCREEN_X, SCREEN_Y, "Visu lem_in fbecerri prastoin")))
		return (-1);
	mlx_key_hook(data->win, deal_key, data);
	data->zm = SCREEN_X / (data->x_extrem + 5);
	data->zm2 = SCREEN_X / (data->y_extrem + 5);
	data->img = mlx_new_image(data->mlx, SCREEN_X / (data->room * SIZE), SCREEN_X / (data->room * SIZE));
	data->img_ptr = (int *)mlx_get_data_addr(data->img, &k, &k, &k);
	data->img2 = mlx_new_image(data->mlx, SCREEN_X / (data->room * SIZE), SCREEN_X / (data->room * SIZE));
	data->img_ptr2 = (int *)mlx_get_data_addr(data->img2, &k, &k, &k);
	data->img3 = mlx_new_image(data->mlx, SCREEN_X / (data->room * SIZE), SCREEN_X / (data->room * SIZE));
	data->img_ptr3 = (int *)mlx_get_data_addr(data->img3, &k, &k, &k);
	data->img4 = mlx_new_image(data->mlx, SCREEN_X, SCREEN_Y);
	data->img_ptr4 = (int *)mlx_get_data_addr(data->img4, &k, &k, &k);
	ft_init_join(data, room);
	ft_init_sqare(data, room);
	mlx_loop(data->mlx);
	return (0);
}

