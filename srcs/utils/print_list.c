/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:08:30 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/24 18:17:12 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(const long *list, const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(list[i], STDOUT_FILENO);
		ft_putchar_fd(' ', STDOUT_FILENO);
		++i;
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
}
