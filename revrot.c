/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:39:43 by balnahdi          #+#    #+#             */
/*   Updated: 2022/02/22 16:39:44 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	revrota(t_pushswap *pushswap)
{
	int	i;
	int	temp;

	temp = pushswap->stacka[0];
	i = 0;
	while (i < pushswap->topa)
	{
		pushswap->stacka[i] = pushswap->stacka[i + 1];
		i++;
	}
	pushswap->stacka[pushswap->topa] = temp;
}

void	revrotb(t_pushswap *pushswap)
{
	int	i;
	int	temp;

	temp = pushswap->stackb[0];
	i = 0;
	while (i < pushswap->topb)
	{
		pushswap->stackb[i] = pushswap->stackb[i + 1];
		i++;
	}
	pushswap->stackb[pushswap->topb] = temp;
}

void	revrot2(t_pushswap *pushswap)
{
	revrota(pushswap);
	revrotb(pushswap);
}
