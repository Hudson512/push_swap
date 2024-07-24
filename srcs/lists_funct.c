/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/07/24 12:34:27 by codespace         #+#    #+#             */
/*   Updated: 2024/07/24 12:34:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	add_list_next(t_list **head, int value)
{
	t_list  *new;
	t_list  *current;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return ;
	new->data = value;
	new->num_oper_a = 0;
	new->num_oper_b = 0;
	new->next = NULL;
	if (*head != NULL)
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
	else
		*head = new;
}

void	add_list_first(t_list **head, int data)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return ;
	new->data = data;
	new->num_oper_a = 0;
	new->num_oper_b = 0;
	new->next = *head;

	*head = new;
}

t_list	*last_node(t_list *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	count_list(t_list *head)
{
	int i;

	i = 0;
	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}

void	print_list(t_list *head)
{
	while (head != NULL)
	{
		printf("-------\n");
		printf("%d\n", head->data);
		// printf("%d\n", head->num_oper_a);
		// printf("%d\n", head->num_oper_b);
		printf("-------\n");
		head = head->next;
	}
}
