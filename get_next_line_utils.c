/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsasse <lsasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:19:51 by lsasse            #+#    #+#             */
/*   Updated: 2023/12/27 16:50:30 by lsasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_update_collector(char *collector)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (collector[i] && collector[i] != '\n')
		i++;
	if (!collector[i])
	{
		free(collector);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(&collector[i]) + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (collector[i])
		str[j++] = collector[i++];
	str[j] = '\0';
	free(collector);
	return (str);
}

char	*ft_read_to_collector(int fd, char *collector)
{
	char	*buffer;
	int		read_bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && (!ft_strchr(collector, '\n')))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			free(collector);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		collector = ft_strjoin(collector, buffer);
	}
	free(buffer);
	return (collector);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

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

char	*ft_strjoin(char *collector, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!buff)
		return (NULL);
	if (!collector)
	{
		collector = (char *)malloc(1 * sizeof(char));
		collector[0] = '\0';
	}
	if (!collector)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(collector) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (collector[++i] != '\0')
		str[i] = collector[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(collector) + ft_strlen(buff)] = '\0';
	free(collector);
	return (str);
}
