/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifs_funct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:16:23 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/19 14:42:15 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	checker_num_palavra(char *str)
{
	int	count_palavra;
	int	in_palavra;
	int	i;

	count_palavra = 0;
	in_palavra = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < 33)
			in_palavra = 0;
		else if (!in_palavra)
		{
			in_palavra = 1;
			count_palavra++;
		}
		i++;
	}
	return (count_palavra);
}

int	checker_num_dup(t_list *head, int value)
{
	while (head != NULL)
	{
		if (head->data == value)
			print_error();
		else
			head = head->next;
	}
	return (1);
}

int		checker_order_list(t_list *head)
{
	if (head == NULL)
		return (0);
	while (head->next != NULL)
	{
		if (head->data  < head->next->data)
			head = head->next;
		else
			return (1);
	}
	return (0);
}

int		checker_order_list_2(t_list *head)
{
	if (head == NULL)
		return (0);
	while (head->next != NULL)
	{
		if (head->data  > head->next->data)
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
	char	**arr;
	int		j;

	arr = ft_split(str, 32);
	j = 0;
	while (j < count_p)
	{
		if (checker_num_dup(*a, (int)ft_atoi(arr[j])) && value_limit(ft_atoi(arr[j])))
			add_list_next(a, (int)ft_atoi(arr[j]));
		j++;
	}
	if (arr != NULL)
	{
		libera_matrix(arr);
		free(arr);
	}
}