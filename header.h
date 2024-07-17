/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:06:59 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/16 18:21:14 by hmateque         ###   ########.fr       */
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
    int	num_oper_a;
    int	num_oper_b;
    struct node *next;
}   t_list;

t_list  *last_node(t_list *stack);
int	    ft_atoi(char *str);
int     checker_num_palavra(char *str);
int		checker_num_dup(t_list *head, int value);
int		checker_order_list(t_list *head);
int		count_list(t_list *head);
int		find_node_index(t_list *head, int value);
int		ft_rot_or_rrot(int value, t_list *head);
int		get_stack_a_step(int value, t_list *head);
int		get_stack_b_step(int nbr, t_list *head);
int		get_stack_b_step_2(int nbr, t_list *head);
int		ft_num_barato(t_list **a, t_list **b);
int		ft_num_barato_2(t_list **a, t_list **b);
int     find_max(t_list *head);
int     find_min(t_list *head);
int		checker_order_list_2(t_list *head);

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
void	ft_reverse_rotate(t_list **stack);
void	ft_rra(t_list **head);
void	ft_rrb(t_list **head);
void	ft_ordering_b(t_list **a, t_list **b);
void	ft_ordering_a(t_list **b, t_list **a);
void	print_list(t_list *head);
void	move_stack_a_step(int value, int m_a, t_list **a, t_list **b);
void	move_stack_b_step(int nbr, int m_b, t_list **b);
void	order_stack(int nbr, t_list **b);
void	order_stack_a(int nbr, t_list **b);
void	move_stack_a_step_2(int value, int m_a, t_list **b, t_list **a);
void	move_stack_b_step_2(int nbr, int m_b, t_list **a);

char	**ft_split(char const *str, char c);

#endif