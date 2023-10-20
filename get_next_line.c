/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:47:34 by mtelek            #+#    #+#             */
/*   Updated: 2023/10/20 16:23:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*createline(char **s)
{
	int		len;
	char	*temp;
	char	*line;

	len = 0;
	line = 0;
	if (*s == NULL)
        return (NULL);
	while ((*s)[len] != '\n')
		len++;
	if((*s)[len] == '\n')
	{
		line = ft_substr(*s, 0, len);
		temp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = temp;
		if((*s)[0] == '\0')
		{	
			ft_strdel(s);
			return (NULL);
		}
	}
	return (line);
}

static char	*output(char **s, int ret, int fd)
{
	if (ret < 0)
		return (NULL);
	else if (ret == 0 && s[fd] == NULL)
		return (NULL);
	else
		return (createline(&s[fd]));
}

char	*get_next_line(int fd)
{
	int				ret;
	static char *s[FD_SIZE];
	char			buff[BUFF_SIZE + 1];
	char			*temp;
	int 			i;
	
	i = 0;
	while (i < FD_SIZE)
	{
		s[i] = NULL;
		i++;
	}
	 if (fd < 0 || fd >= FD_SIZE)
        return (NULL);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = temp;
		}
		if (ft_strchr(s[fd], '\n'))
		{	
			break;
		}
	}
	return (output(s, ret, fd));
}
