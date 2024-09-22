/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:51:14 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/22 13:50:34 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static void	push(long *push_stack, size_t *push_size, long *pop_stack,
	size_t *pop_size)
{
	if (*pop_size == 0)
		return ;
	(*push_size)++;
	(*pop_size)--;
	push_stack[*push_size - 1] = pop_stack[0];
	ft_memmove(pop_stack, pop_stack + 1, *pop_size * sizeof(long));
}

void	push_a(long *stack_a, size_t *size_a, long *stack_b, size_t *size_b)
{
	push(stack_a, size_a, stack_b, size_b);
	ft_dprintf(STDOUT_FILENO, "pa\n");
}

void	push_b(long *stack_a, size_t *size_a, long *stack_b, size_t *size_b)
{
	push(stack_b, size_b, stack_a, size_a);
	ft_dprintf(STDOUT_FILENO, "pb\n");
}
