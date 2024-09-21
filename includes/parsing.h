/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:24:34 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/21 17:40:29 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "push_swap.h"

// parsing/

t_list_number	get_numbers_list(int ac, char **av);
bool			is_valid_list(const char *string_list, const long *list,
					size_t size_list);
bool			is_valid_string(const char *list);

#endif
