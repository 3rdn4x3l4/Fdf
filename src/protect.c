/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:40:12 by plagache          #+#    #+#             */
/*   Updated: 2019/11/05 19:45:23 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	check_ints(char *line)
{
	int	c;

	c = 0;
	while (line[c] && c < 6 && ft_isdigit(line[c]) == 1)
		c++;
	if (c == 6)
		return (-1);
	return (c);
}

static int	loop_ints(int fd)
{
	int		ret;
	int		c;
	char	*line;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		c = 0;
		while (line[c])
		{
			while (line[c] && (line[c] == ' ' || line[c] == '-'))
				c++;
			ret = 0;
			if (ft_isdigit(line[c]) == 1 && (ret = check_ints(line + c)) == -1)
			{
				free(line);
				return (-1);
			}
			c += ret;
		}
		free(line);
	}
	free(line);
	return (0);
}

static int	is_correct(char *line, int len)
{
	int c;

	c = 0;
	while (c < len)
	{
		if (ft_isdigit(line[c]) != 1 && line[c] != ' ' && line[c] != '-'
				&& line[c] != '\n')
			return (0);
		c++;
	}
	return (1);
}

static int	first_read(int fd)
{
	char	buff[101];
	int		ret;

	while ((ret = read(fd, buff, 100)) > 0)
	{
		buff[ret] = '\0';
		if (is_correct(buff, ret) == 0)
			return (-1);
	}
	return (0);
}

int			protect(char *path)
{
	int		fd;

	if (ft_strnstr(path, "/dev", 4)
			|| ft_strstr(path + ft_strlen(path) - 4, ".fdf") == NULL)
		return (-1);
	fd = open(path, O_RDONLY);
	if (fd < 0 || first_read(fd) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	fd = open(path, O_RDONLY);
	if (loop_ints(fd) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	if (test_x_y(path) == -1)
		return (-1);
	return (0);
}
