#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() :
	_x(0) ,_y(0)
{
}

Point::Point(float const a, float const b) :
	_x(a) ,_y(b)
{
}

Point::Point(Fixed const a, Fixed const b) :
	_x(a) ,_y(b)
{
}

Point::Point(const Point & src) :
	_x(src._x) ,_y(src._y)
{
}

Point::~Point()
{
}

Point&	Point::operator = (Point & rhs)
{
	return (rhs);
}

std::ostream & operator<<(std::ostream& os, Point const &rhs)
{
	os << "x: " << rhs.get_x() << " y: " << rhs.get_y();
	return (os);
}

Fixed Point::get_x(void) const
{
	return (_x);
}

Fixed Point::get_y(void) const 
{
	return (_y);
}
