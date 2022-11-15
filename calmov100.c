/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calmov100.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:39:07 by balnahdi          #+#    #+#             */
/*   Updated: 2022/02/22 16:39:08 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	checkswap100(t_pushswap *pushswap)
{
	if (pushswap->stacka[pushswap->topa] > pushswap->stacka[pushswap->topa - 1])
		swapa(pushswap);
	write(1, "sa\n", 3);
}

void	init_b100(t_pushswap *pushswap)
{
	pushswap->scanb = pushswap->topb;
	pushswap->lensort = pushswap->topb;
}

void	upperstack(t_pushswap *pushswap)
{
	while (pushswap->scanb < pushswap->topb)
	{
		rotb(pushswap);
		write(1, "rb\n", 3);
		pushswap->scanb++;
	}
	if (pushswap->scanb == pushswap->topb && \
	pushswap->stackb[pushswap->scanb] == pushswap->sorted[pushswap->topb])
	{
		pusha(pushswap);
		write(1, "pa\n", 3);
		pushswap->scanb = pushswap->topb;
		pushswap->divb = pushswap->topb / 2;
	}
}

void	lowerstack(t_pushswap *pushswap)
{
	while (pushswap->scanb > -1 && pushswap->stackb[pushswap->scanb] \
	== pushswap->sorted[pushswap->topb])
	{
		revrotb(pushswap);
		write(1, "rrb\n", 4);
		pushswap->scanb--;
	}
	pushswap->scanb = pushswap->topb;
	if (pushswap->scanb == pushswap->topb && \
	pushswap->stackb[pushswap->scanb] == pushswap->sorted[pushswap->topb])
	{
		pusha(pushswap);
		write(1, "pa\n", 3);
		pushswap->scanb = pushswap->topb;
		pushswap->divb = pushswap->topb / 2;
	}
}

void	check_mov100(t_pushswap *pushswap)
{
	if (pushswap->scanb >= pushswap->divb)
	{
		upperstack(pushswap);
	}
	else if (pushswap->scanb < pushswap->divb)
	{
		lowerstack(pushswap);
	}
}
