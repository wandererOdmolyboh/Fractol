/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:53:51 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/04/08 15:51:28 by dmolyboh         ###   ########.fr       */
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

	c = a.x*a.x + a.i+a.i;
	return (c);
}

int value ( int x, int y)
{
    unsigned int nb_iter;
	t_complex complex1;//point;
	t_complex complex2;

	nb_iter = 0;
	complex1.x = x/W-1.5;
	complex1.i = y/H-0.5;
	complex2.x = 0;
	complex2.i = 0;
	while (absc(complex2) < 3 && nb_iter <= 34)
	{
           complex2 = add(sqr(complex2), complex1);
           nb_iter++;
    }
	if (nb_iter < 34)
		return ((16711680 * nb_iter)/33);
    else
		return (16777215);
}

void mandelbrot_set(t_fractol *fractol)
{
	int	x;
	int y;

	x = -1;
	y = -1;

	while (++x < V)
	{
		y = -1;
		while(++y < H)
		{
			mlx_pixel_put(fractol->mlx_ptr, fractol->win_ptr, x, y, value(x, y));
		}
	}
}
