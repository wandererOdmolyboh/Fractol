/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:38:01 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/04/23 13:39:20 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

static int		closer(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int				mouse_move(int x, int y, t_fractol *fractol)
{
	if (x > 0 && x < RES && y > 0 && y < RES)
	{
		(fractol->mouse_x) = (x - RES / 2) / KE_M;
		(fractol->mouse_y) = (-y + RES / 2) / KE_M;
		putter_pixel(fractol);
	}
	return (0);
}

int				mouse_press(int button, int x, int y, t_fractol *fractol)
{
	x = 0;
	y = 0;
	if (button == SCROLL_UP)
	{
		if (fractol->zoom < 20)
		{
			fractol->zoom += 0.3;
			putter_pixel(fractol);
		}
	}
	if (button == SCROLL_DW)
	{
		if (fractol->zoom > 1)
		{
			fractol->zoom -= 0.3;
			putter_pixel(fractol);
		}
	}
	return (0);
}

void			manager(t_fractol *fractol)
{
	mlx_hook(fractol->win_ptr, 4, 1, mouse_press, fractol);
	mlx_hook(fractol->win_ptr, 6, 1, mouse_move, fractol);
	mlx_hook(fractol->win_ptr, 2, 17, &manegment_control, fractol);
	mlx_hook(fractol->win_ptr, 17, 0, closer, fractol);
	mlx_loop(fractol->mlx_ptr);
}

void			window(t_fractol *fractol)
{
	t_complex	c;

	c.x = -0.8;
	c.i = 0.156;
	fractol->mlx_ptr = mlx_init();
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr, RES, RES,
	"_FRACTOL_42_");
	fractol->image = mlx_new_image(fractol->mlx_ptr, RES, RES);
	fractol->image_ptr = (int *)mlx_get_data_addr(fractol->image,
	&(fractol->bits_per_pixel), &(fractol->size_line), &(fractol->endian));
	putter_pixel(fractol);
	manager(fractol);
}
