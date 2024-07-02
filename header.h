/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:06:59 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/02 12:24:01 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
}   t_list;

int	    ft_atoi(char *str);
int     verif_num_palavra(char *str);
void    add_list_next(t_list **a, int value);
char	**ft_split(char const *str, char c);

#endif