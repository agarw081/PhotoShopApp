//
//  MLinear.cpp
//  Student Support
//
//  Created by Seth Johnson on 2/9/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#include "MLinear.h"
#include <cmath>

MLinear::MLinear(float radius, float opacity) : Mask(radius, opacity) 
{
	generateMask();
}

float MLinear::getIntensity(int x, int y, float radius) 
{
	float hyp = sqrt(x*x + y*y);

	if (hyp <= radius) {
		return 1 - hyp/radius;
	} else {
		return 0.0;
		
	}
}
