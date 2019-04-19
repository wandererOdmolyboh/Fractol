/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 17:04:43 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/19 15:48:31 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
**Libs_bloks
*/

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

/*
**define_value_bloks
*/

# define TRUE 1
# define FALSE 0
# define ZOOM 3

/*
**define_keycode
*/

# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2
# define K_SHIFT /*65505*/257
# define K_ESC 53
# define K_PLUS 65451

/*
**Resoluton
*/

# define H 1200
# define W 1200

/*
**blocks_stuct
*/

typedef struct s_complex	t_complex;
typedef struct s_rgb		t_rgb;
typedef struct s_typefr		t_typefr;
typedef struct s_fractol	t_fractol;
typedef int	(*t_of_fra)		(t_fractol*, double, double);

struct	s_complex
{
	double		x;
	double		i;
};

struct	s_rgb
{
	int			color;
	int			red;
	int			blue;
	int			green;
	int			alpha;
};

struct	s_typefr
{
	char		*s;
	void		*fractal;
	int			rank;
};

struct	s_fractol
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_typefr	*fractal;
	t_rgb		c_rgb;
	void		*image;
	int			*image_ptr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	double		mouse_x;
	double		mouse_y;
	double		zoom;
	t_of_fra	ff;
	int			rank;
	char		*name;
};

enum			e_colorset
{
	red = 16777215,
	green = 1671,
	blue = 50000,
	rainbow = 9287168
};

		//16448000
	//9287168
	//1356820
	//-1286

/*
**return ((1671 * nb_iter)/33);
**		// return ((34566 * nb_iter)/33);
**		// return ((50000 * nb_iter)/20);
**		// return (16777215);
**colorset Error (line 90, col 0): colorset is not well prefixed.
*/
/*
**function_bloks
*/

double			absc(t_complex a);
t_complex		add(t_complex a, t_complex b);
t_complex		sqr(t_complex a);
void			mandelbrot_set(t_fractol *fractol);
int				manegment_control(int keycode, t_fractol *fractol);
void			color_fr(t_fractol *fractol);
void			init_color(t_fractol *fractol);
void change_zoom(t_fractol *fractol);
t_complex mapPoint(double radius,int x,int y);
void juliaSet(t_fractol *fractal, t_complex c, double radius, int n);
void tester_set(t_fractol *fractal);
int mandelbor_v(t_fractol *fractol,  double x, double y);
int julias_v(t_fractol *fractol,  double x, double y);
#endif
