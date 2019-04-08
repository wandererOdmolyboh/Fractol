/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 17:04:43 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/08 15:00:15 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define TRUE 1
# define FALSE 0

# define W 13
# define A 0
# define S 1
# define D 2

# define H 1000
# define V 1000

typedef struct	s_complex
{
	double		x;
	double		i;
}				t_complex;

typedef struct s_element
{
	int			x;
	int			y;
	int			color;
	int         end;
}				t_element;

typedef struct	s_fractol
{
	int			heigthm;
	int			widthm;
	char		*name;
	void		*mlx_ptr;
	void		*win_ptr;
	t_element	**matrix;
}				t_fractol;

void mandelbrot_set(t_fractol *fractol);

#endif