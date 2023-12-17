/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:17:28 by aloubier          #+#    #+#             */
/*   Updated: 2023/12/17 17:03:07 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed big(100);
	Fixed bigcopy;
	bigcopy = big;
	Fixed small(1);
	std::cout << "is big bigger than small " << (big > small) << std::endl;
	std::cout << "is big bigger or equal to bigcopy" << (big >= bigcopy) << std::endl;
	std::cout << "is big smaller than small " << (big < small) << std::endl;
	std::cout << "is big smaller or equal to bigcopy" << (big <= bigcopy) << std::endl;
	std::cout << "is big equal to small " << (big == small) << std::endl;
	std::cout << "is big equal to bigcopy " << (big == bigcopy) << std::endl;
	std::cout << "big == 100 || big + big = " << big + big << std::endl;
	std::cout << "big == 100 || big - big = " << big - big << std::endl;
	std::cout << "big == 100 || big * big = " << big * big << std::endl;
	std::cout << "big == 100 || big / big = " << big / big << std::endl;
	std::cout << "small is : " << small << std::endl;
	std::cout << "small++ " << small++ << " " << small << std::endl;
	std::cout << "small is : " << small << std::endl;
	std::cout << "small-- " << small-- << " " << small << std::endl;
	std::cout << "small is : " << small << std::endl;
	std::cout << "++small" << ++small << " " << small << std::endl;
	std::cout << "small is : " << small << std::endl;
	std::cout << "--small" << --small << " " << small << std::endl;
	std::cout << "small is : " << small << std::endl;
	std::cout << "which is bigger big or small " << Fixed::max(big, small) << std::endl;
	std::cout << "which is smaller big or small " << Fixed::min(big, small) << std::endl;
	const Fixed cbig(100);
	const Fixed csmall(1);
	std::cout << "which is bigger big or small const edition " << Fixed::max(cbig, csmall) << std::endl;
	std::cout << "which is smaller big or small const edition " << Fixed::min(cbig, csmall) << std::endl;

	return 0;
}
