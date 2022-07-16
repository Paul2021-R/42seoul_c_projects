/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:27:40 by haryu             #+#    #+#             */
/*   Updated: 2022/01/30 19:38:52 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_printf(const char str, ...)
{
	int 		ret;
	va_list 	print
	
	if (!str)
		return (-1);
	va_start(print, str);
	len = 0;
	len = make_len(str, print);
	va_end(print);
	return (ret);
}

static int make_len(const char str, va_list print)
{}

static void print_str()
//해야 할 일 ... 
//s , d , x 구현 
