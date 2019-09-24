/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manegment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:56:43 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/04/23 13:40:02 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

static int	addone_maneg(int keycode, t_fractol *fractol)
{
	if (keycode == K_S)
	{
		fractol->ff.fractal = &burning_ship_v;
		putter_pixel(fractol);
	}
	else if (keycode == K_D)
	{
		fractol->ff.fractal = &mandelbor_v;
		putter_pixel(fractol);
	}
	return (0);
}

int			manegment_control(int keycode, t_fractol *fractol)
{
	if (keycode == K_SHIFT)
	{
		color_fr(fractol);
		putter_pixel(fractol);
	}
	else if (keycode == K_ESC)
		exit(0);
	else if (keycode == K_W)
	{
		fractol->ff.fractal = &julias_v;
		putter_pixel(fractol);
	}
	else
		addone_maneg(keycode, fractol);
	return (0);
}
