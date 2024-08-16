/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:16:27 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/16 10:47:44 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
    Point a(2.7115450918749, -5.5274601667918);
    Point b(8.9361377297741, -3.4827999756494);
    Point c(7.37102170669, 3.4801491046107);
    Point point(7.1101304493178, 0.208706702856);

    if (bsp(a, b, c, point)) {
        std::cout << GREEN << "The point is in the triangle" << RESET;
        std::cout << std::endl;
    } else {
        std::cout << RED << "The point isn't in the triangle" << RESET;
        std::cout << std::endl;
    }
    return (0);
}
