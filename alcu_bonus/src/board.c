/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:00:39 by agautier          #+#    #+#             */
/*   Updated: 2022/02/12 19:42:16 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

static void print_spaces(int nb)
{
	while (nb)
	{
		write(STDOUT_FILENO, " ", 1);
		nb -= 1;
	}
}

void board_print(t_list *board)
{
	int items;
	int longest_line;

	ft_putendl_fd(STDOUT_FILENO, "");
	longest_line = list_max(board);
	while (board)
	{
		items = board->nbr;
		if (items)
			ft_putstr_fd(STDOUT_FILENO, " ");
		print_spaces(longest_line - items);
		while (items)
		{
			ft_putstr_fd(STDOUT_FILENO, "| ");
			items -= 1;
		}
		ft_putendl_fd(STDOUT_FILENO, "\n");
		board = board->next;
	}
}
