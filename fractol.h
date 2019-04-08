/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 17:04:43 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/08 17:20:06 by dmolyboh         ###   ########.fr       */
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

# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2

# define H 2000
# define V 1300

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