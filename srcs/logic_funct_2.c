/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_funct_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:01:50 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/24 14:03:20 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	get_stack_b_step_2(int nbr, t_list *head)
{
	t_list	*p_b;
	int		target;
	int		index_node;
	int		size_list;

	p_b = head;
	target = 1000;
	size_list = count_list(head);
	while (p_b)
	{
		if (p_b->data > nbr)
		{
			if (p_b->data < target)
				target = p_b->data;
		}
		p_b = p_b->next;
	}
	if (target != 0)
	{
		index_node = find_node_index(head, target);
		if (ft_rot_or_rrot(target, head) == 1)
			return (index_node);
		else if (ft_rot_or_rrot(target, head) == 2)
			return (size_list - index_node);
	}
	else
	{
		target = find_max(head);
		index_node = find_node_index(head, target);
		if (ft_rot_or_rrot(target, head) == 1)
			return (index_node);
		else if (ft_rot_or_rrot(target, head) == 2)
			return (size_list - index_node);
	}
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
	target = 1000;
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
		{
			ft_ra(a);
		}
		else if (ft_rot_or_rrot(target, *a) == 2)
		{
			ft_rra(a);
		}
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
