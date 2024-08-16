/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:13:56 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/16 09:29:15 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_INCLUDES_POINT_HPP_
#define EX03_INCLUDES_POINT_HPP_

#include <iostream>
#include <cmath>
#include "../includes/Fixed.hpp"

class Point {
 public:
  Point(void);
  Point(const float x, const float y);
  Point(const Point &point);
  Point &operator=(const Point &point);
  ~Point(void);
  bool operator==(const Point &point) const;
  Fixed getX(void) const;
  Fixed getY(void) const;
 private:
  const Fixed _x;
  const Fixed _y;
};

#endif  // EX03_INCLUDES_POINT_HPP_
