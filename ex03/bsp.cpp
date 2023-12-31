/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:47:21 by aloubier          #+#    #+#             */
/*   Updated: 2023/12/16 19:47:23 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <cmath>

float	ft_fabs(float x)
{
	if (x < 0)
		return -x;
	else
	 	return x;

}

float	getArea(Point const a, Point const b, Point const c)
{
	float	a1, b1, c1;

	a1 = a.get_x().toFloat() * (b.get_y().toFloat() - c.get_y().toFloat());
	b1 = b.get_x().toFloat() * (c.get_y().toFloat() - a.get_y().toFloat());
	c1 = c.get_x().toFloat() * (a.get_y().toFloat() - b.get_y().toFloat());

	return ft_fabs(((a1 + b1 + c1) / 2.0f));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	area_t, area_bc, area_ac, area_ab;

	area_t = getArea(a, b, c);
	area_bc = getArea(point, b, c);
	area_ac = getArea(a, point, c);
	area_ab = getArea(a, b, point);
	
	if (area_bc == 0 || area_ac == 0 || area_ab == 0)
		return (false);
	return (area_t == (area_bc + area_ac + area_ab));
}
