
char	*read_into_buffer(int fd, char *s)
{
	long long int		ret;
	char				*buff;
	char				*temp;

	if (!s)
		s = ft_calloc(1, 1);
	buff = ft_calloc(BUFF_SIZE + 1, sizeof(char));
	if(!buff)
		return (0);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret  == -1)
		{
			free(buff);
			free(temp);
			return (NULL);
		}
		buff[ret] = '\0';
		temp = s;
		s = ft_strjoin(temp, buff);
		if (!s)
		{	
			free(temp);
			s = NULL;
			return (0);
		}
		if (ft_strchr(temp, '\n'))
			break ;
	}
	free(buff);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char		*s;
	char			*line;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (NULL);
	s = read_into_buffer(fd, s);
	if (!s)
		return (NULL);
	line = createline(s);
	s = get_remainder(s);
	
	return (line);
}
