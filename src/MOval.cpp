//
//  MOval.cpp
//  Student Support
//
//  Created by Seth Johnson on 2/9/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#include "MOval.h"
#include <cmath>
MOval::MOval(float radius, float opacity, float angle, float ratio) : Mask(radius, opacity), m_angle(angle), m_ratio(ratio) {
	generateMask();
}

float MOval::getIntensity(int x, int y, float radius) 
{
	float hyp = sqrt(x*x + y*y);
	float a = radius;
	float b = m_ratio*radius;
	float theta = m_angle/180*M_PI;
	
	float h = powf(x*cos(theta)+y*sin(theta),2)/powf(a,2) + powf(x*sin(theta) - y*cos(theta),2)/powf(b, 2) ;
	if (h < 1)
		return 1.0;
	else
		return 0.0;
}
