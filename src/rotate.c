/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:30:33 by plagache          #+#    #+#             */
/*   Updated: 2019/11/05 16:54:40 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_z(t_map *map, double sigma)
{
	int			c;
	t_double	iso;

	c = 0;
	sigma = (M_PI * sigma) / 180;
	while (c < map->x_max * map->y_max)
	{
		iso.x = (map->tab_p[c].x * cos(sigma))
			+ (map->tab_p[c].y * -sin(sigma)) + (map->tab_p[c].z * 0);
		iso.y = (map->tab_p[c].x * sin(sigma)) + (map->tab_p[c].y * cos(sigma))
			+ (map->tab_p[c].z * 0);
		iso.z = (map->tab_p[c].x * 0) + (map->tab_p[c].y * 0)
			+ (map->tab_p[c].z * 1);
		map->tab_p[c].x = iso.x;
		map->tab_p[c].y = iso.y;
		c++;
	}
}

void	rotate_y(t_map *map, double alpha)
{
	int			c;
	t_double	iso;

	c = 0;
	alpha = (M_PI * alpha) / 180;
	while (c < map->x_max * map->y_max)
	{
		iso.x = (map->tab_p[c].x * cos(alpha)) + (map->tab_p[c].y * 0)
			+ (map->tab_p[c].z * sin(alpha));
		iso.y = (map->tab_p[c].x * 0) + (map->tab_p[c].y * 1)
			+ (map->tab_p[c].z * 0);
		iso.z = (map->tab_p[c].x * -sin(alpha)) + (map->tab_p[c].y * 0)
			+ (map->tab_p[c].z * cos(alpha));
		map->tab_p[c].x = iso.x;
		map->tab_p[c].y = iso.y;
		c++;
	}
}

void	rotate_x(t_map *map, double delta)
{
	int			c;
	t_double	iso;

	c = 0;
	delta = (M_PI * delta) / 180;
	while (c < map->x_max * map->y_max)
	{
		iso.x = (map->tab[c].x * 1) + (map->tab[c].y * 0)
			+ (map->tab[c].z * 0);
		iso.y = (map->tab[c].x * 0) + (map->tab[c].y * cos(delta))
			+ (map->tab[c].z * -sin(delta));
		iso.z = (map->tab[c].x * 0) + (map->tab[c].y * sin(delta))
			+ (map->tab[c].z * cos(delta));
		map->tab_p[c].x = iso.x * 2;
		map->tab_p[c].y = iso.y * 2;
		c++;
	}
}
