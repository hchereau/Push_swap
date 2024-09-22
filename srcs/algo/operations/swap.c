/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:21:14 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/22 12:05:34 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static void	swap(long *stack, const size_t a, const size_t b)
{
	long	tmp;

	tmp = stack[a];
	stack[a] = stack[b];
	stack[b] = tmp;
}

void	swap_a(long *stack, const size_t size)
{
	if (size < 2)
		return ;
	swap(stack, 0, 1);
	ft_dprintf(STDOUT_FILENO, "sa\n");
}

void	swap_b(long *stack, const size_t size)
{
	if (size < 2)
		return ;
	swap(stack, 0, 1);
	ft_dprintf(STDOUT_FILENO, "sb\n");
}

void	ss(long *stack_a, const size_t size_a, long *stack_b,
	const size_t size_b)
{
	swap_a(stack_a, size_a);
	swap_b(stack_b, size_b);
	ft_dprintf(STDOUT_FILENO, "ss\n");
}
