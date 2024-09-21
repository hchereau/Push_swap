/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:39:17 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/21 10:40:06 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_valid_char(const char c)
{
	return (c == '-' || c == '+' || c == ' ');
}

static bool	is_real_number(const char *str)
{
	size_t	i;

	i = 0;
	if (is_valid_char(str[i]) == true)
		++i;
	while (ft_isdigit(str[i]) == 1)
		++i;
	if (str[i] == ' ' || str[i] == '\0')
		return (true);
	return (false);
}

bool	is_valid_string(const char *list)
{
	size_t	i;

	i = 0;
	if (list == NULL)
		return (false);
	while (list[i] != '\0')
	{
		if ((is_valid_char(list[i]) == false
				&& ft_isdigit(list[i]) == 0)
			|| is_real_number(list + i) == false)
			return (false);
		++i;
	}
	return (true);
}
