/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:23:29 by mtomomit          #+#    #+#             */
/*   Updated: 2023/05/27 16:56:24 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float area(Point const a, Point const b, Point const c) {
	float	area;

	area = (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) + \
			b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) + \
			c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0;
	if (area < 0)
		area = -area;
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point){
	float	areaABC;
	float	areaPBC;
	float	areaAPC;
	float	areaABP;

	areaABC = area(a, b, c);
	areaPBC = area(point, b, c);
	areaAPC = area(a, point, c);
	areaABP = area(a, b, point);
	return (areaABC == areaPBC + areaAPC + areaABP);
}
