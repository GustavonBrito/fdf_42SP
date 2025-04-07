/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:59:56 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/06 22:28:07 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/headers/ft_printf.h"
#include "libft/headers/get_next_line.h"
#include "libft/headers/libft.h"

void	ft_free_split(char **array, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	validate_element(const char *token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (ft_isdigit(token[i]) == 1)
			i++;
		else if (token[i] == ',')
		{
			if (token[i + 1] == '0' && token[i + 2] == 'x')
				return (1);
			else
				return (-1);
		}
		else if (token[i] == '\n')
			return (1);
		else
			return (-1);
	}
	return (1);
}