/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:32:47 by plefevre          #+#    #+#             */
/*   Updated: 2022/02/13 15:49:03 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strndup(char *src, int size)
{
	char		*dest;
	int			i;

	dest = malloc((size + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_concat(char *s1, char *s2)
{
	int		lens1;
	int		lens2;
	char	*sfinal;
	int		i;
	int		j;

	lens1 = ft_strlen_gnl(s1);
	lens2 = ft_strlen_gnl(s2);
	sfinal = malloc((lens1 + lens2 + 1) * sizeof(char));
	if (sfinal == NULL)
		return (NULL);
	j = -1;
	i = -1;
	while (++i < lens1)
		sfinal[++j] = s1[i];
	i = -1;
	while (++i < lens2)
		sfinal[++j] = s2[i];
	sfinal[++j] = '\0';
	free(s1);
	free(s2);
	return (sfinal);
}
