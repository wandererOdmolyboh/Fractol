/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 17:04:25 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/11 21:45:49 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	mandelbrot_set(fractol);
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
