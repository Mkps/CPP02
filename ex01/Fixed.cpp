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
Fixed::Fixed(int value) : _fixedPointValue((value >> _fractionalBits))
{
    std::cout << "int constructor called" << std::endl;
}
Fixed::Fixed(float value) : _fixedPointValue(((int)value >> _fractionalBits))
{
    std::cout << "float constructor called" << std::endl;
}

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

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void    Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

float   Fixed::toFloat(void) const
{
    return ((int)_fixedPointValue << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return (_fixedPointValue);
}
