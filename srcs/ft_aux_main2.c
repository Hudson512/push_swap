/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_main2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:05:52 by codespace         #+#    #+#             */
/*   Updated: 2024/07/24 15:38:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ra_sa(t_list **a)
{
	ft_ra(a);
	ft_sa(a);
}

void	rra_sa(t_list **a)
{
	ft_rra(a);
	ft_sa(a);
}

void	move_list(t_list **a)
{
	t_list	*p_a;

	p_a = *a;
	if (checker_order_list(p_a))
	{
		if (p_a->data > p_a->next->data
			&& p_a->next->data > p_a->next->next->data)
			ra_sa(a);
		else if ((p_a->data < p_a->next->data
				&& p_a->data < p_a->next->next->data)
			&& (p_a->next->data > p_a->next->next->data))
			rra_sa(a);
		else if (p_a->data > p_a->next->data
			&& p_a->data < p_a->next->next->data)
			ft_sa(a);
		else if (p_a->data < p_a->next->data
			&& p_a->data > p_a->next->next->data)
			ft_rra(a);
		else if (p_a->data > p_a->next->data
			&& p_a->next->data < p_a->next->next->data)
			ft_ra(a);
	}
}
