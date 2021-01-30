/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:40:58 by plagache          #+#    #+#             */
/*   Updated: 2019/11/05 19:35:11 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define IMG_WIDTH 1600
# define IMG_HEIGHT 900
# define ECHAP 53
# define UP	126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define PLUS 69
# define MINUS 78

typedef struct	s_double
{
	double		x;
	double		y;
	double		z;
}				t_double;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;
typedef struct	s_map
{
	char		**board;
	t_point		*tab;
	t_point		*tab_p;
	int			x_max;
	int			y_max;
	int			z_max;
	int			scaled;
}				t_map;

typedef struct	s_mlx
{
	void		*init;
	void		*window;
	void		*img_ptr;
	int			*img_data;
	t_map		*map;
	double		delta;
	double		alpha;
	double		sigma;
	int			size_l;
	int			endian;
	int			bpp;
}				t_mlx;

int				read_file(t_map *map, char	*path);
int				key_press(int keycode, void *param);
int				data_trans(t_map *map);
void			rotate(t_map *map, double delta);
void			which_line(int *data, t_point a, t_point b);
void			clean_board(t_map *map);
void			clean_list(t_list *head);
void			clean_tab(t_map *map);
void			rotate_x(t_map *map, double delta);
void			rotate_y(t_map *map, double alpha);
void			rotate_z(t_map *map, double sigma);
void			draw_x(t_mlx *mlx, t_map *map);
int				protect(char *path);
int				test_x_y(char *path);
int				is_map(char *str);

#endif
