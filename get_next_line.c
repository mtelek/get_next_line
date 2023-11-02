/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:47:34 by mtelek            #+#    #+#             */
/*   Updated: 2023/11/02 11:55:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_remainder(char *s)
{
	char		*temp;
	size_t		len;

	len = 0;
	while (s[len] != '\n' && s[len] != '\0')
		len++;
	temp = ft_substr(s, len + 1, (ft_strlen(s) - len));
	if (!temp)
	{
		temp = NULL;
	}
	if (ft_strchr(s, '\n'))
		s[len + 1] = '\0';
	else
		s[len] = '\0';
	free(s);
	return (temp);
}

static char	*createline(char *s)
{
	int		len;
	char	*line;
	int		i;

	i = 0;
	len = 0;
	if (s == NULL)
		return (NULL);
	while (s[len] != '\n' && s[len])
		len++;
	line = (char *)malloc(len + 2);
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = s[i];
		i++;
	}
	if (len > 0)
	{
		line[len] = '\n';
		line[len + 1] = '\0';
	}
	return (line);
}
/*
static char	*output(char *s, int ret, int fd)
{
	char	*line;

	if (fd < 0 || BUFF_SIZE < 0 || ret < 0)
		return (NULL);
	else if (ret == 0 && *s == '\0')
		return (NULL);

	else
	{
		line = createline(s, ret);
		return (line);
	}
}
*/
/*
int	read_into_buffer(int fd, char **s)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*temp;

	ret = read(fd, buff, BUFF_SIZE);
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
		if (ft_strchr(s, '\n') )
			break ;
	}
	line = output(s, ret, fd);
	s = get_remainder(s);
	return (line);
}
*/
char *read_into_buffer(int fd, char **s)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];

	ret = 1;
	if (!*s)
		*s = ft_strdup("");
	while (ret > 0)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (fd < 0 || BUFF_SIZE < 0)
		return (NULL);
		if (ret == 0 && *s == '\0')
		return (NULL);
		if (ret == -1)
		{

			free(*s);
			return (NULL);
		}
		buff[ret] = '\0';
		s = ft_strjoin(s, buff);
		if (ft_strchr(s, '\n') )
			break ;
	}
	free()
	return (s);
}

char	*get_next_line(int fd)
{
	static char		*s;
	char			*line;

	s = read_into_buffer(fd, s);
	if (!s)
		return (NULL);
	line = createline(s);
	s = get_remainder(s);
	return (line);
}