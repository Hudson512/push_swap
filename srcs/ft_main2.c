/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:10:58 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/07 14:01:56 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_ordenacao(t_list **a, t_list **b)
{
	t_list	*p_a;
	t_list	*p_b;

	p_a = *a;
	p_b = *b;
	if (count_list(p_a) == 3)
	{
		if (verif_ordem_list(p_a)){
			if (p_a->data > p_a->next->data && p_a->next->data > p_a->next->next->data)
			{
				ft_ra(a);
				ft_sa(a);
			}
			else if ((p_a->data < p_a->next->data && p_a->data < p_a->next->next->data) 
				&& (p_a->next->data > p_a->next->next->data))
			{
				ft_rra(a);
				ft_sa(a);
			}
			else if (p_a->data > p_a->next->data && p_a->data < p_a->next->next->data)
			{
				ft_sa(a);
			}
			else if (p_a->data < p_a->next->data && p_a->data > p_a->next->next->data)
			{
				ft_rra(a);
			}
			else if (p_a->data > p_a->next->data && p_a->next->data < p_a->next->next->data)
			{
				ft_ra(a);
			}
		}
	}
}