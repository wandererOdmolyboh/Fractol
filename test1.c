/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 20:47:16 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/15 21:01:14 by wanderer         ###   ########.fr       */
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
    double r1;
    double r2;

    r1 = -0.9;//(4.0*) - 2.0;
    r2 = 0;//(2.0*) - 1.0;
    for (B = 0; B <= W; B++)
    {
        b = 2 - (B / n);
        for (A = 0; A <= W; A++)
        {
            a = -2 + (A / n);
            x = a;
            y = b;
            for(i = 1; i < 1000; i++)
            {
                t = x;
                x = ((x * x) - (y * y)) + r1;
                y = (2 * t * y) + r2;
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
