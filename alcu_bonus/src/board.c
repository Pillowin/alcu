/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:00:39 by agautier          #+#    #+#             */
/*   Updated: 2022/02/13 00:02:23 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include <stdio.h>

void board_print(t_list *board, t_graph *graph, int x_baton, int y_baton)
{
	int items;
	int longest_line;
	int i;
	int j;
	int x_corner, y_corner;
	int x_decalage;

	longest_line = list_max(board);
	i = 0;
	while (board)
	{
		y_corner = i * y_baton  + 0.05 * y_baton + HEIGTH * 0.05;
		items = board->nbr;
		j = 0;
		x_decalage = x_baton * (longest_line - items);
		while (j < items)
		{
			x_corner = 2 * j * x_baton + 0.55 * x_baton + WIDTH * 0.05 + x_decalage;
			draw_rectangle(graph, x_corner, y_corner, x_baton * 0.9, y_baton * 0.9);
			j++;
		}
		i++;
		board = board->next;
	}
	fprintf(stderr, "put img %d\n",
	mlx_put_image_to_window(graph->mlx_ptr, graph->win_ptr, graph->img.id, 0, 0));
	img_clear(graph);
}
