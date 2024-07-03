/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controler2_funct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:51:09 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/03 17:49:19 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_ra(t_list **head)
{
	ft_rotate(head);
	write(1, "ra\n", 3);
}

void	ft_rb(t_list **head)
{
	ft_rotate(head);
	write(1, "rb\n", 3);
}

void	ft_rr(t_list **a, t_list **b)
{
	ft_ra(a);
	ft_rb(b);
	write(1, "rr\n", 3);
}