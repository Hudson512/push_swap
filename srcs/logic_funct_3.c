/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_funct_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:41:21 by codespace         #+#    #+#             */
/*   Updated: 2024/07/24 16:37:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	move_rot_or_rrot(t_list *head, int target, int index_node)
{
	int	size_list;

	size_list = count_list(head);
	if (ft_rot_or_rrot(target, head) == 1)
		return (index_node);
	else if (ft_rot_or_rrot(target, head) == 2)
		return (size_list - index_node);
	return (0);
}

int	move_rot_or_rrot_2(t_list *head, int target, int index_node)
{
	int	size_list;

	size_list = count_list(head);
	target = find_max(head);
	index_node = find_node_index(head, target);
	if (ft_rot_or_rrot(target, head) == 1)
		return (index_node);
	else if (ft_rot_or_rrot(target, head) == 2)
		return (size_list - index_node);
	return (0);
}

void	move_rot_or_rrot_3(int target, t_list **b)
{
	if (ft_rot_or_rrot(target, *b) == 1)
		ft_rb(b);
	else if (ft_rot_or_rrot(target, *b) == 2)
		ft_rrb(b);
}

int	move_rot_or_rrot_4(t_list *head, int target, int index_node)
{
	int	size_list;

	size_list = count_list(head);
	target = find_min(head);
	index_node = find_node_index(head, target);
	if (ft_rot_or_rrot(target, head) == 1)
		return (index_node);
	else if (ft_rot_or_rrot(target, head) == 2)
		return (size_list - index_node);
	return (0);
}
