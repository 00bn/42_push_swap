/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:38:53 by balnahdi          #+#    #+#             */
/*   Updated: 2022/02/22 16:38:54 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(t_pushswap *pushswap)
{
	int	i;
	int	check;

	check = 0;
	i = 0;
	while (pushswap->topa >= i)
	{
		if (pushswap->sorted[i] == pushswap->stacka[i])
		{	
			check += check;
		}
		else
			check += 1;
		i++;
	}
	if (check != 0)
		return (1);
	if (check == 0)
		return (0);
	return (2);
}

void	check_stackb(t_pushswap *pushswap)
{
	int	first;

	first = pushswap->sorted[0];
	if (pushswap->lena == 5)
	{
		if (pushswap->stackb[pushswap->topb] == first && pushswap->topb == 1)
		{
			swapb(pushswap);
			write(1, "sb\n", 3);
		}
		pusha(pushswap);
		write(1, "pa\n", 3);
		pusha(pushswap);
		write(1, "pa\n", 3);
	}
	else if (pushswap->topb == 0 && is_sorted(pushswap) == 0)
	{
		pusha(pushswap);
		write(1, "pa\n", 3);
	}
	else
		algo3(pushswap);
}

void	check_mini_num(t_pushswap *pushswap)
{
	int	first;
	int	second;
	int	i;
	int	j;

	first = pushswap->sorted[0];
	second = pushswap->sorted[1];
	i = pushswap->topa + 1;
	j = 0;
	while (i-- > -1 && j < 2)
	{
		if (first == pushswap->stacka[pushswap->topa] || \
		second == pushswap->stacka[pushswap->topa])
		{
			pushb(pushswap);
			write(1, "pb\n", 3);
			j++;
		}
		else
		{
			rota(pushswap);
			write(1, "ra\n", 3);
		}
	}
}

void	algo5(t_pushswap *pushswap)
{
	check_mini_num(pushswap);
	if (pushswap->topa == 2)
		algo3(pushswap);
	if (pushswap->topb == 0 || pushswap->topb == 1)
		check_stackb(pushswap);
}
