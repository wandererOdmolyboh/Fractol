/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:25:50 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/21 14:53:45 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractal.h"

int mandelbor_v(t_fractol *fractol, double x, double y)
{
    unsigned int	nb_iter;
	t_complex		z;
	t_complex		c;
	// double			tmp;

	// tmp = x;
	// x = y;
	// y = tmp;

	nb_iter = 0;
	z.x = (x / (300. + fractol->zoom)) - (SQ_M / 2. / (300. + fractol->zoom)) - 0.4;
	z.i = (y / (300. + fractol->zoom)) - (SQ_M / 2. / (300. + fractol->zoom));
	c.x = (fractol->mouse_x);
	c.i = (fractol->mouse_y);// try to mac work with difine number
	while (absc(c) < 16 && nb_iter <= 34)
	{
		c.x = c.x > 0 ? c.x : -c.x;
        c.i = c.i > 0 ? c.i : -c.i; 
        c = add(sqr(c), z);
		if(absc(c) > 10000000)
		{
			nb_iter =  ((1000 * nb_iter / 33) << 16) |//the color has been chndge
			((1000 * nb_iter / 33)<< 8) |
			(1000 * nb_iter/ 33);
			return(nb_iter);
		}
		nb_iter++;
    }
	if (nb_iter < 33)
	{
			nb_iter = ( ((fractol->c_rgb.alpha) << 24) |
			((fractol->c_rgb.red * nb_iter / 33) << 16) | 
			((fractol->c_rgb.green * nb_iter / 33)<< 8) |
			(fractol->c_rgb.blue * nb_iter/ 33));
			return(nb_iter);
	}
    else
		return (0);
}