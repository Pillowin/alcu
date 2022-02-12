/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:00:39 by agautier          #+#    #+#             */
/*   Updated: 2022/02/12 19:26:35 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void board_print(t_list *board)
{
	int items;

	ft_putendl_fd(STDOUT_FILENO, "");
	while (board)
	{
		items = board->nbr;
		if (items)
			ft_putstr_fd(STDOUT_FILENO, " ");
		while (items)
		{
			ft_putstr_fd(STDOUT_FILENO, "| ");
			items -= 1;
		}
		ft_putendl_fd(STDOUT_FILENO, "");
		ft_putendl_fd(STDOUT_FILENO, "");
		board = board->next;
	}
}
