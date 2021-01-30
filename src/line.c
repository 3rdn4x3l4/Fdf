/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:00:52 by plagache          #+#    #+#             */
/*   Updated: 2019/11/05 16:21:46 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	*draw_line_low(int *data, t_point a, t_point b)
{
	t_point	diff;
	int		d;
	int		y;
	int		yi;

	diff.x = b.x - a.x;
	diff.y = b.y - a.y;
	yi = (diff.y < 0) ? -1 : 1;
	diff.y = abs(diff.y);
	d = 2 * diff.y - diff.x;
	y = a.y;
	while (a.x <= b.x)
	{
		if ((y * IMG_WIDTH + a.x) >= 0
				&& (y * IMG_WIDTH + a.x) < IMG_WIDTH * IMG_HEIGHT)
			data[y * IMG_WIDTH + a.x] = 0x00FFFFFF;
		if (d > 0)
		{
			y = y + yi;
			d = d - 2 * diff.x;
		}
		d = d + 2 * diff.y;
		a.x++;
	}
	return (data);
}

static int	*draw_line_high(int *data, t_point a, t_point b)
{
	t_point	diff;
	int		d;
	int		x;
	int		xi;

	diff.x = b.x - a.x;
	diff.y = b.y - a.y;
	xi = (diff.x < 0) ? -1 : 1;
	diff.x = abs(diff.x);
	d = 2 * diff.x - diff.y;
	x = a.x;
	while (a.y <= b.y)
	{
		if (((a.y * IMG_WIDTH + x) >= 0)
				&& (a.y * IMG_WIDTH + x) < IMG_WIDTH * IMG_HEIGHT)
			data[a.y * IMG_WIDTH + x] = 0x00FFFFFF;
		if (d > 0)
		{
			x = x + xi;
			d = d - 2 * diff.y;
		}
		d = d + 2 * diff.x;
		a.y++;
	}
	return (data);
}

void		which_line(int *data, t_point a, t_point b)
{
	if (abs(b.y - a.y) < abs(b.x - a.x))
	{
		if (a.x > b.x)
		{
			draw_line_low(data, b, a);
		}
		else
		{
			draw_line_low(data, a, b);
		}
	}
	else
	{
		if (a.y > b.y)
		{
			draw_line_high(data, b, a);
		}
		else
		{
			draw_line_high(data, a, b);
		}
	}
}
