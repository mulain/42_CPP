/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:45:51 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/14 16:46:57 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Tests thanks to kmeixner247! Big Shoutout!
int main(void)
{
	{
		std::cout << std::string(80, '-') << std::endl;
		std::cout << "TESTS FROM SUBJECT PDF:" << std::endl;
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
		std::cout << std::string(80, '-') << std::endl;
	}
	{
		Fixed const i1(5);
		Fixed const i2(13);
		Fixed const f1(3.14f);
		Fixed const f2(13.1523f);
		Fixed const ni(-2);
		Fixed const nf(-0.885f);

		std::cout << "ADDITION:" << std::endl;
		std::cout << i1 << "\t+ " << i2 << "\t\t= " << i1 + i2 << std::endl;
		std::cout << f1 << "\t+ " << f2 << "\t= " << f1 + f2 << std::endl;
		std::cout << i1 << "\t+ " << f1 << "\t= " << i1 + f1 << std::endl;
		std::cout << f2 << "\t+ " << i2 << "\t\t= " << f2 + i2 << std::endl;
		std::cout << i1 << "\t+ " << ni << "\t\t= " << i1 + ni << std::endl;
		std::cout << f1 << "\t+ " << nf << "\t= " << f1 + nf << std::endl;
		std::cout << ni << "\t+ " << nf << "\t= " << ni + nf << std::endl << std::endl;

		std::cout << "SUBTRACTION:" << std::endl;
		std::cout << i1 << "\t- " << i2 << "\t\t= " << i1 - i2 << std::endl;
		std::cout << f1 << "\t- " << f2 << "\t= " << f1 - f2 << std::endl;
		std::cout << i1 << "\t- " << f1 << "\t= " << i1 - f1 << std::endl;
		std::cout << f2 << "\t- " << i2 << "\t\t= " << f2 - i2 << std::endl;
		std::cout << i1 << "\t- " << ni << "\t\t= " << i1 - ni << std::endl;
		std::cout << f1 << "\t- " << nf << "\t= " << f1 - nf << std::endl;
		std::cout << ni << "\t- " << nf << "\t= " << ni - nf << std::endl << std::endl;

		std::cout << "MULTIPLICATION:" << std::endl;
		std::cout << i1 << "\t* " << i2 << "\t\t= " << i1 * i2 << std::endl;
		std::cout << f1 << "\t* " << f2 << "\t= " << f1 * f2 << std::endl;
		std::cout << i1 << "\t* " << f1 << "\t= " << i1 * f1 << std::endl;
		std::cout << f2 << "\t* " << i2 << "\t\t= " << f2 * i2 << std::endl;
		std::cout << i1 << "\t* " << ni << "\t\t= " << i1 * ni << std::endl;
		std::cout << f1 << "\t* " << nf << "\t= " << f1 * nf << std::endl;
		std::cout << ni << "\t* " << nf << "\t= " << ni * nf << std::endl << std::endl;

		std::cout << "DIVISION:" << std::endl;
		std::cout << i1 << "\t/ " << i2 << "\t\t= " << i1 / i2 << std::endl;
		std::cout << i2 << "\t/ " << i1 << "\t\t= " << i2 / i1 << std::endl;
		std::cout << f1 << "\t/ " << f2 << "\t= " << f1 / f2 << std::endl;
		std::cout << i1 << "\t/ " << f1 << "\t= " << i1 / f1 << std::endl;
		std::cout << f2 << "\t/ " << i2 << "\t\t= " << f2 / i2 << std::endl;
		std::cout << i1 << "\t/ " << ni << "\t\t= " << i1 / ni << std::endl;
		std::cout << f1 << "\t/ " << nf << "\t= " << f1 / nf << std::endl;
		std::cout << ni << "\t/ " << nf << "\t= " << ni / nf << std::endl << std::endl;
		std::cout << std::string(80, '-') << std::endl;
	}
	{
		Fixed const i1(2);
		Fixed const i2(-3);
		Fixed const f1(0.5f);
		Fixed const f2(-0.8f);
		std::cout << "COMPARISONS:" << std::endl;
		std::cout << i1 << "\t\t< " << i2 << "\t\t:" << (i1 < i2 ? " true " : " false ") << std::endl;
		std::cout << i2 << "\t\t< " << i1 << "\t\t:" << (i2 < i1 ? " true " : " false ") << std::endl;
		std::cout << f1 << "\t\t< " << f2 << "\t:" << (f1 < f2 ? " true " : " false ") << std::endl;
		std::cout << f2 << "\t< " << f1 << "\t\t:" << (f2 < f1 ? " true " : " false ") << std::endl << std::endl;

		std::cout << i1 << "\t\t> " << i2 << "\t\t:" << (i1 > i2 ? " true " : " false ") << std::endl;
		std::cout << i2 << "\t\t> " << i1 << "\t\t:" << (i2 > i1 ? " true " : " false ") << std::endl;
		std::cout << f1 << "\t\t> " << f2 << "\t:" << (f1 > f2 ? " true " : " false ") << std::endl;
		std::cout << f2 << "\t> " << f1 << "\t\t:" << (f2 > f1 ? " true " : " false ") << std::endl << std::endl;

		std::cout << i1 << "\t\t<= " << i2 << "\t\t:" << (i1 <= i2 ? " true " : " false ") << std::endl;
		std::cout << i2 << "\t\t<= " << i1 << "\t\t:" << (i2 <= i1 ? " true " : " false ") << std::endl;
		std::cout << f1 << "\t\t<= " << f2 << "\t:" << (f1 <= f2 ? " true " : " false ") << std::endl;
		std::cout << f2 << "\t<= " << f1 << "\t\t:" << (f2 <= f1 ? " true " : " false ") << std::endl;
		std::cout << f2 << "\t<= " << f2 << "\t:" << (f2 <= f2 ? " true " : " false ") << std::endl;
		std::cout << i1 << "\t\t<= " << i1 << "\t\t:" << (i1 <= i1 ? " true " : " false ") << std::endl << std::endl;

		std::cout << i1 << "\t\t>= " << i2 << "\t\t:" << (i1 >= i2 ? " true " : " false ") << std::endl;
		std::cout << i2 << "\t\t>= " << i1 << "\t\t:" << (i2 >= i1 ? " true " : " false ") << std::endl;
		std::cout << f1 << "\t\t>= " << f2 << "\t:" << (f1 >= f2 ? " true " : " false ") << std::endl;
		std::cout << f2 << "\t>= " << f1 << "\t\t:" << (f2 >= f1 ? " true " : " false ") << std::endl;
		std::cout << f2 << "\t>= " << f2 << "\t:" << (f2 >= f2 ? " true " : " false ") << std::endl;
		std::cout << i1 << "\t\t>= " << i1 << "\t\t:" << (i1 >= i1 ? " true " : " false ") << std::endl << std::endl;

		std::cout << i1 << "\t\t== " << i2 << "\t\t:" << (i1 == i2 ? " true " : " false ") << std::endl;
		std::cout << i2 << "\t\t== " << i1 << "\t\t:" << (i2 == i1 ? " true " : " false ") << std::endl;
		std::cout << f1 << "\t\t== " << f2 << "\t:" << (f1 == f2 ? " true " : " false ") << std::endl;
		std::cout << f2 << "\t== " << f1 << "\t\t:" << (f2 == f1 ? " true " : " false ") << std::endl;
		std::cout << f2 << "\t== " << f2 << "\t:" << (f2 == f2 ? " true " : " false ") << std::endl;
		std::cout << i1 << "\t\t== " << i1 << "\t\t:" << (i1 == i1 ? " true " : " false ") << std::endl << std::endl;

		std::cout << i1 << "\t\t!= " << i2 << "\t\t:" << (i1 != i2 ? " true " : " false ") << std::endl;
		std::cout << i2 << "\t\t!= " << i1 << "\t\t:" << (i2 != i1 ? " true " : " false ") << std::endl;
		std::cout << f1 << "\t\t!= " << f2 << "\t:" << (f1 != f2 ? " true " : " false ") << std::endl;
		std::cout << f2 << "\t!= " << f1 << "\t\t:" << (f2 != f1 ? " true " : " false ") << std::endl;
		std::cout << f2 << "\t!= " << f2 << "\t:" << (f2 != f2 ? " true " : " false ") << std::endl;
		std::cout << i1 << "\t\t!= " << i1 << "\t\t:" << (i1 != i1 ? " true " : " false ") << std::endl << std::endl;
		std::cout << std::string(80, '-') << std::endl;
	}
	{
		Fixed a;
		Fixed b(1);
		std::cout << "INCREMENT / DECREMENT" << std::endl;
		std::cout << "a\t= " << a << std::endl;
		std::cout << "++a\t= " << ++a << std::endl;
		std::cout << "a++\t= " << a++ << std::endl;
		std::cout << "a\t= " << a << std::endl << std::endl;

		std::cout << "b\t= " << b << std::endl;
		std::cout << "--b\t= " << --b << std::endl;
		std::cout << "b--\t= " << b-- << std::endl;
		std::cout << "b\t= " << b << std::endl;
		std::cout << std::string(80, '-') << std::endl;
	}

	{
		Fixed a(10);
		Fixed b(5.6f);
		Fixed const c_a(20);
		Fixed const c_b(42.42f);
		std::cout << "MIN / MAX" << std::endl;
		std::cout << "max(" << a << ", " << b << ")\t= " << Fixed::max(a, b) << std::endl;
		std::cout << "one constant:" << std::endl;
		std::cout << "max(" << a << ", " << c_b << ")\t= " << Fixed::max(a, c_b) << std::endl;
		std::cout << "two constants:" << std::endl;
		std::cout << "max(" << c_a << ", " << c_b << ")\t= " << Fixed::max(c_a, c_b) << std::endl << std::endl;

		std::cout << "min(" << a << ", " << b << ")\t= " << Fixed::min(a, b) << std::endl;
		std::cout << "one constant:" << std::endl;
		std::cout << "min(" << a << ", " << c_b << ")\t= " << Fixed::min(a, c_b) << std::endl;
		std::cout << "two constants:" << std::endl;
		std::cout << "min(" << c_a << ", " << c_b << ")\t= " << Fixed::min(c_a, c_b) << std::endl << std::endl;
		std::cout << std::string(80, '-') << std::endl;
	}

	return 0;
}