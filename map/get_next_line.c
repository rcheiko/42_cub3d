/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:10:47 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/01 12:28:25 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_newline(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (i + 1);
}

char	*creat_line(char *str, char *buffer)
{
	char	*tmp;
	int		j;
	int		k;

	j = 0;
	k = 0;
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1 + ft_strlen(str)));
	if (tmp == NULL)
		return (NULL);
	if (str)
	{
		while (str[j])
		{
			tmp[j] = str[j];
			j++;
		}
		free(str);
		str = NULL;
	}
	while (buffer[k])
		tmp[j++] = buffer[k++];
	tmp[j] = '\0';
	return (tmp);
}

int	get_rest(char **line, char *str)
{
	char	*rest;
	int		i;

	i = is_newline(str, '\n');
	rest = ft_strchr(str, '\n');
	if (rest != NULL)
	{
		*line = ft_substr(str, 0, i);
		ft_strcpy(str, rest + 1);
		return (1);
	}
	return (0);
}

void	malloc_line(char **line, char *str[4096], int fd)
{
	if (str[fd])
		*line = ft_strdup(str[fd]);
	else
		*line = ft_strdup("");
}

int	get_next_line(int fd, char **line)
{
	static char	*str[4096];
	char		buffer[BUFFER_SIZE + 1];
	int			ret;

	if (fd < 0 || fd > 255 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (str[fd] && get_rest(line, str[fd]))
		return (1);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
		str[fd] = creat_line(str[fd], buffer);
		if (str[fd] == NULL)
			return (-1);
		if (get_rest(line, str[fd]))
			return (1);
	}
	malloc_line(line, str, fd);
	free(str[fd]);
	str[fd] = NULL;
	return (ret);
}
