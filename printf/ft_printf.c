/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:23:25 by haryu             #+#    #+#             */
/*   Updated: 2021/12/30 22:40:43 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_printf(const char *str, ...)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i += 1;
			if (str[i] == 'c')
				write(1, "char", 4);
			else if (str[i] == 's')
				write(1, "str", 3);
			else if (str[i] == 'd' || str[i] == 'i')
				write(1, "integer", 7);
			else if (str[i] == 'u')
				write(1, "unsigned", 8);
			else if (str[i] == 'x' | str[i] == 'X')
				write(1, "16", 2);
			else if (str[i] == 'p')
				write(1, "pointer", 7);
			else
				write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	return (10);
}
