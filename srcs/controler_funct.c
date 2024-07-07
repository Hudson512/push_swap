/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controler_funct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:51:09 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/07 13:49:57 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_sa(t_list **head)
{
	ft_swap(head);
	write(1, "sa\n", 3);
}

void	ft_sb(t_list **head)
{
	ft_swap(head);
	write(1, "sb\n", 3);
}

void	ft_ss(t_list **a, t_list **b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}

void	ft_pa(t_list **b, t_list **a)
{
	ft_push(b, a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_list **a, t_list **b)
{
	ft_push(a, b);
	write(1, "pb\n", 3);
}
