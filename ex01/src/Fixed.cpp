/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:15:55 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/15 12:05:55 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() {
    this->fixedComma = 0;
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(const Fixed &num) {
    std::cout << "Copy constructor called" << std::endl;
    *this = num;
    return;
}

Fixed::Fixed(int num) {
    std::cout << "Int constructor called" << std::endl;
    
    *this = num;
    return;
}

Fixed::Fixed(float num) {
    std::cout << "Float constructor called" << std::endl;
    *this = num;
    return;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
    return;
}

int     Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedComma);
}

void    Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedComma = raw;
    return;
}

Fixed   &Fixed::operator=(const Fixed &num) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &num) {
        this->fixedComma = num.getRawBits();
    }
    return *this;
}
