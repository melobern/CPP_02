/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:15:55 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/15 18:09:14 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() {
    this->_rawBits = 0;
    return;
}

Fixed::Fixed(const Fixed &num) {
    *this = num;
    return;
}

Fixed::Fixed(const int num) {
    this->_rawBits = (num << Fixed::_fractionalBits);
    return;
}

Fixed::Fixed(const float num) {
    this->_rawBits = roundf(num * (1 << Fixed::_fractionalBits));
    return;
}

Fixed::~Fixed() {
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
    if (this != &num) {
        this->_rawBits = num.getRawBits();
    }
    return *this;
}

std::ostream &operator<<(std::ostream &outStream, const Fixed &num) {
    outStream << num.toFloat();
    return (outStream);
}

/*     COMPARISON                 */
bool Fixed::operator>(const Fixed &num) const {
    return (this->_rawBits > num.getRawBits());
}

bool Fixed::operator<(const Fixed &num) const {
    return (this->_rawBits < num.getRawBits());
}

bool Fixed::operator>=(const Fixed &num) const {
    return (this->_rawBits >= num.getRawBits());
}

bool Fixed::operator<=(const Fixed &num) const {
    return (this->_rawBits <= num.getRawBits());
}

bool Fixed::operator==(const Fixed &num) const {
    return (this->_rawBits == num.getRawBits());
}

bool Fixed::operator!=(const Fixed &num) const {
    return (this->_rawBits != num.getRawBits());
}

/*     ARITHMETIC                 */
Fixed Fixed::operator+(const Fixed &num) {
    Fixed addition;

    addition.setRawBits(this->_rawBits + num.getRawBits());
    return (addition);
}

Fixed Fixed::operator-(const Fixed &num) {
    Fixed substract;

    substract.setRawBits(this->_rawBits - num.getRawBits());
    return (substract);
}

Fixed Fixed::operator*(const Fixed &num) {
    Fixed multi;
    int result = this->_rawBits * num.getRawBits();

    multi.setRawBits(result >> Fixed::_fractionalBits);
    return (multi);
}

Fixed Fixed::operator/(const Fixed &num) {
    Fixed division;

    if (num.getRawBits() == 0)
        std::cerr << "Division by zero" << std::endl;
    else
        division.setRawBits(((this->_rawBits << Fixed::_fractionalBits) / num._rawBits));
    return (division);
}


/*     INCREMENT && DECREMENT     */
Fixed Fixed::operator--(void) {
    --this->_rawBits;
    return *this;
}
Fixed Fixed::operator--(int) {
    Fixed before = *this;
    --this->_rawBits;
    return (before);
}

Fixed Fixed::operator++(void) {
    ++this->_rawBits;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed before = *this;
    ++this->_rawBits;
    return (before);
}

/*     MIN && MAX                 */
Fixed& Fixed::min(Fixed &a, Fixed &b) {
    if (a < b)
        return (a);
    return (b);
}
const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b)
        return (a);
    return (b);
}
Fixed& Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return (a);
    return (b);
}
const Fixed&     Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b)
        return (a);
    return (b);
}
