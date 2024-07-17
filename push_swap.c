/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:25:36 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/17 12:37:14 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	nb;

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

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	count_p;
	char	**arr;
	t_list	*a;
	t_list	*b;
	
	if (argc > 1){
		a = NULL;
		b = NULL;
		i = 1;
		while (i < argc)
		{
			count_p = checker_num_palavra(argv[i]);
			if (count_p == 1)
			{
				if (checker_num_dup(a, ft_atoi(argv[i])))
					add_list_next(&a, ft_atoi(argv[i]));	
			}
			else if (count_p > 1)
			{
				arr = ft_split(argv[i], 32);
				j = 0;
				while (j < count_p)
				{
					if (checker_num_dup(a, ft_atoi(arr[j])))
						add_list_next(&a, ft_atoi(arr[j]));
					j++;
				}
			}
			i++;
		}
		if (checker_order_list(a) == 1)
		{
			if (count_list(a) > 3)
			{
				ft_pb(&a, &b);
				ft_pb(&a, &b);
			}
			
			while (count_list(a) >= 3 && checker_order_list(a) == 1)
				ft_ordering_b(&a, &b);
			if (checker_order_list_2(b) == 1)
			{
				int value_max = find_max(b);
				while (checker_order_list_2(b) ==  1)
					order_stack(value_max, &b);
			}
			// printf("Pilha a\n");
			// print_list(a);
			// printf("Pilha b\n");
			// print_list(b);
			ft_ordering_a(&b, &a);
			if (checker_order_list(a) == 1){
				int value_min = find_min(a);
				while (checker_order_list(a) ==  1)
					order_stack_a(value_min, &a);
			}
		}
		// printf("Pilha a\n");
		// print_list(a);
		// printf("Pilha b\n");
		// print_list(b);
		if (checker_order_list(a)){
			int value_min = find_min(a);
			while (checker_order_list(a) ==  1)
				order_stack_a(value_min, &a);
		}
		// printf("Pilha a\n");
		// print_list(a);
		// printf("Pilha b\n");
		// print_list(b);
		// else
		// 	printf("Nao Ordenado\n");
	}
	return 0;
}