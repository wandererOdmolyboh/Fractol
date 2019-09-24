/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 19:30:10 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/23 14:18:37 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int					burning_ship_v(t_fractol *fractol, double x, double y)
{
	unsigned int	nb_iter;
	t_complex		z;
	t_complex		c;

	nb_iter = 0;
	z.x = (x / (300. + fractol->zoom * 50)) - (RES / 2. /
	(300. + fractol->zoom * 50)) - 0.4;
	z.i = (y / (300. + fractol->zoom * 50)) - (RES / 2. /
	(300. + fractol->zoom * 50));
	c.x = fractol->mouse_x;
	c.i = fractol->mouse_y;
	while (absc(c) < 16 && nb_iter <= 34)
	{
		c.x = c.x > 0 ? c.x : -c.x;
		c.i = c.i > 0 ? c.i : -c.i;
		c = add(sqr(c), z);
		nb_iter++;
	}
	if (nb_iter >= 12 && nb_iter <= 33)
		return (color_f(NULL, 16759040, nb_iter));
	if (nb_iter < 33)
		return (color_f(fractol, 0, nb_iter));
	else
		return (0);
}
