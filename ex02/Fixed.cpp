/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:03:57 by aloubier          #+#    #+#             */
/*   Updated: 2023/10/10 14:59:28 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//	Constructors
Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int value) : _fixedPointValue(value << _fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float value) : _fixedPointValue((int)roundf(value * (1 << _fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

//	Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//	Operators
Fixed &Fixed::operator =(const Fixed &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_fixedPointValue = src.getRawBits();
    return *this;
}

std::ostream &operator <<(std::ostream& os, const Fixed& src)
{
    os << src.toFloat(); 
    return (os);
}

///		Comparison Operators
bool	Fixed::operator >( Fixed const & right) const
{
	if (this->getRawBits() > right.getRawBits())
		return (1);
	return (0);
}

bool	Fixed::operator <( Fixed const & right) const
{
	if (this->getRawBits() < right.getRawBits())
		return (1);
	return (0);
}

bool	Fixed::operator >=( Fixed const & right) const
{
	if (this->getRawBits() >= right.getRawBits())
		return (1);
	return (0);
}

bool	Fixed::operator <=( Fixed const & right) const
{
	if (this->getRawBits() <= right.getRawBits())
		return (1);
	return (0);
}

bool	Fixed::operator ==( Fixed const & right) const
{
	if (this->getRawBits() == right.getRawBits())
		return (1);
	return (0);
}

bool	Fixed::operator !=( Fixed const & right) const
{
	if (this->getRawBits() != right.getRawBits())
		return (1);
	return (0);
}
///		Arithmetic Operators
///		Increment Operators
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
float   Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
    return (this->getRawBits() >> _fractionalBits);
}
