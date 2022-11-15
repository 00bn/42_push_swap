/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:38:58 by balnahdi          #+#    #+#             */
/*   Updated: 2022/02/22 16:38:59 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	scan_b100(t_pushswap *pushswap)
{
	int	j;

	j = pushswap->lena - 1;
	init_b100(pushswap);
	while (j > -1 || pushswap->lensort > -1)
	{
		if (pushswap->stackb[pushswap->scanb] == \
		pushswap->sorted[pushswap->lensort])
		{
			check_mov100(pushswap);
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

void	divb100(t_pushswap *pushswap)
{
	pushswap->divb = pushswap->divb / 2;
}

void	sendto_b100(t_pushswap *pushswap)
{
	int	i;

	i = pushswap->topa + 1;
	while (i-- > -1)
	{
		if (pushswap->sorted[pushswap->median] > \
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

void	algo100(t_pushswap *pushswap)
{
	pushswap->arrow = pushswap->topa;
	while (pushswap->contra < pushswap->median || \
	pushswap->contra == pushswap->lena)
	{	
		sendto_b100(pushswap);
		if (pushswap->contra <= pushswap->lena)
		{
			pushswap->median = pushswap->contra / 2 + pushswap->lena / 2;
		}
	}
	pushswap->divb = pushswap->topb;
	checkswap100(pushswap);
	divb100(pushswap);
	scan_b100(pushswap);
}
