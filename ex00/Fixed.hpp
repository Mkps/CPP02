/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:19:50 by aloubier          #+#    #+#             */
/*   Updated: 2023/12/16 19:46:30 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed& operator=(const Fixed &src);
		~Fixed();

		int     getRawBits(void) const;
		void    setRawBits(int const raw);

	private:
		int                 _fixedPointValue;
		static const int    _fractionalBits = 8;
};

#endif
