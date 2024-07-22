/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:25:36 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/22 15:40:47 by hmateque         ###   ########.fr       */
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
		if (!isdigit(str[i]) || str[i + 1] == '+' || str[i + 1] == '-')
			return (0);
		i++;
	}
	return 1;
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
	int	i;
	int	count_p;
	t_list	*a;
	t_list	*b;
	
	if (argc > 1)
	{
		a = NULL;
		b = NULL;
		i = 1;
		while (i < argc)
		{
			if (!is_number(argv[i]))
				print_error();
			count_p = checker_num_palavra(argv[i]);
			if (count_p == 1)
				pre_add(&a, argv[i]);
			else if (count_p > 1)
				pre_add_2(&a, argv[i], count_p);
			i++;
		}
		
		if (checker_order_list(a) == 1)
		{
			check_and_exec(&a, &b);
			while (count_list(a) >= 3 && checker_order_list(a) == 1)
				ft_ordering_b(&a, &b);
			if (checker_order_list_2(b) == 1)
			{
				int value_max = find_max(b);
				while (checker_order_list_2(b) ==  1)
					order_stack(value_max, &b);
			}
			ft_ordering_a(&b, &a);
			if (checker_order_list(a) == 1){
				int value_min = find_min(a);
				while (checker_order_list(a) ==  1)
					order_stack_a(value_min, &a);
			}
		}
		if (checker_order_list(a)){
			int value_min = find_min(a);
			while (checker_order_list(a) ==  1)
				order_stack_a(value_min, &a);
		}
		libera_stack(&a);
		libera_stack(&b);
	}
	return 0;
}