/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller3_funct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:51:09 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/24 09:18:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_rra(t_list **head)
{
	ft_reverse_rotate(head);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_list **head)
{
	ft_reverse_rotate(head);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **a, t_list **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, "rrr\n", 4);
}
