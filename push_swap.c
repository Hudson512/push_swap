/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:25:36 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/11 12:41:13 by hmateque         ###   ########.fr       */
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
	while (str[i] < 33)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	nb = 0;
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
		if (checker_order_list(a))
			ft_ordering(&a, &b);
		else
			printf("Verif_ordem_list - Ordenada\n");
		printf("Pilha a\n");
		print_list(a);
		printf("Pilha b\n");
		print_list(b);
	}
	return 0;
}