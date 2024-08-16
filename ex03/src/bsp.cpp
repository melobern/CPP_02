/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:15:55 by mbernard          #+#    #+#             */
/*   Updated: 2024/08/16 10:47:04 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

static Fixed calculArea(Point const a, Point const b, Point const c) {
    Fixed result;
    Fixed ax = a.getX();
    Fixed ay = a.getY();
    Fixed bx = b.getX();
    Fixed by = b.getY();
    Fixed cx = c.getX();
    Fixed cy = c.getY();

    result = (((bx - ax) * (cy - ay)) - ((by - ay) * (cx -ax))) * Fixed(0.5f);
    if (result < Fixed(0))
        result = result * Fixed(-1);
    return (result);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    if (a == b || a == c || b == c || point == a || point == b || point == c)
        return (false);

    Fixed totalArea = calculArea(a, b, c);
    Fixed replaceA = calculArea(b, c, point);
    Fixed replaceB = calculArea(a, c, point);
    Fixed replaceC = calculArea(a, b, point);
    Fixed zero(0);

    if (replaceA == zero || replaceB == zero || replaceC == zero)
        return (false);
    if (totalArea == replaceA + replaceB + replaceC)
        return (true);
    return (false);
}
