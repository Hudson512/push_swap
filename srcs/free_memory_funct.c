/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory_funct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:50:31 by codespace         #+#    #+#             */
/*   Updated: 2024/07/24 09:23:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void    libera_matrix(char **str)
{
    int i;

    if (str == NULL || str[0] == NULL)
        return;
    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
}

void    libera_stack(t_list **a)
{
    t_list  *temp;

    if (a == NULL || *a == NULL)
        return;
    while (*a)
    {
        temp = *a;
        *a = (*a)->next;
        free(temp);
    }
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