/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 15:57:44 by pvan-erp          #+#    #+#             */
/*   Updated: 2016/10/21 16:15:50 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 546
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_map
{
	int		size;
	int		solved;
	char	map[24][24];
}				t_map;

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

void			ft_bzero(void *s, size_t n);
unsigned int	ft_sqrt_ceil(unsigned int sq);
int				is_valid(char *input);
void			ft_bzero(void *s, size_t n);
unsigned short	*convert(char *tetristr);
unsigned int	ft_sqrt_ceil(unsigned int sq);
void			solve_map(unsigned short *tetriarr);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
