/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:53:51 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/04/11 22:19:35 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

	//complex1.x = 1.5 * (x - V / 2) / (0.5 * 500 * V);           
	//complex1.i = (y - H / 2) / (0.5 * 500 * H);

	// c->i = i / p->zoom - (FR_HE

static int value (t_fractol *fractol, /*double m_y, double m_x,*/ double x, double y)
{
    unsigned int	nb_iter;
	t_complex		complex1;
	t_complex		complex2;

	nb_iter = 0;

	// FOR MANDELBROD
	complex1.x = (x / 500.) - (V / 2. / 500.) - 1.;
	complex1.i = (y / 500.) - (H / 2. / 500.) + 0.7;

	complex2.x = 0;//m_x / 100;
	complex2.i = 0;// m_y / 100;
	while (absc(complex2) < 4 && nb_iter <= 34)
	{
        complex2 = add(sqr(complex2), complex1);
        nb_iter++;
    }
	if (nb_iter < 34)
		return (((fractol->c_rgb.red * nb_iter / 33) << 16) | 
			((fractol->c_rgb.green * nb_iter / 33)<< 8) |
			((fractol->c_rgb.blue * nb_iter) / 33));
    else
		return (0);
}

void mandelbrot_set(/*double m_y, double m_x,*/ t_fractol *fractol)
{
	int	x;
	int y;
	
	x = -1;
	y = -1;
	fractol->c_rgb.color = color_fr(fractol);
	while (++y < V)
	{
		x = -1;
		while(++x < H)
		{ 
			mlx_pixel_put(fractol->mlx_ptr, fractol->win_ptr, x, y, value(fractol, x, y));
		}
	}
}
