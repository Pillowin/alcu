/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:07:13 by agautier          #+#    #+#             */
/*   Updated: 2022/02/12 21:26:08 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include "mlx.h"

static int close_win(int keycode, t_graph *graph)
{
	(void)keycode;
	mlx_destroy_window(graph->mlx_ptr, graph->win_ptr);
	return (0);
}

static int render(int keycode, t_graph *graph)
{
	(void)keycode;
	(void)graph;
	write(STDOUT_FILENO, "render", 6);
	return (0);
}

void event_register(t_graph *graph)
{
	mlx_hook(graph->win_ptr, 33, (1L<<17), close_win, graph);
	mlx_hook(graph->win_ptr, 15, (1L<<16), , graph);
}
