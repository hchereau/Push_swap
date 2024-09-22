/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:21:14 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/22 14:48:30 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static void	swap(long *stack)
{
	long	tmp;

	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void	swap_a(long *stack)
{
	swap(stack);
	ft_dprintf(STDOUT_FILENO, "sa\n");
}

void	swap_b(long *stack)
{
	swap(stack);
	ft_dprintf(STDOUT_FILENO, "sb\n");
}

void	ss(long *stack_a, long *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_dprintf(STDOUT_FILENO, "ss\n");
}
