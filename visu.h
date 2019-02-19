/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 09:24:57 by prastoin          #+#    #+#             */
/*   Updated: 2019/02/19 03:10:16 by fbecerri         ###   ########.fr       */
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
#include <time.h>

#include <stdio.h>

# define SIZE 2
# define BUFF_SIZE 4096
# define KEY_LESS 78
# define KEY_ESC 53
# define KEY_CTRL 256
# define KEY_PLUS 69
# define KEY_UP 125
# define KEY_DOWN 126
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_SPACE 49
# define KEY_NUM6 88
# define KEY_NUM3 85
# define SCREEN_X 1000
# define SCREEN_Y 1000

typedef struct		s_ant
{
	int		curr;
	int		previous;
	int		coup;
	int		i;
}					t_ant;

typedef struct		s_room
{
	char	*name;
	int		x;
	int		y;
	int		start_end;
	int		slot;
	int		*index;
}					t_room;

typedef struct		s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*img_ptr;
	void	*img2;
	int		*img_ptr2;

	int		i;
	char	**map;
	int		room;
	int		step1;
	int		x_extrem;
	int		y_extrem;
	int		xstart;
	int		ystart;
	int		index_start;
	int		index_end;
	int		zm;
	int		zm2;
	int		fourmis;
	t_room	*room2;
	t_ant	*ant;
	int		oto;
	time_t  time;
	int		xpos[2];
	int		ypos[2];

	int		x_max;
	int		y_max;
	char	**jeu;
	int		*len;
}					t_data;

int		ft_shell_visu(t_data *data, t_room *room, t_ant *ant);
void	ft_circle(int x, int y, int rayon, t_data *data, int color);
int		ft_fill_info(char *str, t_room *room, t_data *data);
int		ft_fill_room(t_data *data, t_room *room, int i);
t_room	*ft_init_complete(t_data *data);
void	ft_init_sqare(t_data *data, t_room *room);
t_room	*ft_init(t_data *data, int argc);
int		ft_index_for(char *str, t_room *room, int nbrroom);
int		ft_len_to_c(char *str, char c);
void	ft_print_struc(t_room *room, int nbroom);
int ft_nbr_room(t_data *data);
char		**ft_read(void);
int	deal_key(int key, t_data *data);
void	ft_init_join(t_data *data, t_room *room);
int			nbr_space(char *str, char c);
int			ft_inv_play(t_data *data);
int			ft_play(t_data *data);
t_ant	*ft_init_ant(t_data *data, t_room *room);
int		ft_index_for_links(char *str, t_room *room, int nbrroom, int len);

#endif
