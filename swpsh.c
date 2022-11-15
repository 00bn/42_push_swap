/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swpsh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:39:54 by balnahdi          #+#    #+#             */
/*   Updated: 2022/02/22 16:39:55 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swapa(t_pushswap *pushswap)
{
	int	temp;

	temp = pushswap->stacka[pushswap->topa];
	pushswap->stacka[pushswap->topa] = pushswap->stacka[pushswap->topa - 1];
	pushswap->stacka[pushswap->topa - 1] = temp;
}

void	swapb(t_pushswap *pushswap)
{
	int	temp;

	temp = pushswap->stackb[pushswap->topb];
	pushswap->stackb[pushswap->topb] = pushswap->stackb[pushswap->topb - 1];
	pushswap->stackb[pushswap->topb - 1] = temp;
}

void	pushb(t_pushswap *pushswap)
{
	pushswap->topb++;
	pushswap->stackb[pushswap->topb] = pushswap->stacka[pushswap->topa];
	pushswap->stacka[pushswap->topa] = 0;
	pushswap->topa--;
}

void	pusha(t_pushswap *pushswap)
{
	pushswap->topa++;
	pushswap->stacka[pushswap->topa] = pushswap->stackb[pushswap->topb];
	pushswap->stackb[pushswap->topb] = 0;
	pushswap->topb--;
}
