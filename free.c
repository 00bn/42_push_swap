/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:18:59 by balnahdi          #+#    #+#             */
/*   Updated: 2022/02/22 17:19:47 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_split(char **str, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free(t_pushswap *pushswap)
{
	free(pushswap->stacka);
	free(pushswap->stackb);
	free(pushswap->sorted);
}

void	ft_free_end(t_pushswap *pushswap)
{
	free(pushswap->stacka);
}
