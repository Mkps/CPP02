/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:03:57 by aloubier          #+#    #+#             */
/*   Updated: 2023/12/17 16:56:57 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//	Constructors
Fixed::Fixed()
{
    this->_fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::Fixed(int value) : _fixedPointValue(value << _fractionalBits)
{
}

Fixed::Fixed(float value) : _fixedPointValue((int)roundf(value * (1 << _fractionalBits)))
{
}

//	Destructor
Fixed::~Fixed()
{
}

//	Operators
Fixed &Fixed::operator =(const Fixed &rhs)
{
    this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

std::ostream &operator <<(std::ostream& os, const Fixed& rhs)
{
    os << rhs.toFloat(); 
    return (os);
}

///		Comparison Operators
bool	Fixed::operator >(Fixed const & rhs) const
{
	if (this->getRawBits() > rhs.getRawBits())
		return (1);
	return (0);
}

bool	Fixed::operator <(Fixed const & rhs) const
{
	if (this->getRawBits() < rhs.getRawBits())
		return (1);
	return (0);
}

bool	Fixed::operator >=(Fixed const & rhs) const
{
	if (this->getRawBits() >= rhs.getRawBits())
		return (1);
	return (0);
}

bool	Fixed::operator <=(Fixed const & rhs) const
{
	if (this->getRawBits() <= rhs.getRawBits())
		return (1);
	return (0);
}

bool	Fixed::operator ==(Fixed const & rhs) const
{
	if (this->getRawBits() == rhs.getRawBits())
		return (1);
	return (0);
}

bool	Fixed::operator !=(Fixed const & rhs) const
{
	if (this->getRawBits() != rhs.getRawBits())
		return (1);
	return (0);
}

///		Arithmetic Operators
Fixed	Fixed::operator +(Fixed const & rhs) const
{
	Fixed	ret(this->toFloat() + rhs.toFloat());
	return (ret);
}

Fixed	Fixed::operator -(Fixed const & rhs) const
{
	Fixed	ret(this->toFloat() - rhs.toFloat());
	return (ret);
}

Fixed	Fixed::operator *(Fixed const & rhs) const
{
	Fixed	ret(this->toFloat() * rhs.toFloat());
	return (ret);
}

Fixed	Fixed::operator /(Fixed const & rhs) const
{
	Fixed	ret(this->toFloat() / rhs.toFloat());
	return (ret);
}

///		Increment Operators
Fixed & Fixed::operator++ (void)
{
	this->_fixedPointValue += 1;
	return (*this);
}

Fixed Fixed::operator ++(int)
{
	Fixed	temp = *this;

	this->_fixedPointValue += 1 ;
	return (temp);
}

Fixed & Fixed::operator-- (void)
{
	this->_fixedPointValue -= 1;
	return (*this);
}


Fixed Fixed::operator --(int)
{
	Fixed	temp = *this;

	this->_fixedPointValue -= 1 ;
	return (temp);
}

//	Getter / Setter
int Fixed::getRawBits(void) const
{
    return this->_fixedPointValue;
}

void    Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

//	Member functions
///	Output funcitons
float   Fixed::toFloat(void) const
{
	return ((float)this->getRawBits() / (1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
    return (this->getRawBits() >> this->_fractionalBits);
}
///	Comparison functions
const Fixed & Fixed::min(const Fixed & a, const Fixed & b)
{
	if (a < b)
		return (a);
	return (b);
}
	
const Fixed & Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed & Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}
	
Fixed & Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}
