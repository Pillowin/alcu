/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:32:37 by agautier          #+#    #+#             */
/*   Updated: 2022/02/13 00:25:17 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

int main(int argc, char **argv)
{
	t_list *board;
	int fd;
	t_graph	*graph;
	int x_baton;
	int y_baton;

	fd = STDIN_FILENO;
	if (argc > 2)
	{
		ft_putendl_fd(STDERR_FILENO, "Usage: ./alcu [path_to_map.map]");
		return (EXIT_FAILURE);
	}
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	if (fill_board(fd, &board))
	{
		if (fd != STDIN_FILENO)
			close(fd);
		return (EXIT_FAILURE);
	}
	if (fd != STDIN_FILENO)
		close(fd);

	fd = open("/dev/tty", O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd(STDERR_FILENO, "Open failed");
		list_clear(&board);
		return (EXIT_FAILURE);
	}

	graph = new_graph();
	if (graph == NULL)
	{
		list_clear(&board);
		return (EXIT_FAILURE);
	}
	graph->board = board;
	graph->fd = fd;
	if (board)
	{
		x_baton = (WIDTH * 0.9) / (list_max(board) * 2);
		y_baton = (HEIGTH * 0.9) / ft_lstsize(board);
		board_print(board, graph, x_baton, y_baton);
		play(graph, x_baton, y_baton);
	}
	if (fd != -1)
		close(fd);
	board = graph->board;
	list_clear(&board);
	free_graph(graph);
	return (EXIT_SUCCESS);
}
