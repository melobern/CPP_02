/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:16:27 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/15 18:25:24 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;

    // My main's additions
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << Fixed::min(a, b) << std::endl;
    Fixed const c(Fixed(5.05f) / Fixed(0));
    Fixed const d(Fixed(5.05f) / Fixed(2));
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    return (0);
}

