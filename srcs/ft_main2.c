/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:10:58 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/24 09:11:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_ordering_b(t_list **a, t_list **b)
{
	t_list	*p_a;
	t_list	*p_b;
	int		num_barato;

	if (count_list(*a) == 3)
		move_list(a);
	else if (count_list(*a) > 3)
	{
		num_barato = ft_num_barato(a, b);
		p_a = *a;
		while (p_a)
		{
			if (p_a->data == num_barato)
				p_b = p_a;
			p_a = p_a->next;
		}
		move_stack_b_step(p_b->data, p_b->num_oper_b, b);
		move_stack_a_step(p_b->data, p_b->num_oper_a, a, b);
	}
}

void	ft_ordering_a(t_list **b, t_list **a)
{
	t_list	*p_a;
	t_list	*p_b;
	int		num_barato;
	
	if (count_list(*b) > 0)
	{
		num_barato = ft_num_barato_2(b, a);
		p_a = *b;
		while (p_a)
		{
			if (p_a->data == num_barato)
				p_b = p_a;
			p_a = p_a->next;
		}
		move_stack_b_step_2(p_b->data, p_b->num_oper_b, a);
		move_stack_a_step_2(p_b->data, p_b->num_oper_a, b, a);
		ft_ordering_a(b, a);
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

int		ft_num_barato_2(t_list **a, t_list **b)
{
	t_list *temp;
	int		barato_a;
	int		num_barato;

	temp = *a;
	while (temp)
	{
		temp->num_oper_a = get_stack_a_step(temp->data, *a);
		temp->num_oper_b = get_stack_b_step_2(temp->data, *b);
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