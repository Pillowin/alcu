/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:32:37 by agautier          #+#    #+#             */
/*   Updated: 2022/02/13 12:58:58 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

static void	play(t_list *board, int fd)
{
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
		player_plays(&board, fd);
		if (!board)
		{
			ft_putendl_fd(STDOUT_FILENO, "You lost! :(");
			break ;
		}
		board_print(board);
	}
	close(fd);
	list_clear(&board);
}

int	main(int argc, char **argv)
{
	t_list	*board;
	int		fd;
	bool	board_fill_failed;

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
	play(board, fd);
	return (EXIT_SUCCESS);
}
