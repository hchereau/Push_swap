/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:01:55 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/22 12:05:29 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stack(long *stack, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		printf("%ld ", stack[i]);
		i++;
	}
	printf("\n");
}

int	main(void)
{
	long	stack_b[5] = {5, 2, -3, 9, 6};
	long	stack_a[5] = {};
	// long	*index;
	size_t	size_a = 0;
	size_t	size_b = 5;
	// swap_a(stack, 5);
	push_a(stack_a, &size_a, stack_b, &size_b);
	push
	// index = get_index_list(stack, 5);
	print_stack(stack_a, size_a);
	print_stack(stack_b, size_b);
	// print_stack(index, 5);
}
