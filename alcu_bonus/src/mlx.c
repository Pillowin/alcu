/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 23:18:18 by agautier          #+#    #+#             */
/*   Updated: 2022/02/13 16:05:46 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

t_img	img_init(t_graph *graph)
{
	t_img	img;

	img.bpp = 32;
	img.size_line = WIDTH;
	img.endian = 0;
	img.id = mlx_new_image(graph->mlx_ptr, WIDTH, HEIGTH);
	img.data_addr = mlx_get_data_addr(img.id, &img.bpp, &img.size_line,
			&img.endian);
	return (img);
}

void	img_clear(t_graph *graph)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_put(graph, x, y, 0x000000);
			x += 1;
		}
		y += 1;
	}
}

void	pixel_put(t_graph *graph, int x, int y, unsigned int color)
{
	int	pos;

	pos = x * 4 + y * graph->img.size_line;
	graph->img.data_addr[pos + 0] = color & 0x0000FF;
	graph->img.data_addr[pos + 1] = (color & 0x00FF00) >> 8;
	graph->img.data_addr[pos + 2] = (color & 0xFF0000) >> 16;
	graph->img.data_addr[pos + 3] = (char)0;
}
