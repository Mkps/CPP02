/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:03:57 by aloubier          #+#    #+#             */
/*   Updated: 2023/12/17 16:13:23 by aloubier         ###   ########.fr       */
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

//	Getter / Setter
int Fixed::getRawBits(void) const
{
    return this->_fixedPointValue;
}

void    Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}
#include <bitset>
//	Member functions
float   Fixed::toFloat(void) const
{
    float a = (1 << this->_fractionalBits);
    std::bitset<32> x(a);
    std::cout << "1 << fb : " << x << std::endl;
    float b = (this->_fixedPointValue);
    std::bitset<32> y(b);
    std::cout << "fpv : " << y << std::endl;
    float c = ((float)this->_fixedPointValue / (1 << this->_fractionalBits));
    std::bitset<32> z(c);
    std::cout << "result: " << z << std::endl;
	return ((float)this->_fixedPointValue / (1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
    return (this->getRawBits() >> _fractionalBits);
}
