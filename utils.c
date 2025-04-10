/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:59:56 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/09 22:52:06 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/headers/ft_printf.h"
#include "libft/headers/get_next_line.h"
#include "libft/headers/libft.h"

void	ft_free_split(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	validate_element(char *token)
{
	int	i;

	i = 0;
	while (ft_isdigit(token[i]) == 1 || token[i] == '-')
		i++;
	if (token[i] != ',' && token[i] != '\0' && token[i] != '\n')
		return (-1);
	if (token[i] == ',')
	{
		if (token[i + 1] != '0' || token[i + 2] != 'x')
			return (-1);
	}
	else if (token[i] == '\n')
		return (1);
	return (1);
}

// talvez implementar um forma de percorrer esse hex para ver se tem algum valor maior q F e menor que 0.
