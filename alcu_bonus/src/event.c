/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:07:13 by agautier          #+#    #+#             */
/*   Updated: 2022/02/12 23:14:14 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int play(t_graph *graph)
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
				//mlx_loop_end(graph->mlx_ptr);
				return (1);
			}
			//board_print(board, graph);
			player_plays(graph);
			if (!(graph->board))
			{
				ft_putendl_fd(STDOUT_FILENO, "You lost! :(");
				//mlx_loop_end(graph->mlx_ptr);
				return (1);
			}
			//board_print(board, graph);
		}
	}
	return (0);
}