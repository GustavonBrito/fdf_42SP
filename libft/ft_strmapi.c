/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:01:45 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/03/19 21:42:59 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	a;
	char			*str_with_func_applied;

	a = 0;
	if (s == (void *)0 || f == (void *)0)
		return ((void *)0);
	str_with_func_applied = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (str_with_func_applied == (void *)0)
		return ((void *)0);
	while (s[a])
	{
		str_with_func_applied[a] = f(a, s[a]);
		a++;
	}
	str_with_func_applied[a] = '\0';
	return (str_with_func_applied);
}
