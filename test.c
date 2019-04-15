/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 22:52:09 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/15 20:46:56 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
// #include <stdio.h>
void tester_set(t_fractol *fractal)
{
    int i;
    int A;
    int B;
    double a;
    double b;
    double x;
    double y;
    double t;
    double n = W / 4;

    for (B = 0; B <= W; B++)
    {
        b = 2 - (B / n);
        for (A = 0; A <= W; A++)
        {
            a = -2 + (A / n);
            x = 0;
            y = 0;
            for(i = 1; i < 1000; i++)
            {
                t = x;
                x = ((x * x) - (y * y)) + a;
                y = (2 * t * y) + b;
                if (((x * x) + (y * y)) > 4)
                    break ;
            }
            if (i == 1000)
            {
		        *(fractal->image_ptr + A + B * W) = 100000;    
            }
            else
                 *(fractal->image_ptr + A + B * W) = 0;
        }
    }
    mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->image, 0, 0);
}