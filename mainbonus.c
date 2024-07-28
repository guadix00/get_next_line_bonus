#include <stdio.h>

int	main(void)
{
	char	*line;

	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	
	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
	{
		write(1, "Cannot read one of the files.\n", 30);
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd1);
		if (line == NULL)
			break ;
		printf("File 1 line: %s", line);
		free(line);
		printf("--------\n");
		line = get_next_line(fd2);
		printf("File 2 line: %s", line);
		free(line);
		printf("-------\n");
		line = get_next_line(fd3);
		printf("File 3 line: %s", line);
		free(line);
		printf("-------\n");
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}

