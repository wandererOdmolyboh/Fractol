/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:35:37 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/12 13:32:31 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_color(t_fractol *fractol)
{
    fractol->mouse_x = 0;
    fractol->mouse_y = 0;
    fractol->c_rgb.red = 255;
    fractol->c_rgb.blue = 0;
    fractol->c_rgb.green = 0;
    fractol->c_rgb.alpha = 50;
    fractol->c_rgb.color = (
        (fractol->c_rgb.red << 24) |
        (fractol->c_rgb.red << 16) |
    (fractol->c_rgb.green << 8) | (fractol->c_rgb.blue));
}

void    color_fr(t_fractol *fractol)
{
    enum colorset colorr;
    static int i;

    i++;
    if (i == 5)
        i = 0;
    if (i == 0)
        colorr = green;
    else if (i == 1)
        colorr = red; 
    else if (i == 2)
        colorr = blue;
    else if (i == 3)
        colorr = rainbow;
    else if (i == 4)
        colorr = green;
    else
         colorr = red;
    fractol->c_rgb.color = colorr;
    fractol->c_rgb.red = (fractol->c_rgb.color >> 16) & 0xFF;
    fractol->c_rgb.blue = (fractol->c_rgb.color >> 8) & 0xFF;
    fractol->c_rgb.green = (fractol->c_rgb.color) & 0xFF;
}
