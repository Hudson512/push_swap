/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:25:36 by hmateque          #+#    #+#             */
/*   Updated: 2024/07/03 18:30:22 by hmateque         ###   ########.fr       */
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
			//ft_sa(&a);
			//ft_pb(&a, &b);
			//ft_ra(&a);
			ft_rra(&a);
		}
		else
		{
			printf("Verif_ordem_list - Ordenada\n");
		}

		printf("Pilha - a\n");
		while(a != NULL){
			printf("%d\n", a->data);
			a = a->next;
		}
		printf("Pilha - b\n");
		while(b != NULL){
			printf("%d\n", b->data);
			b = b->next;
		}
	}
	return 0;
}