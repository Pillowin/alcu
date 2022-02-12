/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:04:50 by agautier          #+#    #+#             */
/*   Updated: 2022/02/12 12:48:52 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include <stdlib.h>

void list_push_back(t_list **list, int nbr)
{
	t_list *node;
	t_list *curr;

	node = malloc(sizeof(*node) * 1);
	if (node == NULL)
	{
		ft_putendl_fd(STDERR_FILENO, "error: malloc failed");
		return ;
	}
	node->nbr = nbr;
	node->next = NULL;
	node->prev = NULL;
	curr = *list;
	if (!curr)
	{
		*list = node;
		return ;
	}
	while (curr->next)
		curr = curr->next;
	curr->next = node;
	node->prev = curr;
}

void list_pop_back(t_list **list)
{
	t_list *node;

	node = *list;
	while (node && node->next)
		node = node->next;
	if (node && node->prev)
		node->prev->next = NULL;
	else
		*list = NULL;
	if (node)
		free(node);
	node = NULL;
}

void list_clear(t_list **list)
{
	t_list *node;
	t_list *tmp;

	node = *list;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	*list = NULL;
}

t_list *list_last(t_list *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}
