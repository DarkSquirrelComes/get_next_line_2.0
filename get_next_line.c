#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
//#include "libft/libft.h"

static size_t	ft_strlen(const char *str)
{
	size_t		res;

	res = 0;
	while (*(str++))
		++res;
	return (res);
}

static char		*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = src[i];
	return (dest);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*dest;

	if (s1 == 0 || s2 == 0)
		return (0);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(dest = malloc((l1 + l2 + 1) * sizeof(char))))
		return (0);
	ft_strcpy(dest, s1);
	ft_strcpy(dest + l1, s2);
	dest[l1 + l2] = 0;
	return (dest);
}




/************************
*	OLD MAMMOTH'S SHIT!	*
*						*
*		UP THERE!		*
*		SERIOUSLY.		*
*						*
*************************/

void			concat(char **overhead, char *buf, int *status)
{
	char 		*new_oh;

	new_oh = ft_strjoin(*overhead, buf);
    free(buf);
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
	char		*buf;
    size_t		len;

    *status = 1;
    if (!(buf = (char*)malloc(BUFF_SIZE + 1)))
    {
    	*status = -1;
    	return ;
    }
    if ((len = read(fd, (void *)buf, BUFF_SIZE)))
    {
        if (errno != 0)
        {
            free(buf);
            *status = -1;
        }
        buf[len] = 0;
    }
    else
        *status = 0;
    if (*status == 0 || *status == -1)
    	return ;
    concat(overhead, buf, status);
}

int				process_overhead(char **overhead, char **line)
{
	char		*new_oh;
	size_t		len;

	len = strchr(*overhead, '\n') - *overhead;
	if (!(*line = malloc(len + 1)))
		return (-1);
	else
		(*line)[len] = '\0';
	strncpy(*line, *overhead, len);
	if (*line == 0)
		return (-1);
	new_oh = strdup(*overhead + len + 1);
	free(*overhead);
	*overhead = new_oh;
	return (1);
}

void			str_no_endl(char **overhead, char **line)
{
	*line = strdup(*overhead);
	free(*overhead);
	*overhead = 0;
}

int				get_next_line(const int fd, char **line)
{
	static char	*overhead = 0;
	int			status;

	status = 1;
	if (overhead == 0)
	{
		if (!(overhead = malloc(1)))
			return (-1);
		else
			overhead[0] = '\0';
	}
	if (strchr(overhead, '\n'))
	{
		status = process_overhead(&overhead, line);
		return status;
	}
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
