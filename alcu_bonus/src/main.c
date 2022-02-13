/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:32:37 by agautier          #+#    #+#             */
/*   Updated: 2022/02/13 17:14:40 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

static void	play(t_graph *graph)
{
	int	x_baton;
	int	y_baton;

	graph->max = list_max(graph->board);
	x_baton = (WIDTH * 0.9) / (graph->max * 2 - 1);
	y_baton = (HEIGTH * 0.9) / ft_lstsize(graph->board);
	board_print(graph->board, graph, x_baton, y_baton);
	usleep(AI_WAIT_TIME);
	while (graph->board)
	{
		ai_plays(&(graph->board));
		if (!(graph->board))
		{
			ft_putendl_fd(STDOUT_FILENO,
					"You are the winner! Congratulations! :)");
			break ;
		}
		board_print(graph->board, graph, x_baton, y_baton);
		player_plays(graph);
		if (!(graph->board))
		{
			ft_putendl_fd(STDOUT_FILENO, "You lost! :(");
			break ;
		}
		board_print(graph->board, graph, x_baton, y_baton);
		usleep(AI_WAIT_TIME);
	}
	close(graph->fd);
	list_clear(&(graph->board));
	free_graph(graph);
}

int main(int argc, char **argv)
{
	t_list	*board;
	t_graph	*graph;
	bool	board_fill_failed;
	int		fd;

	if (argc > 2)
	{
		ft_putendl_fd(STDERR_FILENO, "Usage: ./alcu [path_to_map.map]");
		return (EXIT_FAILURE);
	}
	fd = STDIN_FILENO;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	board_fill_failed = board_fill(fd, &board);
	if (fd != STDIN_FILENO)
		close(fd);
	if (board_fill_failed)
		return (EXIT_FAILURE);
	fd = board_reset_fd(fd);
	if (fd == -1)
	{
		list_clear(&board);
		return (EXIT_FAILURE);
	}
	graph = new_graph(board, fd);
	if (graph == NULL)
	{
		list_clear(&board);
		return (EXIT_FAILURE);
	}
	play(graph);
	return (EXIT_SUCCESS);
}
