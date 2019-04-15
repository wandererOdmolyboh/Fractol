/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 17:04:25 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/15 20:02:16 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static int	closer(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

static int mouse_move(int x, int y, t_fractol *fractol)
{
	if (x > 0 && x < W && y > 0 && y < H)
	{
		(fractol->mouse_x) = x;
		(fractol->mouse_y) = y;
		mandelbrot_set(fractol);
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
	// t_complex c;
 
	
	// c.x = -0.8;
	// c.i = 0.156;
	fractol->mlx_ptr = mlx_init();
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr, H, W, "__FRACTOL_42__");
	
	fractol->image = mlx_new_image(fractol->mlx_ptr, W, H);
	fractol->image_ptr = (int *)mlx_get_data_addr(fractol->image, &(fractol->bits_per_pixel),  &(fractol->size_line),  &(fractol->endian));
// -0.8 and 0.156.
	//juliaSet(fractol, c, 5, 4);
	tester_set(fractol);
	//mandelbrot_set(fractol);
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
		ft_putstr(" not found name ");
	}
	return (FALSE);
}

int main(int argc, char **argv)
{
	t_fractol *fractol;

	if (argc >= 2.0 && argc < 5 && check(argv[1]))
	{
		if ((fractol = (t_fractol *)malloc(sizeof(t_fractol))) == NULL)
			return (0);
		init_color(fractol);
		window(fractol);
	}
	else 
		ft_putstr("Error\n");
	return (0);
}
