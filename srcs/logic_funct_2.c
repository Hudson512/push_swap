/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_funct_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:01:50 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/24 16:09:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	get_stack_b_step_2(int nbr, t_list *head)
{
	t_list	*p_b;
	int		target;
	int		index_node;

	p_b = head;
	target = INT_MAX;
	while (p_b)
	{
		if (p_b->data > nbr)
		{
			if (p_b->data < target)
				target = p_b->data;
		}
		p_b = p_b->next;
	}
	if (target != INT_MAX)
	{
		index_node = find_node_index(head, target);
		return (move_rot_or_rrot(head, target, index_node));
	}
	else
		return (move_rot_or_rrot_4(head, target, 0));
	return (0);
}

void	move_stack_a_step_2(int value, int m_a, t_list **b, t_list **a)
{
	while (m_a != 0)
	{
		if (value == (*b)->data)
			ft_pa(b, a);
		else if (ft_rot_or_rrot(value, *b) == 1)
			ft_rb(b);
		else if (ft_rot_or_rrot(value, *b) == 2)
			ft_rrb(b);
		m_a--;
	}
}

void	move_stack_b_step_2(int nbr, int m_b, t_list **a)
{
	t_list	*p_b;
	int		target;

	p_b = *a;
	target = INT_MAX;
	while (p_b)
	{
		if (p_b->data > nbr)
		{
			if (p_b->data < target)
				target = p_b->data;
		}
		p_b = p_b->next;
	}
	while (m_b != 0)
	{
		if (ft_rot_or_rrot(target, *a) == 1)
			ft_ra(a);
		else if (ft_rot_or_rrot(target, *a) == 2)
			ft_rra(a);
		m_b--;
	}
}

void	order_stack(int nbr, t_list **b)
{
	if (ft_rot_or_rrot(nbr, *b) == 1)
		ft_rb(b);
	else if (ft_rot_or_rrot(nbr, *b) == 2)
		ft_rrb(b);
}

void	order_stack_a(int nbr, t_list **b)
{
	if (ft_rot_or_rrot(nbr, *b) == 1)
		ft_ra(b);
	else if (ft_rot_or_rrot(nbr, *b) == 2)
		ft_rra(b);
}
