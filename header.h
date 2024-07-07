/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:06:59 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/07 13:33:31 by hmateque         ###   ########.fr       */
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
int		verif_num_dup(t_list *head, int value);
int		verif_ordem_list(t_list *head);
int		count_list(t_list *head);

void    add_list_next(t_list **head, int value);
void    add_list_first(t_list **head, int data);
void	ft_swap(t_list **head);
void	ft_sa(t_list **head);
void	ft_sb(t_list **head);
void	ft_ss(t_list **a, t_list **b);
void	ft_push(t_list **a, t_list **b);
void	ft_pa(t_list **b, t_list **a);
void	ft_pb(t_list **a, t_list **b);
void	ft_rotate(t_list **p1);
void	ft_ra(t_list **head);
void	ft_rb(t_list **head);
void	ft_rr(t_list **a, t_list **b);
void	ft_reverse_rotate(t_list **p1);
void	ft_rra(t_list **head);
void	ft_rrb(t_list **head);
void	ft_ordenacao(t_list **a, t_list **b);
void	print_list(t_list *head);

char	**ft_split(char const *str, char c);

#endif