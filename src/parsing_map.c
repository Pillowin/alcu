/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:07:48 by lcalvie           #+#    #+#             */
/*   Updated: 2022/02/12 19:03:27 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include <stdlib.h>

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

int	fill_board(int fd, t_list **board)
{
	char	*line;
	int	nb;

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
		if (nb > 0 && nb <= 10000)
			list_push_back(board, nb);
		free(line);
		if ((nb > 0 && nb <= 10000) || nb == -1)
			line = get_next_line(fd);
		if (nb  > 10000 || nb == 0 || (nb == -1 && line != NULL))
		{
			if (nb == -1)
				free(line);
			ft_putendl_fd(STDERR_FILENO, "ERROR");
			return (1);
		}
	}
	return (0);
}
