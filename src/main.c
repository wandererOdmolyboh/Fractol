/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 17:04:25 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/23 14:45:21 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int				check(char *string)
{
	if (ft_strcmp(string, "Juliaset") == FALSE)
		return (TRUE);
	else if (ft_strcmp(string, "Mandelbrot") == FALSE)
		return (TRUE);
	else if (ft_strcmp(string, "burning_ship") == FALSE)
		return (TRUE);
	else
	{
		ft_putstr(string);
		ft_putstr(" not found name\n");
	}
	return (FALSE);
}

void			choice_frac(t_fractol *fractal, char *string)
{
	if (ft_strcmp(string, "Juliaset") == FALSE)
		fractal->ff.fractal = &julias_v;
	else if (ft_strcmp(string, "Mandelbrot") == FALSE)
		fractal->ff.fractal = &mandelbor_v;
	else if (ft_strcmp(string, "burning_ship") == FALSE)
		fractal->ff.fractal = &burning_ship_v;
}

int				main(int argc, char **argv)
{
	t_fractol	fractal;

	if (argc == 2 && argc < 4 && check(argv[1]))
	{
		choice_frac(&fractal, argv[1]);
		fractal.name = argv[1];
		init_value(&fractal);
		window(&fractal);
	}
	else
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putstr(" Juliaset | Mandelbrot | burning_ship\n");
	}
	return (0);
}
