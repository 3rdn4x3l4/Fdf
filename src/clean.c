/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:06:53 by plagache          #+#    #+#             */
/*   Updated: 2019/11/04 12:49:08 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	clean_list(t_list *head)
{
	if (head != NULL)
	{
		clean_list(head->next);
		free(head->content);
		free(head);
	}
}

void	clean_board(t_map *map)
{
	int c;

	c = 0;
	while (map->board[c] != NULL)
	{
		free(map->board[c]);
		c++;
	}
	free(map->board);
}

void	clean_tab(t_map *map)
{
	free(map->tab);
	free(map->tab_p);
}
