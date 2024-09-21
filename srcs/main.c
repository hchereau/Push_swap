/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:24:10 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/21 17:47:35 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int ac, char **av)
{
	const t_list_number	list = get_numbers_list(ac, av);

	if (list.state == error)
	{
		ft_putstr_fd("Error_list\n", STDERR_FILENO);
		return (1);
	}
	else
	{
		sort_numbers(&list);
	}
}

int	main(int ac, char **av)
{
	sort_numbers(get_numbers_list(ac, av));
}
