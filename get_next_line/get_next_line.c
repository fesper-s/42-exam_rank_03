#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*str = malloc(10000);
	char	*buffer = str;

	while (read(fd, buffer, 1) > 0 && *buffer != '\n')
		buffer++;
	if (buffer > str)
		return (*buffer = 0, str);
	else
		return (free(str), NULL);
}
