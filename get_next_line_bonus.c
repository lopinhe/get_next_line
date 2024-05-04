/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsasse <lsasse@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:31:13 by lsasse            #+#    #+#             */
/*   Updated: 2023/12/29 19:12:52 by lsasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_line(char *collector)
{
	int		i;
	char	*str;

	i = 0;
	if (!collector[i])
		return (NULL);
	while (collector[i] && collector[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (collector[i] && collector[i] != '\n')
	{
		str[i] = collector[i];
		i++;
	}
	if (collector[i] == '\n')
	{
		str[i] = collector[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*collector[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	collector[fd] = ft_read_to_collector(fd, collector[fd]);
	if (!collector[fd])
	{
		return (NULL);
	}
	line = ft_get_line(collector[fd]);
	collector[fd] = ft_update_collector(collector[fd]);
	return (line);
}
