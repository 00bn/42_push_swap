/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo500.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:39:01 by balnahdi          #+#    #+#             */
/*   Updated: 2022/02/22 16:39:02 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	scan_b(t_pushswap *pushswap)
{
	int	j;

	j = pushswap->lena - 1;
	init_b(pushswap);
	while (j > -1 || pushswap->lensort > -1)
	{
		if (pushswap->stackb[pushswap->scanb] == \
			pushswap->sorted[pushswap->lensort])
		{
			check_mov(pushswap);
			pushswap->lensort--;
			pushswap->scanb = pushswap->topb;
		}
		else if (pushswap->stackb[pushswap->scanb] != \
		pushswap->sorted[pushswap->lensort])
		{
			while (pushswap->stackb[pushswap->scanb] != \
			pushswap->sorted[pushswap->lensort] && pushswap->scanb > -1)
			{
				pushswap->scanb--;
			}
		}
		j--;
	}
}

void	divb(t_pushswap *pushswap)
{
	pushswap->divb = pushswap->divb / 2;
}

void	sendto_b(t_pushswap *pushswap)
{
	int	i;

	i = pushswap->topa + 1;
	while (i-- > -1 && pushswap->contra <= pushswap->lena - 1)
	{
		if (pushswap->sorted[pushswap->chunk500] > \
		pushswap->stacka[pushswap->topa])
		{
			pushb(pushswap);
			write(1, "pb\n", 3);
			pushswap->contra++;
		}
		else
		{
			rota(pushswap);
			write(1, "ra\n", 3);
			pushswap->arrow++;
		}
	}
}

void	algo500(t_pushswap *pushswap)
{
	int	j;

	j = pushswap->topa;
	pushswap->arrow = pushswap->topa;
	while (pushswap->contra < pushswap->chunk500 && \
	pushswap->contra <= pushswap->lena - 1 && j-- > 0)
	{
		sendto_b(pushswap);
		if (pushswap->contra < pushswap->lena - 1)
		{
			if (pushswap->chunk500 <= pushswap->contra)
			{
				pushswap->chunk500 = pushswap->contra + pushswap->lena / 11;
				if (pushswap->chunk500 == 495)
					pushswap->chunk500 = 499;
			}
		}
	}
	pushswap->divb = pushswap->topb;
	divb(pushswap);
	scan_b(pushswap);
}
