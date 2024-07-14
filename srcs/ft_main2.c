/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:10:58 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/14 07:44:28 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_ordering(t_list **a, t_list **b)
{
	t_list	*p_a;
	int		num_barato;

	p_a = *a;
	if (count_list(p_a) == 3)
	{
		if (checker_order_list(p_a)){
			if (p_a->data > p_a->next->data && p_a->next->data > p_a->next->next->data)
			{
				ft_ra(a);
				ft_sa(a);
			}
			else if ((p_a->data < p_a->next->data && p_a->data < p_a->next->next->data) 
				&& (p_a->next->data > p_a->next->next->data))
			{
				ft_rra(a);
				ft_sa(a);
			}
			else if (p_a->data > p_a->next->data && p_a->data < p_a->next->next->data)
			{
				ft_sa(a);
			}
			else if (p_a->data < p_a->next->data && p_a->data > p_a->next->next->data)
			{
				ft_rra(a);
			}
			else if (p_a->data > p_a->next->data && p_a->next->data < p_a->next->next->data)
			{
				ft_ra(a);
			}
		}
	}
	else
	{
		if (count_list(*b) == 0)
		{
			ft_push(a, b);
			ft_push(a, b);
		}
		num_barato = ft_num_barato(a, b);
	}
}

int		ft_num_barato(t_list **a, t_list **b)
{
	t_list *temp;
	int		barato_a;
	int		num_barato;

	temp = *a;
	while (temp)
	{
		temp->num_oper_a = get_stack_a_step(temp->data, *a);
		temp->num_oper_b = get_stack_b_step(temp->data, *b);
		temp = temp->next;
	}
	temp = *a;
	barato_a = temp->num_oper_a + temp->num_oper_b;
	num_barato = temp->data;
	temp = temp->next;
	while (temp)
	{
		if ((temp->num_oper_a + temp->num_oper_b) < barato_a)
		{
			barato_a = (temp->num_oper_a + temp->num_oper_b);
			num_barato = temp->data;
		}
		temp = temp->next;
	}
	return (num_barato);
}