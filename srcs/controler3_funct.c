/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controler3_funct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:51:09 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/03 18:27:12 by hmateque         ###   ########.fr       */
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
	ft_rra(a);
	ft_rrb(b);
	write(1, "rrr\n", 4);
}