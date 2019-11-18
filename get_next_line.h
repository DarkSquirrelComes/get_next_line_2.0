#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h> 
# include <errno.h> 

# define BUFF_SIZE 20

char	*ft_strjoin(char const *s1, char const *s2);
/************************
*	OLD MAMMOTH'S SHIT!	*
*						*
*		UP THERE!		*
*		SERIOUSLY.		*
*						*
*************************/
int		get_next_line(const int fd, char **line);
//additional functions...
void	concat(char **overhead, char *buf, int *status);
void	extend_overhead(char **overhead, int fd, int *status);
int		process_overhead(char **overhead, char **line);
#endif