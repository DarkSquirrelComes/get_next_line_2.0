#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h> 
# include <errno.h> 

# define BUFF_SIZE 1

int		get_next_line(const int fd, char **line);
#endif