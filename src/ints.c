/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ints.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:49:35 by plagache          #+#    #+#             */
/*   Updated: 2019/11/05 19:18:00 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	count_ints(char *str)
{
	int c;
	int count;

	c = 0;
	count = 0;
	while (str[c])
	{
		while (str[c] && (str[c] == ' ' || str[c] == '-'))
			c++;
		while (str[c] && (ft_isdigit(str[c]) == 1))
			c++;
		count++;
	}
	return (count);
}

static int	loop_count_int(int fd)
{
	int		ret;
	int		count;
	int		countt;
	char	*line;

	if ((ret = get_next_line(fd, &line)) > 0)
	{
		countt = count_ints(line);
		free(line);
	}
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		count = count_ints(line);
		free(line);
		if (countt != count)
			return (-1);
	}
	free(line);
	return (0);
}

int			test_x_y(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (loop_count_int(fd) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}
