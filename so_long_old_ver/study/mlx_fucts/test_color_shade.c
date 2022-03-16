/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_color_shade.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:58:11 by haryu             #+#    #+#             */
/*   Updated: 2022/02/11 21:01:46 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	int trgb;
	
	trgb = create_trgb(atoi(av[1]), atoi(av[2]), atoi(av[3]), atoi(av[4]));
	printf("original color : %08X\n", trgb);
	printf("new one : %08X\n", add_shade(0.8, trgb));
	printf("complemetary color : %08X\n", get_opposite(trgb));
	return 0;
}
