/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 09:24:57 by prastoin          #+#    #+#             */
/*   Updated: 2019/02/07 09:52:37 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft/libft.h"

#include <stdio.h>

# define BUFF_SIZE 4096
# define KEY_LESS 78
# define KEY_CTRL 256
# define KEY_PLUS 69
# define KEY_UP 125
# define KEY_DOWN 126
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_SPACE 53
# define KEY_NUM6 88
# define KEY_NUM3 85
# define SCREEN_X 1000
# define SCREEN_Y 1000

typedef struct		s_data
{
	void	*mlx;
	void	*win;
	void	*ximg;
	void	*img;
	int		*img_ptr;

	char	**map;
	int		nbroom;
	int		step1;
}					t_data;

typedef struct		s_room
{
	char	*name;
	int		x;
	int		y;
	int		slot;
}					t_room;

/*int					ft_error(int i, t_data *fdf);
int					gradient(int a, int b, float percent);
void				ft_tracertrait_cut(t_data *fdf, int x, int y, int dz);
void				ft_quit(t_data *fdf);
int					get_z_max(t_data *fdf);
int					parser(t_data *fdf, int i);
int					data(t_data *fdf);
int					algo(t_data *fdf, int x, int y);*/

#endif
