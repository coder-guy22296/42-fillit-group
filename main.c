/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 15:51:57 by pvan-erp          #+#    #+#             */
/*   Updated: 2016/10/22 17:31:13 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char			tetristr[BUF_SIZE];
	int				file;
	int				ret;

	if (argc != 2)
		write(1, "usage: fillit source_file\n", 26);
	else
	{
		ft_bzero(tetristr, BUF_SIZE);
		file = open(argv[1], O_RDONLY);
		ret = read(file, tetristr, BUF_SIZE);
		if (ret >= BUF_SIZE || ret % 21 != 20)
		{
			write(1, "error\n", 6);
			return (1);
		}
		close(file);
		if (!is_valid(tetristr))
		{
			write(1, "error\n", 6);
			return (1);
		}
		solve_map(convert(tetristr));
	}
	return (0);
}
