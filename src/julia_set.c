/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:25:53 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/23 14:43:58 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int				julias_v(t_fractol *fractal, double x, double y)
{
	t_complex	c;
	t_complex	z1;
	t_complex	z2;
	int			max_nb;
	int			nb_iter;

	c.x = (fractal->mouse_x);
	c.i = (fractal->mouse_y);
	z2.x = 1.5 * (x - RES / 2) / (0.5 * (fractal->zoom / 2) * RES)
	+ fractal->mouse_x;
	z2.i = (y - RES / 2) / (0.5 * (fractal->zoom / 2) * RES) + fractal->mouse_y;
	nb_iter = 0;
	max_nb = 10;
	while (nb_iter < max_nb)
	{
		z1.x = z2.x;
		z1.i = z2.i;
		z2.x = z1.x * z1.x - z1.i * z1.i + c.x;
		z2.i = 2 * z1.x * z1.i + c.i;
		if ((z2.x * z2.x + z2.i * z2.i) > 3)
			return (((4 * nb_iter / max_nb) << 16) | ((fractal->c_rgb.green
	* nb_iter / max_nb) << 8) | (fractal->c_rgb.blue * nb_iter / max_nb));
			nb_iter++;
	}
	return (color_f(fractal, 0, nb_iter));
}
