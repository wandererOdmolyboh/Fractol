/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:53:51 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/04/21 15:14:48 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void putter_pixel(t_fractol *fractal)
{
	int	x;
	int y;
	int color_set;

	y = -1;
	while (++y < SQ_M)
	{
		x = -1;
		while(++x < SQ_M)
		{
			color_set = (fractal->ff.fractal)(fractal, x, y);
			*(fractal->image_ptr + x + y * SQ_M) = color_set;
		}
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->image, 0, 0);
}
