/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:32:34 by agautier          #+#    #+#             */
/*   Updated: 2022/02/13 00:21:38 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALCU_H
#define ALCU_H

#include "mlx.h"

#include <unistd.h>
#include <fcntl.h>

typedef struct s_list t_list;

struct s_list
{
	int nbr;
	t_list *next;
	t_list *prev;
};

# define WIDTH 1000
# define HEIGTH 1000
# define COLOR 0xE16861

typedef struct s_img
{
	void	*id;
	char	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_graph t_graph;
struct	s_graph
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_list		*board;
	int		fd;
};

int play(t_graph *graph, int x_baton, int y_baton);

// MAP
int	fill_board(int fd, t_list **board);

// AI
void ai_plays(t_list **board);

// Player
void player_plays(t_graph *graph);

// Board
void board_print(t_list *board, t_graph *graph, int x_baton, int y_baton);

//GRAPH
t_graph	*new_graph();
void	draw_rectangle(t_graph *graph, int x_corner, int y_corner, int x_len, int y_len);
void	free_graph(t_graph *graph);

// Mlx
t_img img_init(t_graph *graph);
void img_clear(t_graph *graph);
void	pixel_put(t_graph *graph, int x, int y, unsigned int color);

// Utils
size_t ft_strlen(char *str);
void ft_putstr_fd(int fd, char *str);
void ft_putendl_fd(int fd, char *str);
void ft_putnbr(int nbr);
int ft_atoi(char *str);
char *get_next_line(int fd);
int	ft_memcmp(const void *s1, const void *s2, int n);

// List utils
void list_push_back(t_list **list, int nbr);
void list_pop_back(t_list **list);
void list_clear(t_list **list);
t_list *list_last(t_list *list);
int	list_max(t_list *list);
int	ft_lstsize(t_list *lst);


#endif
