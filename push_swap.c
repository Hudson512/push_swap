/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:25:36 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/01 22:11:09 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char *argv[])
{
	int	i;
	int	count_p;
	t_list	*a;
	
	if (argc > 1){
		a = NULL;
		i = 1;
		while (i < argc)
		{
			count_p = verif_num_palavra(argv[i]);
			if (count_p == 1){
				add_list_next(&a, ft_atoi(argv[i]));
			}
			i++;
		}
		while(a != NULL){
			printf("%d\n", a->data);
			a = a->next;
		}
	}
	return 0;
}