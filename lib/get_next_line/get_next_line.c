/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:46:39 by muguveli          #+#    #+#             */
/*   Updated: 2024/01/18 16:10:14 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readline(int fd, char	*readone)
{
	char	*buff;
	int		reader;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	reader = 1;
	while (!ft_strchr1(readone, '\n') && reader != 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buff);
			free(readone);
			return (0);
		}
		buff[reader] = '\0';
		readone = ft_strjoin1(readone, buff);
	}
	free(buff);
	return (readone);
}

char	*putline(char *readone)
{
	char	*str;
	int		i;

	i = 0;
	if (!readone[i])
		return (0);
	while (readone[i] != '\n' && readone[i] != '\0')
		i++;
	str = (char *)malloc(sizeof(char) * i + 2);
	if (!str)
		return (0);
	i = 0;
	while (readone[i] != '\n' && readone[i] != '\0')
	{
		str[i] = readone[i];
		i++;
	}
	if (readone[i] == '\n')
	{
		str[i] = readone[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*nxtline(char *readone)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (readone[i] != '\n' && readone[i] != '\0')
		i++;
	if (!readone[i])
	{
		free(readone);
		return (0);
	}
	str = malloc(sizeof(char) * (ft_strlen1(readone) - i));
	if (!str)
		return (0);
	i++;
	while (readone[i + j] != '\0')
	{
		str[j] = readone[j + i];
		j++;
	}
	str[j] = '\0';
	free(readone);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*readone;
	char		*arr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	readone = readline(fd, readone);
	if (!readone)
		return (0);
	arr = putline(readone);
	readone = nxtline(readone);
	return (arr);
}
