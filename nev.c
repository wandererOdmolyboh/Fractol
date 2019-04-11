/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:23:05 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/11 00:28:55 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include "fractol.h"


static int	closer(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void		window(t_fractol *fractol)
{
	fractol->mlx_ptr = mlx_init();
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr, H, V, "__FRACTOL_42__");
    fractol->image_ptr = mlx_new_image(fractol->mlx_ptr, V, H);
//	mandelbrot_set(fractol);
    for(int x = 0; x < 100; x++)
      mlx_put_image_to_window (fractol->mlx_ptr, fractol->win_ptr, fractol->image_ptr, x, 100);
    mlx_get_data_addr ( void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );
    mlx_hook(fractol->win_ptr, 17, 0, closer, fractol);
	mlx_loop(fractol->mlx_ptr);
}


int check(char *string)
{
	if (ft_strcmp(string, "Juliaset") == FALSE) 
		return (TRUE);
	else if (ft_strcmp(string, "Mandelbrot") == FALSE)
		return (TRUE);
	else if (ft_strcmp(string, "another") == FALSE)
		return (TRUE);
	return (FALSE);
}

int main(int argc, char **argv)
{
	t_fractol *fractol;

	ft_putstr(argv[1]);
	if (argc >= 2.0 && argc < 5 && check(argv[1]))
	{
		if ((fractol = (t_fractol *)malloc(sizeof(t_fractol))) == NULL)
			return (0);
		// if ((fractol->heigthm = H) <= H ||
		// (fractol->widthm = V) <= V)
		// 	return (0);
		window(fractol);
	}
	else 
		ft_putstr("Error2\n");
	return (0);
}
