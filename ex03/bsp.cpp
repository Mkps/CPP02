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

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	area_t, area_bc, area_ac, area_ab;

	area_t = getArea(a, b, c);
	area_bc = getArea(point, b, c);
	area_ac = getArea(a, point, c);
	area_ab = getArea(a, b, point);

	return (area_t == (area_bc + area_ac + area_ab));
}
