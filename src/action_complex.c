/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_complex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:20:23 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/21 14:55:45 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

t_complex	add(t_complex a, t_complex b)
{
	t_complex	c;
	
	c.x = a.x + b.x;
	c.i = a.i + b.i;
	return (c);
}

t_complex	sqr(t_complex a)
{
	t_complex c;
	
	c.x = a.x * a.x - a.i * a.i;
	c.i = 2 * a.x * a.i;
	return (c);
}

double absc(t_complex a)
{
	double c;

	c = a.x * a.x + a.i * a.i;
	return (c);
}

double absc2(t_complex a, t_complex b)
{
	double c;

	a.x = a.x - b.x;
	a.i = a.i - b.i;
	c = a.x * a.x + a.i * a.i;
	return (c);
}

/*
** t_complex  pow_z(t_complex input, int  p)
** {
**         t_complex rez;
**         rez.x = 0;
**         rez.i = 0;
**         **Пронормируем заданное комплексное число.
**         double  norm     = sqrt(input.x * input.x + input.i * input.i);
**         double  cos_phi  = input.x / norm;        
**         double  phi      = acos(cos_phi);    
**         **Представим заданное комплексное число
**         **z == z_real + i * z_imag
**         **в виде
**         **z == norm * (cos(phi) + i * sin(phi)).
**         **Возводя это число в степень p по формуле Муавра, получим:
**         **z^p = norm^p * (cos(p * phi) + i * sin(p * phi)),
**         **откуда
**         double  norm_p  = pow(norm, p);
**         rez.x        = norm_p * cos(p * phi);
**         rez.i        = norm_p * sin(p * phi);       
**     return (rez);     
** }
*/
