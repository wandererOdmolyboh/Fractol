/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JuliaSet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 22:15:51 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/13 22:34:53 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex mapPoint(double radius,int x,int y)
{
	t_complex c;
 
	c.x = 2*radius*(x - 1000/2.0)/1000;
	c.i = 2*radius*(y - 1000/2.0)/1000;
 
	return c;
}
 
void juliaSet(t_fractol *fractal, t_complex c, double radius, int n)
{
	int x,y,i;
	t_complex z0,z1;
 
	for(x=0;x<=1000;x++)
		for(y=0;y<=1000;y++)
        {
			z0 = mapPoint(radius,x,y);
			for(i=1;i<=n;i++){
				z1 = add(sqr(z0),c);
				if(absc(z1)>radius)
                {
					*(fractal->image_ptr + x + y * W) = 100000;
					break;
				}
				z0 = z1;
			}
			if(i>n)
				*(fractal->image_ptr + x + y * W) = 0;
		}
    mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->image, 0, 0);
}