/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 16:54:23 by haryu             #+#    #+#             */
/*   Updated: 2021/12/31 17:00:17 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

# ifdef _WIN32

#	include <io.h>

# else

#	include <unistd.h>

# endif

int		ft_printf(const char *str, ...);

#endif 
