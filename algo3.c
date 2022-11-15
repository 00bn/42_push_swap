/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:38:47 by balnahdi          #+#    #+#             */
/*   Updated: 2022/02/22 18:59:21 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	algo3div(t_pushswap *pushswap)
{
	if (pushswap->stacka[pushswap->topa] < pushswap->stacka[0] && \
		pushswap->stacka[pushswap->topa] \
		 > pushswap->stacka[pushswap->topa - 1])
	{
		swapa(pushswap);
		write(1, "sa\n", 3);
	}
	if (pushswap->stacka[pushswap->topa] > \
			pushswap->stacka[pushswap->topa - 1] \
			&& pushswap->stacka[pushswap->topa] > pushswap->stacka[0])
	{
		rota(pushswap);
		write(1, "ra\n", 3);
		if (pushswap->stacka[pushswap->topa] < \
			pushswap->stacka[0] && pushswap->stacka[pushswap->topa] > \
			pushswap->stacka[pushswap->topa - 1])
		{
			swapa(pushswap);
			write(1, "sa\n", 3);
		}
	}
}

void	algo3(t_pushswap *pushswap)
{
	if (pushswap->stacka[pushswap->topa] > \
			 pushswap->stacka[pushswap->topa - 1] || \
			pushswap->stacka[pushswap->topa] < pushswap->stacka[0])
	{
		algo3div(pushswap);
	}
	if (pushswap->stacka[pushswap->topa - 1] > \
		pushswap->stacka[pushswap->topa] && \
			pushswap->stacka[pushswap->topa - 1] > pushswap->stacka[0])
	{
		revrota(pushswap);
		write(1, "rra\n", 4);
		if (pushswap->stacka[pushswap->topa] > \
		pushswap->stacka[pushswap->topa - 1])
		{
			swapa(pushswap);
			write(1, "sa\n", 3);
		}
	}
}
