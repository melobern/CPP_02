/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:13:56 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/16 10:48:17 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_INCLUDES_FIXED_HPP_
#define EX03_INCLUDES_FIXED_HPP_

#include <iostream>
#include <cmath>

class Fixed {
 public:
  Fixed(void);
  Fixed(const Fixed &num);
  Fixed(const int num);
  Fixed(const float num);
  ~Fixed(void);
  Fixed &operator=(const Fixed &num);
  /*     COMPARISON                 */
  bool operator>(const Fixed &num) const;
  bool operator<(const Fixed &num) const;
  bool operator>=(const Fixed &num) const;
  bool operator<=(const Fixed &num) const;
  bool operator==(const Fixed &num) const;
  bool operator!=(const Fixed &num) const;
  /*     ARITHMETIC                 */
  Fixed operator+(const Fixed &num);
  Fixed operator-(const Fixed &num);
  Fixed operator*(const Fixed &num);
  Fixed operator/(const Fixed &num);
  /*     INCREMENT && DECREMENT     */
  Fixed operator--(void);
  Fixed operator--(int);
  Fixed operator++(void);
  Fixed operator++(int);
  /*     FUNCTIONS                  */
  int     getRawBits(void) const;
  void    setRawBits(int const raw);
  float   toFloat(void) const;
  int     toInt(void) const;
  /*     MIN && MAX                 */
  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);

 private:
  static const int _fractionalBits = 8;
  int              _rawBits;
};

std::ostream &operator<<(std::ostream &outStream, const Fixed &num);

#endif  // EX03_INCLUDES_FIXED_HPP_
