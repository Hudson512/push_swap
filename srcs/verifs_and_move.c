/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifs_and_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:35:01 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/24 12:38:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	check_and_exec(t_list **a, t_list **b)
{
	if (count_list(*a) == 2)
	{
		if (checker_order_list(*a))
			ft_sa(a);
	}
	else if (count_list(*a) == 4)
	{
		ft_pb(a, b);
	}
	else if (count_list(*a) > 3)
	{
		ft_pb(a, b);
		ft_pb(a, b);
	}
}

int	checker_order_list_2(t_list *head)
{
	if (head == NULL)
		return (0);
	while (head->next != NULL)
	{
		if (head->data > head->next->data)
			head = head->next;
		else
			return (1);
	}
	return (0);
}

void	pre_add(t_list **a, char *str)
{
	if (checker_num_dup(*a, (int)ft_atoi(str)) && value_limit(ft_atoi(str)))
		add_list_next(a, (int)ft_atoi(str));
}

void	pre_add_2(t_list **a, char *str, int count_p)
{
	char **arr;
	int j;

	arr = ft_split(str, 32);
	j = 0;
	while (j < count_p)
	{
		if (checker_num_dup(*a, (int)ft_atoi(arr[j]))
			&& value_limit(ft_atoi(arr[j])))
			add_list_next(a, (int)ft_atoi(arr[j]));
		j++;
	}
	if (arr != NULL)
	{
		libera_matrix(arr);
		free(arr);
	}
}
