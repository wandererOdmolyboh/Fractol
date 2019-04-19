/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmolyboh <dmolyboh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:53:51 by dmolyboh          #+#    #+#             */
/*   Updated: 2019/04/19 15:53:48 by dmolyboh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

	//complex1.x = 1.5 * (x - V / 2) / (0.5 * 500 * V);           
	//complex1.i = (y - H / 2) / (0.5 * 500 * H);

	// c->i = i / p->zoom - (FR_HE

void change_zoom(t_fractol *fractol)
{
	fractol->zoom *= ZOOM;
}


int julias_v(t_fractol *fractol,  double x, double y)
{
	//each iteration, it calculates: new = old*old + c, where c is a constant and old starts at current pixel
  double cRe, cIm;           //real and imaginary part of the constant c, determinate shape of the Julia Set
  double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old
  double zoom = 0.5, moveX = 0, moveY = 0; //you can change these to zoom and change position
  int color; //the RGB color value for the pixel
  int maxIterations = 10; //after how much iterations the function should stop

  //pick some values for the constant c, this determines the shape of the Julia Set
  cRe = (fractol->mouse_x);
  cIm = (fractol->mouse_y);
 	 //calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
  newRe = 1.5 * (x - W / 2) / (0.5 * zoom * W) + moveX;
  newIm = (y - H / 2) / (0.5 * zoom * H) + moveY;
  //i will represent the number of iterations
  int i;
  //start the iteration process
  for(i = 0; i < maxIterations; i++)
  {
		//remember value of previous iteration
		oldRe = newRe;
		oldIm = newIm;
		//the actual iteration, the real and imaginary part are calculated
		newRe = oldRe * oldRe - oldIm * oldIm + cRe;
		newIm = 2 * oldRe * oldIm + cIm;
		//if the point is outside the circle with radius 2: stop
		if((newRe * newRe + newIm * newIm) > 3)
			return(
			((4* i /  maxIterations) << 16) | 
			((fractol->c_rgb.green * i /  maxIterations)<< 8) |
			(fractol->c_rgb.blue * i /  maxIterations));
  }
  //use color model conversion to get rainbow palette, make brightness black if maxIterations reached
  //color = HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < maxIterations)));
  //draw the pixel
   color = 255 * i;
   return(
			((fractol->c_rgb.red * i /  maxIterations) << 16) | 
			((fractol->c_rgb.green * i /  maxIterations)<< 8) |
			(fractol->c_rgb.blue * i /  maxIterations));	
  // pset(x, y, color);
}



int mandelbor_v(t_fractol *fractol, double x, double y)
{
    unsigned int	nb_iter;
	t_complex		complex1;
	t_complex		complex2;

	nb_iter = 0;

	// FOR MANDELBROD
	complex1.x = (x / (300. + fractol->zoom)) - (W / 2. / (300. + fractol->zoom)) - 0.4;
	complex1.i = (y / (300. + fractol->zoom)) - (H / 2. / (300. + fractol->zoom));

	complex2.x = (fractol->mouse_x);//m_x / 100;
	complex2.i = (fractol->mouse_y);// m_y / 100;

	while (absc(complex2) < 16 && nb_iter <= 34)
	{
        complex2 = add(sqr(complex2), complex1);
		if(absc(complex2)>10000000)
		{
			nb_iter =  ((1000 * nb_iter / 33) << 16) | 
			((1000 * nb_iter / 33)<< 8) |
			(1000 * nb_iter/ 33);
			return(nb_iter);		

		} // maybe or not
        nb_iter++;
    }
	if (nb_iter < 33)
	{		
			nb_iter = ( ((fractol->c_rgb.alpha) << 24) |
			((fractol->c_rgb.red * nb_iter / 33) << 16) | 
			((fractol->c_rgb.green * nb_iter / 33)<< 8) |
			(fractol->c_rgb.blue * nb_iter/ 33));
			return(nb_iter);
	}
    else
		return (0);
}

// static int julias_v(t_fractol *fractol,  double x, double y)
// {
//  	double zx = 0.4;//scaled x coordinate of pixel # (scaled to lie in the Mandelbrot X scale (−2.5, 1))
//       // # zx represents the real part of z
//     double zy = -0.6;//scaled y coordinate of pixel # (scaled to lie in the Mandelbrot Y scale (−1, 1))
//     //    # zy represents the imaginary part of z 

// double xtemp;
//     int iteration = 0;
//     int max_iteration = 1000;
// 	cy = 0.4;
// 	cx =
//     while (zx * zx + zy * zy < 4  &&  iteration < max_iteration) 
//     {
//         xtemp = zx * zx - zy * zy;
//         zy = 2 * zx * zy  + cy;
//         zx = xtemp + cx;
    
//         iteration = iteration + 1 
//     }
  
//     if (iteration == max_iteration)
//         return black;
//     else
//         return iteration;
// }

void mandelbrot_set(/*double m_y, double m_x,*/ t_fractol *fractal)
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
			// colooor = mandelbor_v(fractal, x, y);
			colooor = (fractal->ff)(fractal, x, y);
			//printf("%i\n", colooor);
			// ft_memcpy(fractal->image_ptr + y + x * V, &colooor, sizeof(int));
			 *(fractal->image_ptr + x + y * W) = colooor;
		}
	}
	printf("%d %d\n", fractal->mouse_x, fractal->mouse_y);
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->image, 0, 0);
}
