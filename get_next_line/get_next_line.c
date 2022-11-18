#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*str = malloc(10000), *buffer = str;
	while (read(fd, buffer, 1) > 0 && *buffer++ != '\n');
	return (buffer > str) ? (*buffer = 0, str) : (free(str), NULL);
}
