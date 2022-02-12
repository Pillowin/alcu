/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:46:12 by agautier          #+#    #+#             */
/*   Updated: 2022/02/12 16:59:03 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include <stdbool.h>
#include <stdlib.h>	// TODO: remove

static int find_winning_play(int item_count, bool must_take_last)
{
	int must_take;

	fprintf(stderr, "must_take_last = %s\n", must_take_last ? "true" : "false");
	if (!must_take_last)
	{
		must_take = item_count % 4 - 1;
		if (must_take == 0)	// i lost :(
			must_take = 1;
		else if (must_take == -1)
			must_take = 3;
	}
	else
	{
		must_take = item_count % 4;
		if (must_take == 0)	// i lost :(
			must_take = 1;
		else if (must_take == -1)
			must_take = 3;
	}
	return (must_take);
}

static bool analyze_heap(int item_count, bool must_take_last)
{
	bool should_start;

	if (!must_take_last)
	{
		if (item_count % 4 - 1 == 0)
			should_start = false;
		else
			should_start = true;
	}
	else
	{
		if (item_count % 4 - 0 == 0)
			should_start = false;
		else
			should_start = true;
	}

	must_take_last = !should_start;
	return (must_take_last);
}

void ai_plays(t_list **board)
{
	t_list *heap;
	bool must_take_last;
	int took;

	heap = *board;
	must_take_last = false;
	while (heap->next)
	{
		must_take_last = analyze_heap(heap->nbr, must_take_last);
		heap = heap->next;
	}
	took = find_winning_play(heap->nbr, must_take_last);
	heap->nbr -= took;

	ft_putstr_fd(STDOUT_FILENO, "AI took ");
	ft_putnbr(took);
	ft_putendl_fd(STDOUT_FILENO, "");

	if (heap->nbr <= 0)
		list_pop_back(board);
	exit(EXIT_FAILURE);
}

