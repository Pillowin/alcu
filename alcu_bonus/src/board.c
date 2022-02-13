/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:00:39 by agautier          #+#    #+#             */
/*   Updated: 2022/02/13 17:40:21 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

static int	correct_line(char *line)
{
	int	len;
	int	i;

	if (line == NULL)
		return (0);
	len = ft_strlen(line);
	if (len == 0)
		return (0);
	i = -1;
	while (++i < len - 1)
		if (line[i] < '0' || line[i] > '9')
			return (0);
	if (line[len - 1] != '\n')
		return (0);
	if (len == 1)
		return (-1);
	return (ft_atoi(line));
}

int	board_fill(int fd, t_list **board)
{
	char	*line;
	int		nb;

	*board = NULL;
	if (fd < 0)
	{
		ft_putendl_fd(STDERR_FILENO, "Open failed, wrong filename.");
		return (1);
	}
	line = get_next_line(fd);
	while (*board == NULL || line != NULL)
	{
		nb = correct_line(line);
		if (nb > 0 && nb <= MAX_ITEMS)
			list_push_back(board, nb);
		free(line);
		if (nb == -1 && fd == STDIN_FILENO)
		{
			if (list_size(*board) == 0)
			{
				list_clear(board);
				ft_putendl_fd(STDERR_FILENO, "ERROR");
				return (1);
			}
			return (0);
		}
		if ((nb > 0 && nb <= MAX_ITEMS) || nb == -1)
			line = get_next_line(fd);
		if (nb > MAX_ITEMS || nb == 0 || (nb == -1 && line != NULL))
		{
			if (nb == -1)
				free(line);
			list_clear(board);
			ft_putendl_fd(STDERR_FILENO, "ERROR");
			return (1);
		}
	}
	return (0);
}

void	board_print(t_list *board, t_graph *graph, int x_baton, int y_baton)
{
	int	items;
	int	i;
	int	j;
	int	x_corner;
	int	y_corner;
	int	x_decalage;

	img_clear(graph);
	i = 0;
	while (board)
	{
		y_corner = i * y_baton + 0.05 * y_baton + HEIGTH * 0.05;
		items = board->nbr;
		j = 0;
		x_decalage = x_baton * (graph->max - items);
		while (j < items)
		{
			x_corner =  (2 * j + 0.05) * x_baton
				+ WIDTH * 0.05
				+ x_decalage;
			draw_rectangle(graph, x_corner, y_corner,
				x_baton * 0.9, y_baton * 0.9);
			j++;
		}
		i++;
		board = board->next;
	}
	mlx_put_image_to_window(graph->mlx_ptr, graph->win_ptr, graph->img.id,
		0, 0);
}

int	board_reset_fd(int fd)
{
	fd = open("/dev/tty", O_RDONLY);
	if (fd == -1)
		ft_putendl_fd(STDERR_FILENO, "Open failed");
	return (fd);
}
