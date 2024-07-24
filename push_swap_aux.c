/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:39:47 by codespace         #+#    #+#             */
/*   Updated: 2024/07/24 16:58:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	screening_funct(t_list **a, t_list **b, int value_max, int value_min)
{
	if (checker_order_list(*a) == 1)
	{
		check_and_exec(a, b);
		while (count_list(*a) >= 3 && checker_order_list(*a) == 1)
			ft_ordering_b(a, b);
		if (checker_order_list_2(*b) == 1)
		{
			value_max = find_max(*b);
			while (checker_order_list_2(*b) == 1)
				order_stack(value_max, b);
		}
		ft_ordering_a(b, a);
		if (checker_order_list(*a) == 1)
		{
			value_min = find_min(*a);
			while (checker_order_list(*a) == 1)
				order_stack_a(value_min, a);
		}
	}
	if (checker_order_list(*a))
	{
		value_min = find_min(*a);
		while (checker_order_list(*a) == 1)
			order_stack_a(value_min, a);
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
