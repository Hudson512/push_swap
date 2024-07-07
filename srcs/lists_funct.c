/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:44:19 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/07 13:32:25 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void add_list_next(t_list **head, int value)
{
    t_list  *new;
    
    new = (t_list *)malloc(sizeof(t_list));
    new->data = value;
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
    new->next = *head;

    *head = new;
}

int    count_list(t_list *head)
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

void    print_list(t_list *head)
{
    while(head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}