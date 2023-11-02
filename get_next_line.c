/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:47:34 by mtelek            #+#    #+#             */
/*   Updated: 2023/11/02 20:59:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	{
		return (NULL);
	}
	while (i <= len)
	{
		line[i] = s[i];
		i++;
	}
	line[len] = '\n';
	line[len + 1] = '\0';
	return (line);
}

char	*get_remainder(char *s)
{
	char		*temp;
	size_t		len;

	len = 0;
	while (s[len] != '\n' && s[len] != '\0')
		len++;
	if (!s)
	{
		temp = NULL;
	}
	temp = ft_substr(s, len + 1, (ft_strlen(s) - len));
	if (!temp)
	{
		free(s);
		return (NULL);
	}
	if (ft_strchr(s, '\n'))
		s[len + 1] = '\0';
	else
		s[len] = '\0';
	free(s);
	return (temp);
}

char	*read_into_buffer(int fd, char *s)
{
	long long int		ret;
	char				*buff;
	char				*temp;

	if (!s)
		s = ft_calloc(1, 1);
	buff = ft_calloc(BUFF_SIZE + 1, sizeof(char));
	if(!buff)
	{
		free(s);
		return (NULL);
	}
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1)
		{
			free(buff);
			free(s);
			return (NULL);
		}
		buff[ret] = '\0';
		temp = ft_strjoin(s, buff);
		free(s);
		s = temp;
		if (ft_strchr(s, '\n'))
			break ;
	}
	free(buff);
	return (s);
}

char	*get_next_line(int fd)
{
	static char		*s;
	char			*line;
	
	if (fd < 0 || BUFF_SIZE <= 0)
		return (NULL);
	s = read_into_buffer(fd, s);
	if (!s)
		return (0);
	line = createline(s);
	s = get_remainder(s);
	return (line);
}
