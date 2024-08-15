/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:15:55 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/15 13:52:52 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() {
    this->_rawBits = 0;
    std::cout << "Default constructor called" << std::endl;
    return;
}

Fixed::Fixed(const Fixed &num) {
    std::cout << "Copy constructor called" << std::endl;
    *this = num;
    return;
}

Fixed::Fixed(const int num) {
    std::cout << "Int constructor called" << std::endl;\
    this->_rawBits = (num << Fixed::_fractionalBits);
    return;
}

Fixed::Fixed(const float num) {
    std::cout << "Float constructor called" << std::endl;
    this->_rawBits = roundf(num * (1 << Fixed::_fractionalBits));
    return;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
    return;
}

int     Fixed::getRawBits(void) const {
    return (this->_rawBits);
}

void    Fixed::setRawBits(int const raw) {
    this->_rawBits = raw;
    return;
}

float     Fixed::toFloat(void) const {
    float floatPoint = static_cast<float>(this->_rawBits);

    return(floatPoint / (1 << this->_fractionalBits));
}

int     Fixed::toInt(void) const {
    return(this->_rawBits >> this->_fractionalBits);
}

Fixed   &Fixed::operator=(const Fixed &num) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &num) {
        this->_rawBits = num.getRawBits();
    }
    return *this;
}

std::ostream &operator<<(std::ostream &outStream, const Fixed &num) {
    outStream << num.toFloat();
    return (outStream);
}
