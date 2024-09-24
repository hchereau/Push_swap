/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:51:14 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/24 18:29:07 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static void	push(long *push_stack, size_t *push_size, long *pop_stack,
	size_t *pop_size)
{
	size_t	i;

	if (*push_size == 0)
		return ;
	i = *pop_size;
	while (i > 0)
	{
		pop_stack[i] = pop_stack[i - 1];
		--i;
	}
	pop_stack[0] = push_stack[0];
	i = 0;
	while (i < *push_size - 1)
	{
		push_stack[i] = push_stack[i + 1];
		++i;
	}
	++(*pop_size);
	--(*push_size);
}

void	push_a(long *stack_a, size_t *size_a, long *stack_b, size_t *size_b)
{
	push(stack_b, size_b, stack_a, size_a);
	ft_dprintf(STDOUT_FILENO, "pa\n");
}

void	push_b(long *stack_a, size_t *size_a, long *stack_b, size_t *size_b)
{
	push(stack_a, size_a, stack_b, size_b);
	ft_dprintf(STDOUT_FILENO, "pb\n");
}
