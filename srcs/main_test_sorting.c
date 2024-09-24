/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:01:55 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/24 17:35:11 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	print_stack(long *stack, size_t size)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%ld ", stack[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

int	main(void)
{
	long	*stack_a;
	long	*stack_b;
	size_t	size_a;
	size_t	size_b;


	stack_a = (long *)malloc(5 * sizeof(long));
	stack_b = (long *)malloc(2 * sizeof(long));
	stack_a[0] = 1;
	stack_a[1] = 2;
	stack_a[2] = 3;
	stack_a[3] = 4;
	stack_a[4] = 5;
	stack_b[0] = 6;
	stack_b[1] = 7;

	size_a = 5;
	size_b = 2;
	print_list(stack_a, size_a);
	push_b(stack_a, &size_a, stack_b, &size_b);
	print_list(stack_a, size_a);
	print_list(stack_b, size_b);
}
