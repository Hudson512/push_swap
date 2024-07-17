/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:44:19 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/17 10:29:56 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void    add_list_next(t_list **head, int value)
{
    t_list  *new;
    
    new = (t_list *)malloc(sizeof(t_list));
    new->data = value;
    new->num_oper_a = 0;
    new->num_oper_b = 0;
    new->next = NULL;
    if (*head != NULL)
    {
        t_list *current = *head;
        while (current->next != NULL)
            current = current->next;
        current->next = new;
    }
    else
        *head = new;
}

void    add_list_first(t_list **head, int data)
{
    t_list  *new;

    new = (t_list *)malloc(sizeof(t_list));
    new->data = data;
    new->num_oper_a = 0;
    new->num_oper_b = 0;
    new->next = *head;

    *head = new;
}

t_list  *last_node(t_list *stack)
{
    while (stack->next)
        stack = stack->next;
    return (stack);
}

int     count_list(t_list *head)
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

int     find_node_index(t_list *head, int value)
{
    int i;

    i = 0;
    while (head)
    {
        if (head->data == value)
            return (i);
        else
            head = head->next;
        i++;
    }
    return (0);
}

int     find_max(t_list *head)
{
    t_list *current;
    int max_value;

    if (head == NULL)
        return (0);
    max_value = head->data;
    current = head->next;
    while (current != NULL)
    {
        if (current->data > max_value)
            max_value = current->data;
        current = current->next;
    }
    return max_value;
}

int     find_min(t_list *head)
{
    t_list *current;
    int min_value;

    if (head == NULL)
        return (0);
    min_value = head->data;
    current = head->next;
    while (current != NULL)
    {
        if (current->data < min_value)
            min_value = current->data;
        current = current->next;
    }
    return min_value;
}

void    print_list(t_list *head)
{
    while(head != NULL)
    {
        printf("-------\n");
        printf("%d\n", head->data);
        // printf("%d\n", head->num_oper_a);
        // printf("%d\n", head->num_oper_b);
        printf("-------\n");
        head = head->next;
    }
}