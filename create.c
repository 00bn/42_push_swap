/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:39:21 by balnahdi          #+#    #+#             */
/*   Updated: 2022/02/22 16:39:26 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_structure(t_pushswap *pushswap)
{
	pushswap->lena = 0;
	pushswap->stacka = NULL;
	pushswap->topa = -1;
	pushswap->topb = -1;
	pushswap->contra = 0;
	pushswap->chunk500 = 0;
}

int	*creat_stack_argv(t_pushswap *pushswap, char *argv[])
{
	int	intnum;
	int	len;
	int	i;

	len = pushswap->lena - 1;
	i = 1;
	pushswap->stacka = (int *)malloc(sizeof(int) *(pushswap->lena));
	pushswap->stackb = (int *)malloc(sizeof(int) *(pushswap->lena));
	while (argv[i])
	{
		if (argv[i] && len >= 0)
		{
			intnum = ft_atoi(argv[i]);
			pushswap->stacka[len] = intnum;
		}
		i++;
		len--;
	}
	pushswap->topa = pushswap->lena - 1;
	return (pushswap->stacka);
}

int	*creat_stack_str(t_pushswap *pushswap, char **str)
{
	int	i;
	int	intnum;
	int	len;

	len = pushswap->lena - 1 ;
	i = 0;
	pushswap->stacka = (int *)malloc(sizeof(int) *(pushswap->lena));
	pushswap->stackb = (int *)malloc(sizeof(int) *(pushswap->lena));
	while (str[i])
	{
		if (str[i] && len >= 0)
		{
			intnum = ft_atoi(str[i]);
			pushswap->stacka[len] = intnum;
		}
		i++;
		len--;
	}
	pushswap->topa = pushswap->lena - 1;
	return (pushswap->stacka);
}
