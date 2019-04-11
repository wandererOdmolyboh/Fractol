/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_complex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:20:23 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/11 16:21:03 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

	c = a.x * a.x - a.i * a.i;
	return (c);
}