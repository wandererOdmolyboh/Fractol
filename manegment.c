/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manegment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:56:43 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/04/19 15:52:49 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			manegment_control(int keycode, t_fractol *fractol)
{
	if (keycode == K_SHIFT)
    {
	//  printf("%d %d\n", fractol->mouse_x, fractol->mouse_y);

        color_fr(fractol);
		mandelbrot_set(fractol);
    }
    else if (keycode == K_PLUS)
    {
        change_zoom(fractol);
        mandelbrot_set(fractol);
    }
    else if (keycode == K_ESC)
    {
        exit(0);
    }
    else if (keycode == K_W)
        fractol->ff = &julias_v;
    // else if (keycode == K_S)
    //     fractol->ff = &_v;
    // else if (keycode == )
	return (0);
}