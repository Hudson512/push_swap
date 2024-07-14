/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifs_funct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:16:23 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/11 12:45:41 by hmateque         ###   ########.fr       */
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
	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == 32))
		{
			write(2, "ERROR\n", 6);
			exit(1);
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
		{
			write(2, "ERROR\n", 6);
			exit(1);
		}
		else
			head = head->next;
	}
	return (1);
}

int		checker_order_list(t_list *head)
{
	while (head->next != NULL)
	{
		if (head->data  < head->next->data)
			head = head->next;
		else
			return (1);
	}
	return (0);
}