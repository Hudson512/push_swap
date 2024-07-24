/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:05:45 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/24 16:36:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_rot_or_rrot(int value, t_list *head)
{
	int	size_list;
	int	index_node;

	size_list = count_list(head);
	index_node = find_node_index(head, value);
	if ((index_node > (size_list / 2)) || (index_node + 1 == size_list))
		return (2);
	else
		return (1);
}

int	get_stack_a_step(int value, t_list *head)
{
	int	index_node;
	int	size_list;

	size_list = count_list(head);
	index_node = find_node_index(head, value);
	if (value == head->data)
		return (1);
	if (ft_rot_or_rrot(value, head) == 1)
		return (index_node + 1);
	else if (ft_rot_or_rrot(value, head) == 2)
		return (size_list - index_node + 1);
	return (0);
}

int	get_stack_b_step(int nbr, t_list *head)
{
	t_list	*p_b;
	int		target;
	int		index_node;

	p_b = head;
	target = 0;
	while (p_b)
	{
		if (p_b->data < nbr)
		{
			if (p_b->data > target)
				target = p_b->data;
		}
		p_b = p_b->next;
	}
	if (target != 0)
	{
		index_node = find_node_index(head, target);
		return (move_rot_or_rrot(head, target, index_node));
	}
	else
		return (move_rot_or_rrot_2(head, target, 0));
	return (0);
}

void	move_stack_a_step(int value, int m_a, t_list **a, t_list **b)
{
	while (m_a != 0)
	{
		if (value == (*a)->data)
			ft_pb(a, b);
		else if (ft_rot_or_rrot(value, *a) == 1)
			ft_ra(a);
		else if (ft_rot_or_rrot(value, *a) == 2)
			ft_rra(a);
		m_a--;
	}
}

void	move_stack_b_step(int nbr, int m_b, t_list **b)
{
	t_list	*p_b;
	int		target;

	p_b = *b;
	target = 0;
	while (p_b)
	{
		if (p_b->data < nbr)
		{
			if (p_b->data > target)
				target = p_b->data;
		}
		p_b = p_b->next;
	}
	while (m_b != 0)
	{
		if (target != 0)
			move_rot_or_rrot_3(target, b);
		else
		{
			target = find_max(*b);
			move_rot_or_rrot_3(target, b);
		}
		m_b--;
	}
}
