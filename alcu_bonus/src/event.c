/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:07:13 by agautier          #+#    #+#             */
/*   Updated: 2022/02/13 00:25:30 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int play(t_graph *graph, int x_baton, int y_baton)
{
	static int	play = 1;

	printf("on est ici\n");
	if (play)
	{
		play = 0;
		while (graph->board)
		{
			ai_plays(&(graph->board));
			if (!(graph->board))
			{
				ft_putendl_fd(STDOUT_FILENO, "You are the winner! Congratulations! :)");
				return (1);
			}
			board_print(graph->board, graph, x_baton, y_baton);
			player_plays(graph);
			if (!(graph->board))
			{
				ft_putendl_fd(STDOUT_FILENO, "You lost! :(");
				return (1);
			}
			board_print(graph->board, graph, x_baton, y_baton);
		}
	}
	return (0);
}
