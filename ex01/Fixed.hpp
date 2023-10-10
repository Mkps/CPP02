/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:19:50 by aloubier          #+#    #+#             */
/*   Updated: 2023/10/10 14:58:44 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(int value);
		Fixed(float value);
		Fixed(const Fixed &src);
		Fixed& operator=(const Fixed &src);
		~Fixed();

		int     getRawBits(void) const;
		void    setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;

	private:
		int                 _fixedPointValue;
		static const int    _fractionalBits = 8;
};

std::ostream& operator<<(std::ostream &os, const Fixed &src);
#endif
