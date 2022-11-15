/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:39:50 by balnahdi          #+#    #+#             */
/*   Updated: 2022/02/22 16:39:51 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_swap(int *i, int *j)
{
	int	temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

int	partition(int *unsorted, int low, int high)
{
	int	piv;
	int	i;
	int	j;

	piv = unsorted[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (unsorted[j] < piv)
		{
			i++;
			ft_swap(&unsorted[i], &unsorted[j]);
		}
		j++;
	}
	ft_swap(&unsorted[i + 1], &unsorted[j]);
	return (i + 1);
}

int	*sort(int **unsorted, int low, int high)
{
	int	piv;

	if (low < high)
	{
		piv = partition(*unsorted, low, high);
		sort(unsorted, low, piv - 1);
		sort(unsorted, piv + 1, high);
	}
	return (*unsorted);
}

void	dupstack(t_pushswap *pushswap)
{
	int	*unsorted;
	int	len;
	int	high;

	len = pushswap->lena - 1;
	high = len;
	unsorted = (int *)malloc(sizeof(int) * pushswap->lena);
	while (len >= 0)
	{
		if (len >= 0)
		{
			unsorted[len] = pushswap->stacka[len];
		}
		len--;
	}
	len ++;
	pushswap->sorted = sort(&unsorted, len, high);
	pushswap->chunk500 = pushswap->lena / 11;
	pushswap->median = pushswap->lena / 2;
}
