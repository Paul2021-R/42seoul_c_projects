/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_colors_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:32:24 by haryu             #+#    #+#             */
/*   Updated: 2022/02/11 19:48:13 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){ b, g, r, t }); //들어오는 문자열로 된 정수값 1바이트(비부호형) 을 묶어서 배열로 만들고 다시 정수로 형변환을 하여 정수값으로 환산한 형태
}

unsigned char	get_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]); //받은 정수를 다시 비부호형 char 타입으로 형변환 한뒤 배열처럼 하여 해당 위치에 맞는 정수값을 출력하는 형식 
}

unsigned char	get_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	get_g(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	get_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}

int	add_shade(double shader, int trgb)
{
	unsigned char	color[4];
	int				i;
	int				temp;

	color[0] = get_b(trgb);
	color[1] = get_g(trgb);
	color[2] = get_r(trgb);
	color[3] = get_t(trgb);

	i = 0;
	while (i < 3)
	{
		if (color[i] == 0)
			continue ;
		else
		{
			temp -= (int)(color[i] * shader);
			color[i] = temp;
		}
		i++;
	}
	return (*(int *)color);
}
