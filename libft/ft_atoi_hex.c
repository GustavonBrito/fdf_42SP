/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 02:26:05 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/04/13 02:26:22 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	getnb(char c)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789ABCDEF";
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int	ft_atoi_hexa(char *str)
{
	int		i;
	int		res;
	char	c;

	i = -1;
	res = 0;
	c = 0;
	while (i++, str[i] && str[i] != ' ')
	{
		c = str[i];
		if (c >= 97 && c <= 102)
			c = c - 32;
		res = (res * 16) + getnb(c);
	}
	return (res);
}
