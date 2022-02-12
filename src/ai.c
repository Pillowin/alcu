/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:46:12 by agautier          #+#    #+#             */
/*   Updated: 2022/02/12 15:48:07 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include <stdbool.h>

static int find_play(int item_count, bool must_not_take_last)
{
	int must_take;

	must_take = item_count % 4 - must_not_take_last;
	if (must_take == 0)	// i lost :(
	{
		//	fprintf(stderr, "AI: i think i lost\n");
		must_take = 1;
	}
	else if (must_take == -1)
		must_take = 3;
	return (must_take);
}

static bool analyze_heap(int item_count, bool must_not_take_last)
{
	bool should_not_start;
	
	if (item_count % 4 - must_not_take_last == 0)
		should_not_start = true;
	else
		should_not_start = false;
	return (should_not_start);
}

void ai_plays(t_list **board)
{
	t_list *heap;
	bool must_not_take_last;
	int took;

	heap = *board;
	must_not_take_last = true;
	while (heap)
	{
		must_not_take_last = analyze_heap(heap->nbr, must_not_take_last);
		heap = heap->next;
	}
	fprintf(stderr, "must_take_last = %s\n", (!must_not_take_last ? "true" : "false"));
	heap = list_last(*board);
	took = find_play(heap->nbr, must_not_take_last);
	heap->nbr -= took;

	ft_putstr_fd(STDOUT_FILENO, "AI took ");
	ft_putnbr(took);
	ft_putendl_fd(STDOUT_FILENO, "");

	if (heap->nbr <= 0)
		list_pop_back(board);
}

