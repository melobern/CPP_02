/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:15:55 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/16 09:46:13 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point(void)
        :_x(0), _y(0) {
    return;
}

Point::Point(const float x, const float y)
        :_x(x), _y(y) {
    return;
}

Point::Point(const Point &point) {
    *this = point;
    return;
}

Point   &Point::operator=(const Point &point) {
    this->~Point();
    new (this) Point(point._x.toFloat(), point._y.toFloat());
    return (*this);
}

bool   Point::operator==(const Point &point) const {
    if (this->getX() == point.getX() && this->getY() == point.getY())
        return (true);
    return (false);
}

Point::~Point(void) {
    return;
}

Fixed Point::getX(void) const {
    return(this->_x);
}

Fixed Point::getY(void) const {
    return(this->_y);
}
