/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:46:45 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/26 13:27:18 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static void	reverse_rotate(long *stack, size_t size)
{
	long	tmp;
	size_t	i;

	if (size < 2)
		return ;
	tmp = stack[size - 1];
	i = size - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = tmp;
}

void	reverse_rotate_a(long *stack_a, size_t size_a)
{
	reverse_rotate(stack_a, size_a);
	ft_dprintf(STDOUT_FILENO, "rra\n");
}

void	reverse_rotate_b(long *stack_b, size_t size_b)
{
	reverse_rotate(stack_b, size_b);
	ft_dprintf(STDOUT_FILENO, "rrb\n");
}

void	rrr(long *stack_a, size_t size_a, long *stack_b, size_t size_b)
{
	reverse_rotate_a(stack_a, size_a);
	reverse_rotate_b(stack_b, size_b);
	ft_dprintf(STDOUT_FILENO, "rrr\n");
}
