/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 09:23:37 by prastoin          #+#    #+#             */
/*   Updated: 2019/02/08 21:40:48 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

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

	str = ft_reading();
	if (!(map = ft_strsplit(str, '\n')))
		return (NULL);
	return (map);
}

int		ft_nbr_c(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}


int		ft_len_to_c(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}


void	ft_print_struct(t_room *room, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		printf("ROOM[%d]\n", i);
		printf("Name =%s\n", room[i].name);
		printf("Start_end =%d\n", room[i].start_end);
		printf("x = %d y = %d\n", room[i].x, room[i].y);
		printf("\n");
		i++;
	}
}

int		ft_index_for(char *str, t_room *room, int nbrroom)
{
	int		a;
	int		len;
	int		lenstr;

	lenstr = ft_strlen(str);
	len = 0;
	a = 0;
	while (a < nbrroom)
	{
		len = ft_strlen(room[a].name);
		if (len == lenstr)
			if (ft_strncmp(room[a].name, str, lenstr) == 0)
				return(a);
		a++;
	}
	free(str);
	return (-1);
}

int		ft_init_img(t_room *room, t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	data->img = mlx_new_image(data->mlx, IMG_X, IMG_Y);
	data->img_ptr = (int *)mlx_get_data_addr(data->img, &i, &i, &i);
	while (y < 20)
	{
		x = 0;
		while (x < 20)
		{
			data->img_ptr[y * IMG_X + x] = 0xFFFFFF;
			x++;
		}
		y++;
	}
	while (i < data->nbroom)
	{
		room[i].img = data->img;
		room[i].img_ptr = data->img_ptr;
		i++;
	}
	return (0);
}

int		deal_key(int key, t_data *data)
{
	printf("%d\n", key);
	if (key == KEY_ESC)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

/*int		mouse_hook(int button, int x, int y, t_data *data)
{
	return (0);
}*/

int		ft_load(t_data *data)
{
	mlx_key_hook(data->win, deal_key, data);
//	mlx_mouse_hook(data->win, mouse_hook, data);
	return (0);
}

int		ft_first_render(t_room *room, t_data *data)
{
	int	y;
	int	x;
	int	i;

	i = 0;
	x = 0;
	y = 0;
	while (i < data->nbroom)
	{
		mlx_put_image_to_window(data->mlx, data->win, room[i].img, room[i].y * 10, room[i].x * 10);
		mlx_string_put(data->mlx, data->win, room[i].y * 10, room[i].x * 10, 0xFF0000, room[i].name);
		i++;
	}
	return (0);
}

int main(void)
{
	t_data	data;
	t_room	*room;

	if ((ft_init(&data) == -1))
		return (-1);
	room = ft_init_room(&data);
//	ft_init_room_links(room, &data); non utile car plus smart
	ft_print_struct(room, data.nbroom);
	ft_init_img(room, &data);
	ft_first_render(room, &data);
	ft_load(&data);
	mlx_loop(data.mlx);
	return (0);
}
