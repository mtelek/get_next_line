/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:47:34 by mtelek            #+#    #+#             */
/*   Updated: 2023/10/20 12:19:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*createline(char **s)
{
	int		len;
	char	*temp;

	len = 0;
	temp = NULL;
	while ((*s)[len] != '\n')
		len++;
	if((*s)[len] == '\n')
	{
		temp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = temp;
		if((*s)[0] == '\0')
			ft_strdel(s);
	}
	if((*s[len] != '\n' && *s[len + 1] == 0)) //last updated
		return (0);
	return ((char *)s);
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
	static char		*s[FD_SIZE];
	char			buff[BUFF_SIZE + 1];
	char			*temp;

	if (fd < 0)
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
