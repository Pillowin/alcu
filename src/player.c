/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:16:59 by agautier          #+#    #+#             */
/*   Updated: 2022/02/12 12:55:14 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void player_plays(t_list **board)
{
	t_list *heap;
	int took;

	heap = list_last(*board);
	took = 1; // TODO: ask for player move

	ft_putendl_fd(STDOUT_FILENO, "Please choose between 1 and 3 items");
	ft_putnbr(took);
	ft_putendl_fd(STDOUT_FILENO, "");

	heap->nbr -= took;
	if (heap->nbr <= 0)
		list_pop_back(board);
}
