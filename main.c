/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:33:58 by mtelek            #+#    #+#             */
/*   Updated: 2024/03/30 20:35:20 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*text;
	int		i;

	i = 0;
	fd = open("txtfile.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	while (i < 3)
	{
		text = get_next_line(fd);
		printf("%s", text);
		free(text);
		i++;
	}
	close(fd);
}
