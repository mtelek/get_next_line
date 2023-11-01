/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:47:34 by mtelek            #+#    #+#             */
/*   Updated: 2023/11/01 17:31:08 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_remainder(char *line)
{
	char		*temp;
	size_t		len;

	len = 0;
	while (line[len] != '\n' && line[len] != '\0')
		len++;
	temp = ft_substr(line, len + 1, (ft_strlen(line) - len));
	if (!temp)
	{
		free(temp);
		temp = NULL;
	}
	if (ft_strchr(line, '\n'))
		line[len + 1] = '\0';
	else
		line[len] = '\0';
	return (temp);
}

static char	*createline(char *s)
{
	int		len;
	char	*line;
	int		i;

	i = 0;
	len = 0;
	line = 0;
	if (s == NULL)
		return (NULL);
	while (s[len] != '\n' && s[len])
		len++;
	//if (s[len] == '\n' || len == BUFF_SIZE || s[len] == '\0')
	line = (char *)malloc(len + 2);
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = s[i];
		i++;
	}
	line[len] = '\n';
	line[len + 1] = '\0';
	return (line);
}

static char	*output(char *s, int ret, int fd)
{
	if (fd < 0 || BUFF_SIZE < 0)
		return (NULL);
	else if (ret == 0 && s[fd] == 0)
		return (NULL);
	else
		return (createline(s));
}

int	read_into_buffer(int fd, char **s)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*temp;

	ret = read(fd, buff, BUFF_SIZE);
	if (ret < 0)
		return (-1);
	if (*s == NULL)
		*s = ft_strdup("");
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
	char			*temp;
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
	temp = get_remainder(s);
	free(s);
	s = temp;
	return (line);
}
