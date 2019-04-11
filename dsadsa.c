/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsadsa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanderer <wanderer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 08:56:12 by wanderer          #+#    #+#             */
/*   Updated: 2019/04/11 21:36:27 by wanderer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>


enum year {Jan = 2, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
enum colorset {red = 16777215, green = 1671, blue = 50000, rainbow = 34566};
  
int main() 
{ 
    int i;
    enum colorset colorr;

    i++;
    if (i == 1)
        colorr = red; 
    else if (i == 2)
        colorr = green;
    else if (i == 3)
        colorr = green;
    else if (i == 4)
        colorr = green;
    else if (i == 0)
        colorr = green;
    
   colorr = red;
   printf("%d \n", colorr);
   colorr++;
   printf("%d \n", colorr);
//    for (i=rainbow; i<=red; i++)       
//       printf("%d ", i); 
        
   return 0; 
}