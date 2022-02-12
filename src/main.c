/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:32:37 by agautier          #+#    #+#             */
/*   Updated: 2022/02/12 18:02:38 by lcalvie          ###   ########.fr       */
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
	if (fill_board(fd, &board) | (fd != STDIN_FILENO ))
		return (EXIT_FAILURE);
	char *line = get_next_line(0);
	(void) line;
	return 1;
	//t_list *heap = board;
	//while (heap)
	//{
	//	ft_putnbr(heap->nbr);
	//	ft_putendl_fd(STDOUT_FILENO, "");
	//	fprintf(stderr, "game starts\n");
	//	while (heap->nbr > 1)
	//	{
	//		int play = find_play(heap->nbr);
	//		fprintf(stderr, "AI takes %d item\n", play);

	//		heap->nbr -= play;
	//		if (heap->nbr == 0)
	//		{
	//			fprintf(stderr, "AI LOST !!! :(\n");
	//			break ;
	//		}


	//		fprintf(stderr, "player takes 1\n");
	//		heap->nbr -= 1; // this is player whos playing
	//		if (heap->nbr == 0)
	//		{
	//			fprintf(stderr, "PLAYER LOST !!! :(\n");
	//			break ;
	//		}

	//		fprintf(stderr, "%d item remaining\n", heap->nbr);
	//	}
	//	heap = heap->next;
	//}

	/*
	fprintf(stderr, "-------\n");
	t_list *heap = board;
	while (heap)
	{
		fprintf(stderr, "nbr = %d\tprev=%p\tnext=%p\n", heap->nbr, heap->prev, heap->next);
		heap = heap->next;
	}
	list_pop_back(&board);
	fprintf(stderr, "-------\n");
	heap = board;
	while (heap)
	{
		fprintf(stderr, "nbr = %d\tprev=%p\tnext=%p\n", heap->nbr, heap->prev, heap->next);
		heap = heap->next;
	}
	fprintf(stderr, "-------\n");
	if (list_last(board))
		fprintf(stderr, "last nbr = %d\n", list_last(board)->nbr);
	else
		fprintf(stderr, "list is empty");
	*/

	board_print(board);
	while (board)	// main loop
	{
		ai_plays(&board); // AI plays
		if (!board)
		{
			ft_putendl_fd(STDOUT_FILENO, "You are the winner! Congratulations! :)");
			break ;
		}
		board_print(board);
		player_plays(&board); // Player plays
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
