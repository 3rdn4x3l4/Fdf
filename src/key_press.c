/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:51:45 by plagache          #+#    #+#             */
/*   Updated: 2019/11/05 16:21:12 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	key_press_s(int keycode, t_mlx *mlx)
{
	if (keycode == PLUS)
	{
		mlx->sigma += 1;
		if (mlx->sigma > 360)
			mlx->sigma = 0;
		draw_x(mlx, mlx->map);
		return (0);
	}
	if (keycode == MINUS)
	{
		mlx->sigma -= 1;
		if (mlx->sigma < 0)
			mlx->sigma = 360;
		draw_x(mlx, mlx->map);
		return (0);
	}
	return (0);
}

static int	key_press_f(int keycode, t_mlx *mlx)
{
	if (keycode == RIGHT)
	{
		mlx->alpha += 1;
		if (mlx->alpha > 360)
			mlx->alpha = 0;
		draw_x(mlx, mlx->map);
		return (0);
	}
	if (keycode == LEFT)
	{
		mlx->alpha -= 1;
		if (mlx->alpha < 0)
			mlx->alpha = 360;
		draw_x(mlx, mlx->map);
		return (0);
	}
	if (key_press_s(keycode, mlx) == 0)
		return (0);
	return (0);
}

int			key_press(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (keycode == ECHAP)
		exit(0);
	if (keycode == UP)
	{
		if (++mlx->delta > 360)
			mlx->delta = 0;
		draw_x(mlx, mlx->map);
		return (0);
	}
	if (keycode == DOWN)
	{
		if (--mlx->delta < 0)
			mlx->delta = 360;
		draw_x(mlx, mlx->map);
		return (0);
	}
	if (key_press_f(keycode, mlx) == 0)
		return (0);
	return (0);
}
