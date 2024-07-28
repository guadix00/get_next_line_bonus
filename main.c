/*int main(void)
{
	char	*line;
	int fd = open("test42.txt", O_RDONLY);
	if (fd == NOT_FOUND)
		return (NOT_FOUND);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}*/
int	main(int ac, char **av)
{
	int 	fd;
	char	*line;
	int		count; // line numbers

	count = 0;
	if (ac == 1)
	{
		write(1, "File name missing.\n", 19);
		return (1);
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			write(1, "Cannot read file.\n", 18);
		while (fd)
		{
			line = get_next_line(fd);
			if (line == NULL)
				break ;
			count++;
			printf("LINE [%d] =\n%s\n", count, line);
			printf("------------\n");
			free(line);
			line = NULL;
		}
		close(fd);
	}
	return (0);
}

