/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:13:56 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/15 13:20:09 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_INCLUDES_FIXED_HPP_
#define EX01_INCLUDES_FIXED_HPP_

#include <iostream>
#include <cmath>

class Fixed {
 public:
  Fixed(void);
  explicit Fixed(const Fixed &num);
  explicit Fixed(const int num);
  explicit Fixed(const float num);
  ~Fixed(void);
  Fixed &operator=(const Fixed &num);
  int     getRawBits(void) const;
  void    setRawBits(int const raw);
  float   toFloat(void) const;
  int     toInt(void) const;
 private:
  static const int _fractionalBits = 8;
  int              _rawBits;
};

std::ostream &operator<<(std::ostream &outStream, const Fixed &num);

#endif  // EX01_INCLUDES_FIXED_HPP_
