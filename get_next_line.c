/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:47:34 by mtelek            #+#    #+#             */
/*   Updated: 2023/10/19 13:28:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	createline(char **s, char **line)
{
	int		len;
	char	*temp;

	len = 0;
	while((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if((*s)[len] == '\n')
	{
		*line = ft_substr(*s, 0, len);
		temp = ft_strdup(&((*s)[len]));
		free(*s);
		*s = temp;
		if((*s)[0] == '\0')
			ft_calloc((size_t)*s, 1);
	}
	else
	{
		*line = ft_strdup(*s);
	}
	return (1);
}

static int	output(char **s, char ** line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && s[fd] == NULL)
		return (0);
	else
		return (createline(&s[fd], line));
}

int	get_next_line(const int fd, char **line)
{
	int				ret;
	static char		*s[FD_SIZE];
	char			buff[BUFF_SIZE + 1];
	char			*temp;

	if (fd < 0 && line == NULL)
		return (-1);
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
			break ;
	}
	return (output(s, line, ret, fd));
}
/*
int main(void)
{
    int fd;
    char *line;

    fd = open("txtfile.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    while (get_next_line(fd, &line) > 0)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
*/