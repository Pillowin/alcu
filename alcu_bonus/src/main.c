/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:32:37 by agautier          #+#    #+#             */
/*   Updated: 2022/02/12 21:49:40 by lcalvie          ###   ########.fr       */
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

	if (board)
	{
		x_baton = (WIDTH * 0.9) / (list_max(board) * 2);
		y_baton = (HEIGTH * 0.9) / ft_lstsize(board);
		board_print(board, graph, x_baton, y_baton);
	}
	while (board)
	{
		ai_plays(&board);
		if (!board)
		{
			ft_putendl_fd(STDOUT_FILENO, "You are the winner! Congratulations! :)");
			break ;
		}
		//board_print(board, graph);
		player_plays(&board, fd);
		if (!board)
		{
			ft_putendl_fd(STDOUT_FILENO, "You lost! :(");
			break ;
		}
		//board_print(board, graph);
	}
	close(fd);
	free_graph(graph);
	list_clear(&board);
	return (EXIT_SUCCESS);
}
