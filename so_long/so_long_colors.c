/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:55:31 by haryu             #+#    #+#             */
/*   Updated: 2022/02/11 22:07:06 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	add_shade(double shader, int trgb)
{
	unsigned char	color[4];
	int				i;
	unsigned char	temp;

	color[0] = (unsigned char)get_b(trgb);
	color[1] = (unsigned char)get_g(trgb);
	color[2] = (unsigned char)get_r(trgb);
	color[3] = (unsigned char)get_t(trgb);
	i = 0;
	while (i < 3)
	{
		if (color[i] <= 1)
		{
			i++;
			continue;
		}
		else
		{
			temp = color[i] * shader;
			color[i] -= (int)temp;
		}
		i++;
	}
	return (*(int *)color);
}

int get_opposite(int trgb)
{
	unsigned char	color[4];
	int				i;

	color[0] = (unsigned char)get_b(trgb);
	color[1] = (unsigned char)get_g(trgb);
	color[2] = (unsigned char)get_r(trgb);
	color[3] = (unsigned char)get_t(trgb);
	i = 0;
	while(i < 3)
	{
		color[i] = 255 - color[i];
		i++;
	}
	return (*(int *)color);
}
