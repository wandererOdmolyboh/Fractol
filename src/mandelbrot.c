/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:25:50 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/23 14:18:23 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int					mandelbor_v(t_fractol *fractal, double x, double y)
{
	unsigned int	nb_iter;
	t_complex		z;
	t_complex		c;
	unsigned int	max_iter;

	max_iter = 15;
	nb_iter = 0;
	z.x = (x / (300. + fractal->zoom * 50)) - (RES / 2. /
	(300. + fractal->zoom * 50)) - 0.4;
	z.i = (y / (300. + fractal->zoom * 50)) - (RES / 2. /
	(300. + fractal->zoom * 50));
	c.x = (fractal->mouse_x);
	c.i = (fractal->mouse_y);
	while (absc(c) < 16 && nb_iter <= max_iter)
	{
		c = add(sqr(c), z);
		if (absc(c) > 10000000)
			return (color_f(NULL, 1000, nb_iter));
		nb_iter++;
	}
	if (nb_iter < (max_iter - 1))
		return (color_f(fractal, 1000, nb_iter));
	else
		return (0);
}
