/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia_Set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:25:53 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/20 18:59:25 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractal.h"

int julias_v(t_fractol *fractol,  double x, double y) // mybe chandge value fo test
{
	t_complex	c;
	t_complex	z1;
	t_complex	z2;
	double zoom = 0.5, moveX = 0, moveY = 0; //you can change these to zoom and change position
	int color;
	int maxIterations = 10;
	int i;

	i = 0;
	c.x = (fractol->mouse_x);
	c.i = (fractol->mouse_y);
	z2.x = 1.5 * (x - SQ_M / 2) / (0.5 * zoom * SQ_M) + moveX;
	z2.i = (y - SQ_M / 2) / (0.5 * zoom * SQ_M) + moveY;
	while (i < maxIterations)
	{
		z1.x = z2.x;
		z1.i = z2.i;
		z2.x = z1.x * z1.x - z1.i * z1.i + c.x;
		z2.i = 2 * z1.x * z1.i + c.i;
		if((z2.x * z2.x + z2.i * z2.i) > 3)
			return(
			((4* i /  maxIterations) << 16) | 
			((fractol->c_rgb.green * i /  maxIterations)<< 8) |
			(fractol->c_rgb.blue * i /  maxIterations));
		i++;
	}
	color = 255 * i;
	return (
				((fractol->c_rgb.red * i /  maxIterations) << 16) | 
				((fractol->c_rgb.green * i /  maxIterations)<< 8) |
				(fractol->c_rgb.blue * i /  maxIterations)
			);
}
