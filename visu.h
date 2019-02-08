/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 09:24:57 by prastoin          #+#    #+#             */
/*   Updated: 2019/02/08 21:33:39 by prastoin         ###   ########.fr       */
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

# define KEY_ESC 53
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

# define IMG_X 20
# define IMG_Y 20
typedef struct		s_data
{
	void	*mlx;
	void	*win;
	void	*ximg;
	void	*img;
	int		*img_ptr;

	char	**map;

	int		nbroom;
	int		first_room;
	int		first_link;
	int		nbfourmis;
	int		start;
	int		end;
	int		end_map;
}					t_data;

typedef struct		s_room
{
	char	*name;
	int		x;
	int		y;
	int		start_end;
	int		slot;
	int		*img_ptr;
	void	*img;
	int		links;
	int		index[100];
}					t_room;

/*int					ft_error(int i, t_data *fdf);
int					gradient(int a, int b, float percent);
void				ft_tracertrait_cut(t_data *fdf, int x, int y, int dz);
void				ft_quit(t_data *fdf);
int					get_z_max(t_data *fdf);
int					parser(t_data *fdf, int i);
int					data(t_data *fdf);
int					algo(t_data *fdf, int x, int y);*/
//init
int		ft_init_complete(t_data *data);
int	ft_init(t_data *data);
t_room	*ft_init_room(t_data *data);
int		ft_init_room_links(t_room *room, t_data *data);

//tools
int		ft_nbr_c(char *str, char c);
int		ft_len_to_c(char *str, char c);
int		ft_index_for(char *str, t_room *room, int nbrroom);
char		**ft_read(void);

#endif
