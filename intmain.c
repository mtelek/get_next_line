/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:51:08 by mtelek            #+#    #+#             */
/*   Updated: 2023/11/02 18:52:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*test;
	int		i;

	i = 0;
	fd = open("txtfile.txt", O_RDONLY);
	if (fd == -1)
	{
		return (-1);
	}
	while (i < 3)
	{
		test = get_next_line(fd);
		printf("%s", test);
		free(test);
		i++;
	}
	close(fd);
}
