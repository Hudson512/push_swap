/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:39:24 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/14 06:22:34 by hmateque         ###   ########.fr       */
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
		return (2); // rev_rot
	else
		return (1); // rot
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
}

int	get_stack_b_step(int nbr, t_list *head)
{
	t_list *p_b;
	int		target;
	int		index_node;
	int		size_list;

	p_b = head;
	target = 0;
	size_list = count_list(head);
	while (p_b)
	{
		if (p_b->data < nbr){
			if (p_b->data > target)
				target = p_b->data;
		}
		else if (p_b->data > nbr){
			if (p_b->data > target)
				target = p_b->data;
		}
		p_b = p_b->next;
	}
	index_node = find_node_index(head, target);
	if (ft_rot_or_rrot(target, head) == 1)
		return (index_node);
	else if (ft_rot_or_rrot(target, head) == 2)
		return (size_list - index_node);
}