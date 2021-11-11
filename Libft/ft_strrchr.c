/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:35:27 by wildwiser-r       #+#    #+#             */
/*   Updated: 2021/11/11 11:37:34 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    const char    *ret;

    ret = s;

    while (*s++)
        ;
    while (*ret != *s && *s != (char)c)
    {
        s -= 1;
        if (*s == (char)c)
            return ((char *)s);
    }
        return(NULL);
}