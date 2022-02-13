/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:47:16 by lcalvie           #+#    #+#             */
/*   Updated: 2022/02/13 15:46:10 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include <stdlib.h>

t_graph	*new_graph(t_list *board, int fd)
{
	t_graph	*graph;

	graph = malloc(sizeof(t_graph));
	if (graph == NULL)
		return (NULL);
	graph->mlx_ptr = mlx_init();
	if (graph->mlx_ptr == NULL)
	{
		free(graph);
		return (NULL);
	}
	graph->board = board;
	graph->fd = fd;
	graph->win_ptr = mlx_new_window(graph->mlx_ptr, WIDTH, HEIGTH,
			"ALCU BONUS");
	graph->img = img_init(graph);
	return (graph);
}

void	draw_rectangle(t_graph *graph, int x_corner, int y_corner,
			int x_len, int y_len)
{
	int	x;
	int	y;

	y = 0;
	while (y < y_len)
	{
		x = 0;
		while (x < x_len)
		{
			pixel_put(graph, x_corner + x, y_corner + y, COLOR);
			x++;
		}
		y++;
	}
}

void	free_graph(t_graph *graph)
{
	if (graph)
	{
		mlx_destroy_image(graph->mlx_ptr, graph->img.id);
		mlx_clear_window(graph->mlx_ptr, graph->win_ptr);
		mlx_destroy_window(graph->mlx_ptr, graph->win_ptr);
		mlx_destroy_display(graph->mlx_ptr);
		free(graph->mlx_ptr);
		free(graph);
	}
}
