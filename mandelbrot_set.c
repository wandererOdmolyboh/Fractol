/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:53:51 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/04/12 13:34:00 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

	//complex1.x = 1.5 * (x - V / 2) / (0.5 * 500 * V);           
	//complex1.i = (y - H / 2) / (0.5 * 500 * H);

	// c->i = i / p->zoom - (FR_HE

static int value (t_fractol *fractol,  double x, double y)
{
    unsigned int	nb_iter;
	t_complex		complex1;
	t_complex		complex2;

	nb_iter = 0;

	// FOR MANDELBROD
	complex1.x = (x / 300.) - (W / 2. / 300.) - 0.4;
	complex1.i = (y / 300.) - (H / 2. / 300.);

	complex2.x = (fractol->mouse_x) / 1000.;//m_x / 100;
	complex2.i = (fractol->mouse_y) / 1000.;// m_y / 100;
	while (absc(complex2) < 16 && nb_iter <= 34)
	{
        complex2 = add(sqr(complex2), complex1);
        nb_iter++;
    }
	if (nb_iter < 34)
		return ( ((fractol->c_rgb.alpha) << 24) |
			((fractol->c_rgb.red * nb_iter / 33) << 16) | 
			((fractol->c_rgb.green * nb_iter / 33)<< 8) |
			((fractol->c_rgb.blue * nb_iter) / 33));
    else
		return (0);
}

void mandelbrot_set(/*double m_y, double m_x,*/ t_fractol *fractol)
{
	int	x;
	int y;
	int colooor;

	y = -1;
	while (++y < W)
	{
		x = -1;
		while(++x < H)
		{
			colooor = value(fractol, x, y);
			// ft_memcpy(fractol->image_ptr + y + x * V, &colooor, sizeof(int));
			 *(fractol->image_ptr + x + y * W) = colooor;
		}
	}
	printf("%d %d\n", fractol->mouse_x, fractol->mouse_y);
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr, fractol->image, 0, 0);
}
