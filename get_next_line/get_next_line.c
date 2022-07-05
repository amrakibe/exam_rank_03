#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char *ft_strdup(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	char *buff = malloc(i + 1);
	i = 0;
	while (str[i])
	{
		buff[i] = str[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}
char *get_next_line(int fd)
{
	char line[1000000] = {0};
	char buf[1];
	int i = 0;
	int n;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while ((n = read(fd, buf, 1)) && n > 0)
	{
		line[i++] = buf[0];
		line[i] = 0;
		if (buf[0] == '\n')
			return (ft_strdup(line));
	}
	if (!line[0])
		return (NULL);
	return (ft_strdup(line));
}
