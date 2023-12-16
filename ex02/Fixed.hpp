/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:19:50 by aloubier          #+#    #+#             */
/*   Updated: 2023/12/16 19:47:11 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(int value);
		Fixed(float value);
		Fixed(const Fixed & src);
		~Fixed();

		Fixed&	operator=(const Fixed & rhs);
		//Comparison operators
		bool	operator >(Fixed const & rhs) const;
		bool	operator <(Fixed const & rhs) const;
		bool	operator >=(Fixed const & rhs) const;
		bool	operator <=(Fixed const & rhs) const;
		bool	operator ==(Fixed const & rhs) const;
		bool	operator !=(Fixed const & rhs) const;

		// Arithmetic Operators
		Fixed operator +(Fixed const & rhs) const;
		Fixed operator -(Fixed const & rhs) const;
		Fixed operator *(Fixed const & rhs) const;
		Fixed operator /(Fixed const & rhs) const;

		// Increment Operators
		Fixed & operator++ (void);
		Fixed operator ++(int);
		Fixed & operator-- (void);
		Fixed operator --(int);

		// Output member functions
		int		toInt(void) const;
		float	toFloat(void) const;

		// Comparison member functions
		static Fixed & min(Fixed & a, Fixed & b);
		static Fixed & max(Fixed & a, Fixed & b);
		static const Fixed & min(const Fixed & a, const Fixed & b);
		static const Fixed & max(const Fixed & a, const Fixed & b);

		// Getter/Setter
		int     getRawBits(void) const;
		void    setRawBits(int const raw);

	private:
		int                 _fixedPointValue;
		static const int    _fractionalBits = 8;
};

std::ostream& operator<<(std::ostream &os, const Fixed & rhs);

#endif
