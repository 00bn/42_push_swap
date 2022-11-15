/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:39:47 by balnahdi          #+#    #+#             */
/*   Updated: 2022/02/22 17:16:39 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rota(t_pushswap *pushswap)
{
	int	temp;
	int	i;

	temp = pushswap->stacka[pushswap->topa];
	i = 0;
	while (i < pushswap->topa)
	{
		pushswap->stacka[pushswap->topa - i] = \
		pushswap->stacka[pushswap->topa - (i + 1)];
		i++;
	}
	pushswap->stacka[0] = temp;
}

void	rotb(t_pushswap *pushswap)
{
	int	temp;
	int	i;

	temp = pushswap->stackb[pushswap->topb];
	i = 0;
	while (i < pushswap->topb)
	{
		pushswap->stackb[pushswap->topb - i] = \
		pushswap->stackb[pushswap->topb - (i + 1)];
		i++;
	}
	pushswap->stackb[0] = temp;
}

void	rot2(t_pushswap *pushswap)
{
	rota(pushswap);
	rotb(pushswap);
}
