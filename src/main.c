/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 17:04:25 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/21 15:33:48 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"


static int	closer(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

static int mouse_move(int x, int y, t_fractol *fractol)
{
	if (x > 0 && x < SQ_M && y > 0 && y < SQ_M)
	{
		(fractol->mouse_x) = (x - SQ_M/2) / KE_M;
		(fractol->mouse_y) = (-y + SQ_M/2 ) / KE_M;
		putter_pixel(fractol);
	}
	return (0);
}

void manager(t_fractol *fractol)
{//2
	mlx_hook(fractol->win_ptr, 6, 1, mouse_move, fractol);
	mlx_hook(fractol->win_ptr, 2, 17, &manegment_control, fractol);
	mlx_hook(fractol->win_ptr, 17, 0, closer, fractol);
	mlx_loop(fractol->mlx_ptr);
}

void		window(t_fractol *fractol)
{
	t_complex c;
	
	c.x = -0.8;
	c.i = 0.156;
	fractol->mlx_ptr = mlx_init();
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr, SQ_M, SQ_M, "__FRACTOL_42__");
	fractol->image = mlx_new_image(fractol->mlx_ptr, SQ_M, SQ_M);
	fractol->image_ptr = (int *)mlx_get_data_addr(fractol->image, &(fractol->bits_per_pixel),  &(fractol->size_line),  &(fractol->endian));
	fractol->ff.fractal = &burning_ship_v;
	//netwon(fractol);
	putter_pixel(fractol);
	manager(fractol);
}


int check(char *string)
{
	if (ft_strcmp(string, "Juliaset") == FALSE) 
		return (TRUE);
	else if (ft_strcmp(string, "Mandelbrot") == FALSE)
		return (TRUE);
	else if (ft_strcmp(string, "another") == FALSE)
		return (TRUE);
	else
	{
		ft_putstr(string);
		ft_putstr(" not found name\n");
	}
	return (FALSE);
}

int main(int argc, char **argv)
{
	t_fractol fractal;

	if (argc >= 2.0 && argc < 4 && check(argv[1]))
	{
		fractal.name = argv[1];
		init_value(&fractal);
		window(&fractal);
	}
	else if (argc == 1 || argc > 3)
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putstr(" Juliaset | Mandelbrot | another or 2 combination\n");
	}
	return (0);
}
