/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 23:16:57 by agautier          #+#    #+#             */
/*   Updated: 2022/02/12 00:26:11 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_get_line(char *save)
{
	int		i;
	char	*s;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_save(char *save)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (save[i])
		s[c++] = save[i++];
	s[c] = '\0';
	free(save);
	return (s);
}

char	*ft_read_and_save(int fd, char *save)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}
