/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:25:36 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/07 14:18:01 by hmateque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	count_p;
	char	**arr;
	t_list	*a;
	t_list	*b;
	
	if (argc > 1){
		a = NULL;
		b = NULL;
		i = 1;
		while (i < argc)
		{
			count_p = verif_num_palavra(argv[i]);
			if (count_p == 1){
				if (!verif_num_dup(a, ft_atoi(argv[i])))
					add_list_next(&a, ft_atoi(argv[i]));
				else
				{
					write(2, "ERROR\n", 6);
					exit(1);
				}	
			}
			else if (count_p > 1){
				arr = ft_split(argv[i], 32);
				j = 0;
				while (j < count_p){
					if (!verif_num_dup(a, ft_atoi(arr[j])))
						add_list_next(&a, ft_atoi(arr[j]));
					else
					{
						write(2, "ERROR\n", 6);
						exit(1);
					}
					j++;
				}
			}
			i++;
		}
		if (verif_ordem_list(a))
		{
			ft_ordenacao(&a, &b);
		}
		else
		{
			printf("Verif_ordem_list - Ordenada\n");
		}
		printf("Pilha a\n");
		print_list(a);
		printf("Pilha b\n");
		print_list(b);
	}
	return 0;
}