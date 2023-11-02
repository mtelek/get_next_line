
static char	*output(char *s, int ret, int fd)
{
	char	*line;

	if (fd < 0 || BUFF_SIZE < 0)
		return (NULL);
	else if (ret == 0 && s[fd] == 0)
		return (NULL);
	else
	{
		line = createline(s, ret);
		return (line);
	}
}

int	read_into_buffer(int fd, char **s)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*temp;

	ret = read(fd, buff, BUFF_SIZE);
	if (ret < 0)
		return (0);
	if (ret == 0)
		return (0);
	if (*s == NULL)
	{
		*s = ft_strdup("");
	}
	buff[ret] = '\0';
	temp = *s;
	*s = ft_strjoin(temp, buff);
	if (!*s)
	{
		free(temp);
		*s = NULL;
		return (0);
	}
	free(temp);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char		*s;
	char			*line;
	int				ret;

	ret = 1;
	while (ret > 0)
	{
		ret = read_into_buffer(fd, &s);
		if (ret < 0)
			return (NULL);
		if (ft_strchr(s, '\n'))
			break ;
	}
	line = output(s, ret, fd);
	s = get_remainder(s);
	return (line);
}