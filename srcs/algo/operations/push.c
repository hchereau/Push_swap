/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:51:14 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/22 12:08:14 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	push_a(long *stack_a, size_t *size_a, long *stack_b, size_t *size_b)
{
	if (*size_b == 0)
		return ;
	(*size_a)++;
	(*size_b)--;
	stack_a[*size_a - 1] = stack_b[0];
	ft_memmove(stack_b, stack_b + 1, *size_b * sizeof(long));
	ft_dprintf(STDOUT_FILENO, "pa\n");
}

void	push_b(long *stack_a, size_t *size_a, long *stack_b, size_t *size_b)
{
	if (*size_a == 0)
		return ;
	(*size_b)++;
	(*size_a)--;
	stack_b[*size_b - 1] = stack_a[0];
	ft_memmove(stack_a, stack_a + 1, *size_a * sizeof(long));
	ft_dprintf(STDOUT_FILENO, "pb\n");
}
