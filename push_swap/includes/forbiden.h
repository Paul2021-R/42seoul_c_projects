/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forbiden.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 01:24:53 by haryu             #+#    #+#             */
/*   Updated: 2022/04/23 01:26:07 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORBIDEN_H
# define FORBIDEN_H

# include "pushswap.h"
# include <stdio.h>

/* Forbidden utils */
/* 현재 스텍 확인용 */
void	lst_print(t_pushlist **push);
/* LIS array 확인용 */
void	lis_print(t_pushlist **push);

#endif