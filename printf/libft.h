/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:28:27 by haryu             #+#    #+#             */
/*   Updated: 2021/12/30 22:35:34 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>

#ifdef  _WIN32

#	include <io.h>

# else

#	include <unistd.h>

# endif

int	ft_printf(const char *str, ...);

#endif
