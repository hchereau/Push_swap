/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:24:03 by hucherea          #+#    #+#             */
/*   Updated: 2024/09/19 16:01:42 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_string_list(int ac, char **av)
{
	char	*string_list;
	char	*temp_string_list;
	int		i;

	i = 1;
	string_list = ft_strdup("");
	if (string_list == NULL)
		return (NULL);
	temp_string_list = string_list;
	while (i < ac)
	{
		string_list = ft_strjoin(string_list, av[i]);
		free(temp_string_list);
		temp_string_list = string_list;
		if (string_list == NULL)
			break ;
		string_list = ft_strjoin(string_list, " ");
		free(temp_string_list);
		temp_string_list = string_list;
		if (string_list == NULL)
			break ;
		++i;
	}
	return (string_list);
}

static int	get_list(int **list, char *str)
{
	char	**split;
	size_t	i_list;
	size_t	size_list;

	i_list = 0;
	size_list = count_words(str, ' ');
	split = ft_split(str, ' ');
	*list = malloc(sizeof(int) * size_list);
	if (*list != NULL && split != NULL)
	{
		while (*split)
		{
			(*list)[i_list] = ft_atoi(*split);
			++i_list;
			++split;
		}
	}
	free_strs(split - i_list);
	return (size_list);
}

t_list_number	get_numbers_list(int ac, char **av)
{
	char			*string_list;
	t_list_number	list;

	list.state = error;
	if (ac < 2)
		return (list);
	string_list = get_string_list(ac, av);
	if (string_list != NULL)
	{
		list.size = get_list(&list.list, string_list);
		list.state = not_sorted;
		free(string_list);
	}
	return (list);
}
