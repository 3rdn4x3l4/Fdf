/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:51:26 by plagache          #+#    #+#             */
/*   Updated: 2019/11/05 17:38:54 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	get_mlx(t_mlx *mlx, t_map *map)
{
	mlx->init = mlx_init();
	mlx->window = mlx_new_window(mlx->init, WIN_WIDTH, WIN_HEIGHT, "fdf");
	mlx->map = map;
	mlx->delta = 0;
	mlx->alpha = 0;
	mlx->sigma = 0;
	mlx_hook(mlx->window, 2, 0, &key_press, mlx);
}

static void	center_tab(t_map *map)
{
	int c;

	c = 0;
	while (c < map->x_max * map->y_max)
	{
		map->tab[c].x -= map->x_max / 2;
		map->tab[c].y -= map->y_max / 2;
		c++;
	}
}

int			main(int ac, char **av)
{
	t_mlx	mlx;
	t_map	map;

	if (ac != 2)
	{
		ft_putendl("usage : ./fdf path/to/map.fdf");
		return (-1);
	}
	if (protect(av[1]) == -1 || read_file(&map, av[1]) == -1)
	{
		write(2, "error\n", 6);
		return (-1);
	}
	get_mlx(&mlx, &map);
	center_tab(&map);
	draw_x(&mlx, &map);
	mlx_loop(mlx.init);
	clean_tab(&map);
	return (0);
}
