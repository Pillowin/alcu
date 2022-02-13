/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:32:34 by agautier          #+#    #+#             */
/*   Updated: 2022/02/13 12:55:42 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
# define ALCU_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list	t_list;

struct s_list
{
	int		nbr;
	t_list	*next;
	t_list	*prev;
};

// AI
void	ai_plays(t_list **board);

// Player
void	player_plays(t_list **board, int fd);

// Board
void	board_print(t_list *board);
int		board_fill(int fd, t_list **board);
int		board_reset_fd(int fd);

// Utils
size_t	ft_strlen(char *str);
void	ft_putstr_fd(int fd, char *str);
void	ft_putendl_fd(int fd, char *str);
void	ft_putnbr(int nbr);
int		ft_atoi(char *str);
char	*get_next_line(int fd);

// List utils
void	list_push_back(t_list **list, int nbr);
void	list_pop_back(t_list **list);
void	list_clear(t_list **list);
int		list_max(t_list *list);
t_list	*list_last(t_list *list);

#endif
