/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:15:14 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/24 12:40:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_swap(t_list **head)
{
	t_list	*elem1;
	t_list	*elem2;

	elem1 = *head;
	elem2 = elem1->next;
	elem1->next = elem2->next;
	elem2->next = elem1;
	*head = elem2;
}

void	ft_push(t_list **p1, t_list **p2)
{
	t_list	*elem_p1;

	elem_p1 = *p1;
	add_list_first(p2, elem_p1->data);
	*p1 = elem_p1->next;
	free(elem_p1);
	elem_p1 = NULL;
}

void	ft_rotate(t_list **p1)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	if (*p1 == NULL || (*p1)->next == NULL)
		return ;
	tmp1 = *p1;
	tmp2 = tmp1->next;
	tmp3 = tmp2;
	while (tmp3->next != NULL)
		tmp3 = tmp3->next;
	tmp3->next = tmp1;
	tmp1->next = NULL;
	*p1 = tmp2;
}

void	ft_reverse_rotate(t_list **stack)
{
	t_list *last;
	t_list *prev_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = last_node(*stack);
	prev_last = *stack;
	while (prev_last->next != last)
		prev_last = prev_last->next;
	prev_last->next = NULL;
	last->next = *stack;
	*stack = last;
}
