/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:39:15 by balnahdi          #+#    #+#             */
/*   Updated: 2022/02/22 20:57:41 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_arg(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == ' ' || str[i + 1] == '\0')
			return (0);
		i++;
	}	
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	check_sorted(t_pushswap *pushswap)
{
	int	i;
	int	j;
	int	k;

	i = pushswap->topa;
	j = 0;
	k = pushswap->topa;
	while (k > -1)
	{
		if (pushswap->stacka[i] == pushswap->sorted[j])
		{
			if (j == pushswap->topa)
			{
				ft_free(pushswap);
				exit (0);
			}
			j++;
			i--;
		}
		k--;
	}
}

int	check(int num, int *arr, int i)
{
	int	k;

	k = 0;
	while (k < i)
	{
		if (num == arr[k])
			return (1);
		k++;
	}
	return (0);
}

int	is_dup(t_pushswap *pushswap)
{
	int	i;

	i = 0;
	while (i < pushswap->lena)
	{
		if (check(pushswap->stacka[i], pushswap->stacka, i))
			return (1);
		i++;
	}
	return (0);
}
