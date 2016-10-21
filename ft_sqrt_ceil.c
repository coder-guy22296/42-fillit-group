/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_ceil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 15:54:43 by pvan-erp          #+#    #+#             */
/*   Updated: 2016/10/21 15:54:45 by pvan-erp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** square root, rounded up
*/

unsigned int	ft_sqrt_ceil(unsigned int sq)
{
	unsigned int	rt;

	rt = 0;
	while (rt * rt < sq && rt < 65536)
		rt++;
	return (rt);
}
