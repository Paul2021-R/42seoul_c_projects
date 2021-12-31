/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:54:23 by haryu             #+#    #+#             */
/*   Updated: 2022/01/01 03:56:04 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./LIBFT/libft.h"
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_putstr_len(const char *str);
int		switch_integer(long nbr, char specifier);
int		switch_integer_16(int nbr, char specifier);
char	*ft_uitoa(unsigned int nbr);
char	*ft_itoa(int nbr);
char	*ft_strrev(char *src);
size_t	ft_strlen(const char *s);
#endif 
