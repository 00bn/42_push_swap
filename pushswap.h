/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:22:20 by badriah           #+#    #+#             */
/*   Updated: 2022/02/22 20:56:49 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include	"./libft/libft.h"
# include	<stdio.h>
# include	<unistd.h>
# include	<sys/types.h>
# include	<sys/uio.h>
# include	<stdlib.h>
# include	<sys/wait.h>
# include	<fcntl.h>
# include	<errno.h>

typedef struct s_pushswap
{
	int	lena;
	int	*stacka;
	int	topa;
	int	*stackb;
	int	topb;
	int	*sorted;
	int	median;
	int	arrow;
	int	contra;
	int	scanb;
	int	divb;
	int	lensort;
	int	chunk500;
	int	*tmp;
}t_pushswap;

//free
void	ft_free(t_pushswap *pushswap);
void	ft_free_end(t_pushswap *pushswap);
void	free_split(char **str, int j);
//checkers
int		check_arg(char *str);
void	check_sorted(t_pushswap *pushswap);
int		check(int num, int *arr, int i);
int		is_dup(t_pushswap *pushswap);
//init
void	init_structure(t_pushswap *pushswap);
//main work_split
void	do_args_work(t_pushswap *pushswap, char *argv[]);
void	do_str_work(t_pushswap *pushswap, char **str);
//create
int		*creat_stack_argv(t_pushswap *pushswap, char *argv[]);
int		*creat_stack_str(t_pushswap *pushswap, char **str);

//operations
void	swapa(t_pushswap *pushswap);
void	swapb(t_pushswap *pushswap);
void	pushb(t_pushswap *pushswap);
void	pusha(t_pushswap *pushswap);
void	rota(t_pushswap *pushswap);
void	rotb(t_pushswap *pushswap);
void	rot2(t_pushswap *pushswap);
void	revrota(t_pushswap *pushswap);
void	revrotb(t_pushswap *pushswap);
void	revrot2(t_pushswap *pushswap);
//sort
void	dupstack(t_pushswap *pushswap);
int		*sort(int **unsorted, int low, int high);
int		partition(int *unsorted, int low, int high);
void	ft_swap(int *i, int *j);

//helpers
void	printstacka(t_pushswap *pushswap);
void	printstackb(t_pushswap *pushswap);
void	printsorted(t_pushswap *pushswap);

//algos
//3
void	select_algo(t_pushswap *pushswap);
void	algo3(t_pushswap *pushswap);
void	algo3div(t_pushswap *pushswap);
//5
void	check_mini_num(t_pushswap *pushswap);
void	algo5(t_pushswap *pushswap);
void	check_stackb(t_pushswap *pushswap);
int		is_sorted(t_pushswap *pushswap);
//100
void	algo100(t_pushswap *pushswap);
void	sendto_b100(t_pushswap *pushswap);
void	divb100(t_pushswap *pushswap);
void	checkswap(t_pushswap *pushswap);
void	scan_b100(t_pushswap *pushswap);
void	check_mov100(t_pushswap *pushswap);
void	upperstack(t_pushswap *pushswap);
void	lowerstack(t_pushswap *pushswap);
void	checkswap100(t_pushswap *pushswap);
void	init_b100(t_pushswap *pushswap);
void	re_init100(t_pushswap *pushswap);
//500
void	algo500(t_pushswap *pushswap);
void	sendto_b(t_pushswap *pushswap);
void	divb(t_pushswap *pushswap);
void	checkswap(t_pushswap *pushswap);
void	scan_b(t_pushswap *pushswap);
void	check_mov(t_pushswap *pushswap);
void	init_b(t_pushswap *pushswap);
void	re_init(t_pushswap *pushswap);
void	lowerstack500(t_pushswap *pushswap);
void	upperstack500(t_pushswap *pushswap);
#endif