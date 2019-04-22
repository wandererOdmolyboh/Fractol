/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manegment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:56:43 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/04/22 14:43:23 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int			manegment_control(int keycode, t_fractol *fractol)
{
	if (keycode == K_SHIFT)
    {
        color_fr(fractol);
		putter_pixel(fractol);
    }
    else if (keycode == K_PLUS)
        putter_pixel(fractol);
    else if (keycode == K_ESC)
        exit(0);
    else if (keycode == K_W)
        fractol->ff.fractal = &julias_v;
    else if (keycode == K_S)
        fractol->ff.fractal = &burning_ship_v;
	return (0);
}
