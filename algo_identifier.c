/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_identifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:38:42 by balnahdi          #+#    #+#             */
/*   Updated: 2022/02/22 16:38:43 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	select_algo(t_pushswap *pushswap)
{
	if (pushswap->lena == 1)
	{
		ft_free(pushswap);
		exit (0);
	}	
	else if (pushswap->lena == 2)
	{
		swapa(pushswap);
		write(1, "sa\n", 3);
	}	
	else if (pushswap->lena == 3)
		algo3(pushswap);
	else if (pushswap->lena == 5)
		algo5(pushswap);
	else if (pushswap->lena == 500)
		algo500(pushswap);
	else
		algo100(pushswap);
}
