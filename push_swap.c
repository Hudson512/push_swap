/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:25:36 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/24 16:59:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	if (str == NULL)
		return (0);
	while (str[i] < 33)
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * sign);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		while (str[i] == 32 || str[i] == '\t')
			i++;
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (!ft_isdigit(str[i]) || str[i + 1] == '+' || str[i + 1] == '-')
			return (0);
		i++;
	}
	return (1);
}

int	value_limit(long nbr)
{
	if (nbr > 2147483647 || nbr < INT_MIN)
		print_error();
	return (1);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		count_p;
	t_list	*a;
	t_list	*b;

	if (argc > 1)
	{
		a = NULL;
		b = NULL;
		i = 0;
		while (++i < argc)
		{
			if (!is_number(argv[i]))
				print_error();
			count_p = checker_num_palavra(argv[i]);
			if (count_p == 1)
				pre_add(&a, argv[i]);
			else if (count_p > 1)
				pre_add_2(&a, argv[i], count_p);
		}
		screening_funct(&a, &b, 0, 0);
		libera_stack(&a);
		libera_stack(&b);
	}
	return (0);
}
