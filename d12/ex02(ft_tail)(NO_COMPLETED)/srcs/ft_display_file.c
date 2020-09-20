/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

void	ft_display_file(int i, int fd, int argc, char **argv)
{
	char	buffer;
	int		offset;
	int		readed;
	int		rnum;
	int		size_file;

	if (argv[1][0] == '-' && (argv[1][1] == 'C' || argv[1][1] == 'c'))
	{
		ft_print_name(i, argc, argv[i]);
		size_file = ft_size_file(argv[i]);
		readed = 0;
		offset = ft_atoi(argv[2]);
		while (readed < (size_file - offset))
		{
			if ((rnum = read(fd, &buffer, 1)) == -1)
			{
				ft_display_custom_error(errno, argv[i]);
				break;
			}
			readed += rnum;
		}
		while  ((rnum = read(fd, &buffer, 1)))
		{
			if (rnum == -1)
			{
				ft_display_custom_error(errno, argv[i]);
				break;
			}
			write(1, &buffer, 1);
		}
		if (i < (argc - 1))
			ft_putchar('\n');
	}
}