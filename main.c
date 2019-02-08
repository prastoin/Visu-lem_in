/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 09:23:37 by prastoin          #+#    #+#             */
/*   Updated: 2019/02/07 10:16:48 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

char *		ft_reading(void)
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

int		ft_init_complete(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	
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

int main(void)
{
	t_data	data;
	if ((ft_init(&data) == -1))
			return (-1);
	return 0;
}
