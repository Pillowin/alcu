/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:00:39 by agautier          #+#    #+#             */
/*   Updated: 2022/02/13 17:41:06 by agautier         ###   ########.fr       */
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

static void	print_spaces(int nb)
{
	while (nb)
	{
		write(STDOUT_FILENO, " ", 1);
		nb -= 1;
	}
}

void	board_print(t_list *board)
{
	int	items;
	int	longest_line;

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

int	board_reset_fd(int fd)
{
	fd = open("/dev/tty", O_RDONLY);
	if (fd == -1)
		ft_putendl_fd(STDERR_FILENO, "Open failed");
	return (fd);
}
