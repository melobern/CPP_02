/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:13:56 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/15 12:51:19 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX00_INCLUDES_FIXED_HPP_
#define EX00_INCLUDES_FIXED_HPP_

#include <iostream>

class Fixed {
 public:
  Fixed(void);
  explicit Fixed(const Fixed &num);
  ~Fixed(void);
  Fixed &operator=(const Fixed &num);
  int   getRawBits(void) const;
  void  setRawBits(int const raw);
 private:
  static const int _eightBits = 8;
  int              _fixedComma;
};
#endif  // EX00_INCLUDES_FIXED_HPP_
