/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:32:37 by agautier          #+#    #+#             */
/*   Updated: 2022/02/12 19:02:39 by agautier         ###   ########.fr       */
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

	fd = STDIN_FILENO;
	if (argc > 2)
	{
		ft_putendl_fd(STDERR_FILENO, "Usage: ./alcu [path_to_map.map]");
		return (EXIT_FAILURE);
	}
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	if (fill_board(fd, &board))
		return (EXIT_FAILURE);

	board_print(board);
	while (board)
	{
		ai_plays(&board);
		if (!board)
		{
			ft_putendl_fd(STDOUT_FILENO, "You are the winner! Congratulations! :)");
			break ;
		}
		board_print(board);
		player_plays(&board);
		if (!board)
		{
			ft_putendl_fd(STDOUT_FILENO, "You lost! :(");
			break ;
		}
		board_print(board);
	}

	list_clear(&board);
	return (EXIT_SUCCESS);
}
