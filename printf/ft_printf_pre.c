/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:23:25 by haryu             #+#    #+#             */
/*   Updated: 2022/01/05 12:04:33 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*make_len(char *fmt, va_list ap);

int	ft_printf(const char *str, ...)
{
	int			i;
	int			err;
	int			ret;
	char		*ret_str;
	va_list		ap;

	va_start(ap, str);
	i = 0;
	ret = 0;
	while (str[i])
	{
		err = 1;
		if (str[i] == '%')
			ret_str = make_len((char)str[++i], ap, &err);
		if (str[i] != '%')
			res_str = make_len((char)str[i], 0, &err);
		ret += err;
		if (err == -1)
			return (-1);
		i++;
	}
	va_end(ap);
	return (ret);
}

static char	*make_len(char fmt, va_list ap, int *err)
{
	char		*temp;
	static char	*str;

	str = (char *)ft_calloc(1, sizeof(char));
	if (!str)
	{
		err = -1;
		return(NULL);
	}
	if (fmt == 'C')
	else if (fmt == 's')
	{
		temp = ft_strdup(va_arg(ap, char *));
		err = ft_strlen(temp); // need to modify
	}
	else if (fmt == 'd' || fmt == 'i' || fmt == 'u')
	{
		temp = switch_integer(va_arg(ap, long long), fmt, &err); // need to modify
	}
	else if (fmt == 'x' || fmt == 'X' || fmt == 'p')
	{
		temp = switch_integer_16(va_arg(ap, long long), fmt, &err); // need to modify
	}
	else 
	{}
	str = ft_strjoin(str, temp);
	{
		temp = (char *)ft_calloc (2, sizeof(char *));
		if (!temp)
		{
			err = -1;
			return (NULL);
		}
		temp[0] = (va_arg(ap, int));
	}
	else if (str[i] == 's')
		temp = (char *)ft_calloc (ft_strlen(sizseof)
	else if (str[i] == 'd' || str[i] == 'i' || str[i] == 'u')
		err = 
	else if (str[i] == 'x' || str[i] == 'X' || str[i] == 'p')
		err = switch_integer_16(va_arg(ap, long long), str[i]);
}