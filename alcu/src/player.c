/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:16:59 by agautier          #+#    #+#             */
/*   Updated: 2022/02/13 13:32:57 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void	player_plays(t_list **board, int fd)
{
	t_list	*heap;
	char	*line;

	heap = list_last(*board);
	while (true)
	{
		ft_putendl_fd(STDOUT_FILENO, "Please choose between 1 and 3 items");
		line = get_next_line(fd);
		if (line && ft_strlen(line) == 2 && (line[0] > '0' && line[0] <= '3')
			&& line[1] == '\n' && line[0] <= (heap->nbr + '0'))
			break ;
		if (line && ft_strlen(line))
		{
			line[ft_strlen(line) - 1] = '\0';
			ft_putstr_fd(STDOUT_FILENO, line);
		}
		ft_putendl_fd(STDOUT_FILENO, " - Invalid choice");
		free(line);
	}
	heap->nbr -= line[0] - '0';
	free(line);
	if (heap->nbr <= 0)
		list_pop_back(board);
}
