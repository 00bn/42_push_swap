/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:39:29 by balnahdi          #+#    #+#             */
/*   Updated: 2022/02/22 16:39:30 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	printstacka(t_pushswap *pushswap)
{
	int	j;
	int	k;

	j = pushswap->lena - 1;
	k = pushswap->lena - 1;
	printf("\n");
	printf("STACK A\n");
	while (j > -1)
	{
		if (k > -1)
			printf("arr index[%d]=%d\n", k, pushswap->stacka[k]);
		k--;
		j--;
	}
}

void	printstackb(t_pushswap *pushswap)
{
	int	j;
	int	k;

	k = pushswap->topb;
	j = pushswap->topb;
	printf("\n");
	printf("STACK B\n");
	while (j >= 0)
	{
		if (k >= 0)
			printf("arr index[%d]=%d\n", k, pushswap->stackb[k]);
		k--;
		j--;
	}
}

void	printsorted(t_pushswap *pushswap)
{
	int	j;
	int	k;

	j = pushswap->topa;
	k = pushswap->topa;
	printf("\n");
	printf("STACK SORTED\n");
	while (j >= 0)
	{
		if (k >= 0)
			printf("SORTED index[%d]=%d\n", k, pushswap->sorted[k]);
		k--;
		j--;
	}
}
