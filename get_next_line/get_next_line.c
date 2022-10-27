#include <stdlib.h>
#include <unistd.h>

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

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("./teste.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
}
