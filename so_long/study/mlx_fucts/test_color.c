/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:59:39 by haryu             #+#    #+#             */
/*   Updated: 2022/02/11 18:09:27 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	int ret;
	int t, r, g, b;

	(void)ac;
	t = atoi(av[1]);
	r = atoi(av[2]);
	g = atoi(av[3]);
	b = atoi(av[4]);
	ret = create_trgb(t, r, g, b);
	printf("0x%x\n", ret);
	printf("t = %d r = %d g = %d b = %d\n",get_t(ret), get_r(ret), get_g(ret), get_b(ret));
}
