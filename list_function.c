/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:44:19 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/01 21:44:19 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void add_list_next(t_list **a, int value)
{
    t_list  *new;
    
    new = (t_list *)malloc(sizeof(t_list));
    new->data = value;
    new->next = NULL;
    if (*a != NULL)
    {
        t_list *current = *a;
        while (current->next != NULL)
            current = current->next;
        current->next = new;
    }
    else
        *a = new;
}