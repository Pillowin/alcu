/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:00:39 by agautier          #+#    #+#             */
/*   Updated: 2022/02/12 21:47:44 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void board_print(t_list *board, t_graph *graph, int x_baton, int y_baton)
{
	int items;
	int longest_line;
	int i;
	int j;
	int x_corner, y_corner;

	longest_line = list_max(board);
	i = 0;
	while (board)
	{
		y_corner = i * y_baton  + 0.05 * y_baton;
		items = board->nbr;
		j = 0;
		while (j < items)
		{
			x_corner = 2 * j * x_baton + 1.05 * x_baton;
			draw_rectangle(graph, x_corner, y_corner, x_baton * 0.9, y_baton * 0.9);
			j++;
		}
		i++;
		board = board->next;
	}
}
