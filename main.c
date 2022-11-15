/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:39:33 by balnahdi          #+#    #+#             */
/*   Updated: 2022/02/22 20:57:29 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_str_work(t_pushswap *pushswap, char **str)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++])
			pushswap->lena++;
	creat_stack_str(pushswap, str);
	dupstack(pushswap);
	if (is_dup(pushswap))
	{
		ft_free(pushswap);
		write (1, "Error\n", 7);
		exit (0);
	}
	free_split(str, i);
	check_sorted(pushswap);
	select_algo(pushswap);
	ft_free(pushswap);
}

int	check_string_num(char *argv[])
{
	t_pushswap	pushswap;
	int			i;
	int			isnumber;
	char		**str;

	init_structure(&pushswap);
	i = 0;
	str = ft_split(argv[1], ' ');
	isnumber = check_arg(str[i++]);
	while (str[i] && isnumber == 1)
	{
		isnumber = check_arg(str[i]);
		i++;
	}
	if (isnumber == 1)
	{
		do_str_work(&pushswap, str);
	}
	else
	{
		write(1, "Error\n", 7);
		ft_free_end(&pushswap);
		exit(1);
	}
	return (0);
}

void	do_args_work(t_pushswap *pushswap, char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
		if (argv[i++])
			pushswap->lena++;
	creat_stack_argv(pushswap, argv);
	dupstack(pushswap);
	if (is_dup(pushswap))
	{
		write(1, "Error\n", 7);
		ft_free(pushswap);
		exit (0);
	}
	check_sorted(pushswap);
	select_algo(pushswap);
	ft_free(pushswap);
}

int	check_argv_num(char *argv[])
{
	t_pushswap	pushswap;
	int			isnumber;
	int			i;

	init_structure(&pushswap);
	i = 1;
	isnumber = check_arg(argv[i++]);
	while (argv[i] && isnumber == 1)
	{
		isnumber = check_arg(argv[i]);
		i++;
	}
	if (isnumber == 1)
		do_args_work(&pushswap, argv);
	else
	{
		write(1, "Error\n", 7);
		ft_free_end(&pushswap);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc == 2 || argc > 2)
	{
		if (argc == 2)
		{
			if (argv[1][0] == '\0')
				exit (0);
			check_string_num(argv);
		}
		else
			check_argv_num(argv);
	}
	else
		exit (0);
}
