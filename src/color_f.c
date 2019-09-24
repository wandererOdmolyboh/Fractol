/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:41:27 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/04/23 14:18:52 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int		color_f(t_fractol *fractal, int colorr, int nb_iter)
{
	int color_rez;

	if (fractal != NULL)
	{
		color_rez = (((fractal->c_rgb.alpha) << 24) |
		((fractal->c_rgb.red * nb_iter / 33) << 16) |
		((fractal->c_rgb.green * nb_iter / 33) << 8) |
		(fractal->c_rgb.blue * nb_iter / 33));
	}
	else
	{
		color_rez = colorr;
	}
	return (color_rez);
}
