/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:47:44 by aloubier          #+#    #+#             */
/*   Updated: 2023/12/16 19:47:45 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point {
public:
	Point();
	Point(float const, float const);
	Point(Fixed const, Fixed const);
	Point(Point const & src);
	Point&	operator=(Point & rhs);
	~Point();
	Fixed	get_x(void) const;
	Fixed	get_y(void) const;

private:
	Fixed const	_x;
	Fixed const	_y;
};

std::ostream & operator<<(std::ostream& os, Point const &src);

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
