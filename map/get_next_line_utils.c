/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:11:35 by rcheiko           #+#    #+#             */
/*   Updated: 2021/04/01 12:31:55 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*rep;
	int		i;

	len = ft_strlen(s1);
	i = 0;
	rep = malloc(sizeof(char) * len + 1);
	if (rep == NULL)
		return (NULL);
	while (s1[i])
	{
		rep[i] = s1[i];
		i++;
	}
	rep[i] = '\0';
	return (rep);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)&s[size]);
	if (c == 0 || s[i] == 0)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*strf;
	int				i;
	unsigned int	lens;

	lens = ft_strlen(s);
	i = 0;
	if (start > lens)
	{
		strf = malloc(sizeof(char) * 1);
		if (strf == NULL)
			return (NULL);
		return (strf);
	}
	strf = malloc(sizeof(char) * len + 1);
	if (strf == NULL)
		return (NULL);
	while (s[start] && len != 0)
	{
		if (len == 0)
			return (strf);
		strf[i++] = s[start++];
		len--;
	}
	strf[i] = '\0';
	return (strf);
}
