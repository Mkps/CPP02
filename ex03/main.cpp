/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:17:28 by aloubier          #+#    #+#             */
/*   Updated: 2023/10/10 14:43:28 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

void	testTriangle(bool result)
{
	if (result)
		std::cout << "inside" << std::endl;
	else
		std::cout << "outside" << std::endl;

}

int main( void ) {

	// Original tests
	/// Test inside 
	Point A(0, 0), B(10, 30), C(20, 0), P(10, 15);
	testTriangle(bsp(A, B, C, P)); // Should output "inside"
	/// Test outside
	Point A0(0, 0), B0(10, 30), C0(20, 0), P0(30, 15);
	testTriangle(bsp(A0, B0, C0, P0)); // Should output "outside"
	/// Test inside with float values 
	Point	Pn(4.18f, 3.02f);
	Point	An(0, 0);
	Point	Bn(5.12, 4.16);
	Point	Cn(1.18, -6.49);
	testTriangle(bsp(An, Bn, Cn, Pn)); // Should output "inside"
	// Test 1: Point inside the triangle
	Point A2(0, 0), B2(4, 0), C2(2, 4), P2(2, 2);
	testTriangle(bsp(A2, B2, C2, P2)); // Should output "inside"

	// Test 2: Point outside the triangle
	Point A3(0, 0), B3(4, 0), C3(2, 4), P3(5, 5);
	testTriangle(bsp(A3, B3, C3, P3)); // Should output "outside"

	// Test 3: Point on the vertex of the triangle
	Point A4(0, 0), B4(4, 0), C4(2, 4), P4(0, 0);
	testTriangle(bsp(A4, B4, C4, P4)); // Should output "outside"
									   //
	// Test 4: Point on the edge of the triangle
	Point A5(0, 0), B5(4, 0), C5(2, 4), P5(2, 0);
	testTriangle(bsp(A5, B5, C5, P5)); // Should output "outside"

	// Test 5: Degenerate triangle (line segment)
	Point A6(0, 0), B6(4, 0), C6(8, 0), P6(2, 0);
	testTriangle(bsp(A6, B6, C6, P6)); // Should output "outside"

	// Test 6: Colinear points, forming a line
	Point A7(0, 0), B7(4, 4), C7(2, 2), P7(1, 1);
	testTriangle(bsp(A7, B7, C7, P7)); // Should output "outside"

	// Test 7: Negative coordinates and quadrants
	Point A8(-2, -2), B8(2, -2), C8(0, 2), P8(0, 0);
	testTriangle(bsp(A8, B8, C8, P8)); // Should output "inside"
	return 0;
}
