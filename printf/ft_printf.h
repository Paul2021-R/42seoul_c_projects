/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:54:23 by haryu             #+#    #+#             */
/*   Updated: 2022/01/20 14:34:17 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./LIBFT/libft.h"
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_putstr_len(const char *str);
char	*switch_integer(long long nbr, char specifier);
char	*switch_integer_16(long long nbr, char specifier);
char	*ft_uitoa(unsigned int nbr);
char	*ft_itoa_16(int nbr);
char	*ft_ltostr_16(long long nbr);
char	*ft_strrev(char *src);
char	*ft_chartostr(char c);
void	ft_print_str_lst(t_list *first);
#endif
