/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:53:51 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/04/08 17:36:33 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	add(t_complex a, t_complex b)
{
	t_complex	c;
	
	c.x = a.x + b.x;
	c.i = a.i + b.i;
	return (c);
}

t_complex	sqr(t_complex a)
{
	t_complex c;
	
	c.x = a.x * a.x - a.i * a.i;
	c.i = 2 * a.x * a.i;
	return (c);
}

double absc(t_complex a)
{
	double c;

	c = a.x * a.x - a.i * a.i;
	return (c);
}

int value (double x, double y)
{
    unsigned int nb_iter;
	t_complex complex1;//point;
	t_complex complex2;
	int			red;
	int			green;
	int			blue;

	green = 0;
	blue = 0;
	red = 255;
	nb_iter = 0;
	complex1.x = (x / 500.) - (V / 2.0 / 500.) - 1.;
	complex1.i = (y / 500.) - (H / 2.0 / 500.) + 0.7;
	// c->i = i / p->zoom - (FR_HE
	complex2.x = 0;
	complex2.i = 0;
	while (absc(complex2) < 4 && nb_iter <= 34)
	{
        complex2 = add(sqr(complex2), complex1);
        nb_iter++;
    }
	if (nb_iter < 34)
		return ((255 * nb_iter)/33);
    else
		return (0);
}
	// if (nb_iter < 34)
	// 	return ((1671 * nb_iter)/33);
    // else
	// 	return (16777215);

void mandelbrot_set(t_fractol *fractol)
{
	int	x;
	int y;

	x = -1;
	y = -1;
	while (++y < V)
	{
		x = -1;
		while(++x < H)
		{
			mlx_pixel_put(fractol->mlx_ptr, fractol->win_ptr, x, y, value(x, y));
		}
	}
}
