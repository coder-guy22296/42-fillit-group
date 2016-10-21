/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 15:51:57 by pvan-erp          #+#    #+#             */
/*   Updated: 2016/10/21 15:51:59 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char			tetristr[BUF_SIZE];
	//unsigned short	*tetriarr;
	int				file;
	int				ret;
	/*
	int i = ~0;																							//debug

	while (++i < 100)																					//debug
		printf("sqrt(%d) = %d\n", i, ft_sqrt_ceil(i));													//debug
	printf("sqrt(2147483647) = %d\n", ft_sqrt_ceil(2147483647));										//debug
	printf("sqrt(4294967295) = %d\n", ft_sqrt_ceil(4294967295));										//debug
	// */
	if (argc != 2)
		write(1, "usage: fillit source_file\n", 26);
	else
	{
		ft_bzero(tetristr, BUF_SIZE);
		/*
		int i = 0;																						///debug
		while (i < BUF_SIZE)																			///debug
		{																								///debug
			printf("%d\n", tetristr[i++]);																///debug
		}																								///debug
		// */
		//printf("%s\n", tetristr);																		///debug
		file = open(argv[1], O_RDONLY);
		ret = read(file, tetristr, BUF_SIZE);
		//printf("%d\n", ret);																			///debug
		
		//*
		if (ret >= BUF_SIZE || ret % 21 != 20)
		{
			write(1, "error\n", 6);
			//printf("wrong file length\n");																////debug
			return (1);
		}
		// */
		close(file);
		if (!is_valid(tetristr))
		{
			write(1, "error\n", 6);
			//printf("wrong format\n");																	///debug
			return (1);
		}
	}

	/*
	tetriarr = convert(tetristr);																		//debug
	i = ~0;																								//debug
	while (tetriarr[++i])																					//debug
	{																									//debug
		printf("%d\n", tetriarr[i]);																	//debug
	}																									//debug
	// */
	//write(1, argv[0], 9);																				///debug
	//write(1, "\n", 1);																				///debug
	solve_map(convert(tetristr));
	return (0);
}
