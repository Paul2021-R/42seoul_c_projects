/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:02:37 by haryu             #+#    #+#             */
/*   Updated: 2022/02/03 17:29:45 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar(int c, int *len);
void	ft_putstr(char *s, int *len);
void	ft_put_integer(int n, int *len);
void	ft_put_unsigned(unsigned int n, int *len);
void	ft_put_hex(unsigned int n, int *len, char *ref);
void	ft_put_pointer(unsigned long long n, int *len, char *ref);
void	ft_put_pointer_pre(unsigned long long n, int *len, char *ref);
char	*ref_base(char *ref);
int		ft_printf(const char *str, ...);
#endif
