/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:16:23 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/02 13:18:18 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	while (str[i] < 33)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * sign);
}

int	verif_num_palavra(char *str)
{
	int	count_palavra;
	int	in_palavra;
	int	i;

	count_palavra = 0;
	in_palavra = 0;
	i = 0;
	while (str[i]){
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
	while (str[i]){
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{
			write(2, "ERROR\n", 6);
			exit(1);
		}
		i++;
	}
	return (count_palavra);
}

int	verif_num_dup(t_list *head, int value)
{
	while (head != NULL){
		if (head->data == value)
			return (0);
		else
			head = head->next;
	}
	return (1);
}