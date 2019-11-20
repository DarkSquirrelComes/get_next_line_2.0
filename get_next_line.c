/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heurybia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:18:29 by heurybia          #+#    #+#             */
/*   Updated: 2019/11/20 16:18:36 by heurybia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "libft/libft.h"

void			concat(char **overhead, char *buf, int *status)
{
	char		*new_oh;

	new_oh = ft_strjoin(*overhead, buf);
	free(*overhead);
	if (!(new_oh))
	{
		*status = -1;
		return ;
	}
	*overhead = new_oh;
}

void			extend_overhead(char **overhead, int fd, int *status)
{
	char		buf[BUFF_SIZE + 1];
	int			len;

	*status = 1;
	if ((len = read(fd, (void *)buf, BUFF_SIZE)) > 0)
		buf[len] = '\0';
	else
		*status = len;
	if (*status == 0 || *status == -1)
		return ;
	concat(overhead, buf, status);
}

int				process_overhead(char **overhead, char **line)
{
	char		*new_oh;
	int			len;

	len = ft_strchr(*overhead, '\n') - *overhead;
	if (!(*line = malloc(len + 1)))
		return (-1);
	else
		(*line)[len] = '\0';
	ft_strncpy(*line, *overhead, len);
	if (*line == 0)
		return (-1);
	new_oh = ft_strdup(*overhead + len + 1);
	free(*overhead);
	*overhead = new_oh;
	return (1);
}

void			str_no_endl(char **overhead, char **line)
{
	*line = ft_strdup(*overhead);
	free(*overhead);
	*overhead = NULL;
}

int				get_next_line(const int fd, char **line)
{
	static char	*overhead = NULL;
	int			status;

	if (fd < 0 || line == NULL)
		return (-1);
	status = 1;
	if (overhead == NULL)
		if (!(overhead = ft_strnew(1)))
			return (-1);
	if (ft_strchr(overhead, '\n'))
		return (process_overhead(&overhead, line));
	extend_overhead(&overhead, fd, &status);
	if (status == 0 && ft_strlen(overhead) != 0)
	{
		str_no_endl(&overhead, line);
		return (1);
	}
	if (status == -1 || status == 0)
		return (status);
	return (get_next_line(fd, line));
}
