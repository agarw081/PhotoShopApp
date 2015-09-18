//
//  MConstant.cpp
//  Student Support
//
//  Created by Seth Johnson on 2/9/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#include "MConstant.h"
#include <cmath>

MConstant::MConstant(float radius, float opacity) : Mask(radius, opacity) 
{
	generateMask();
}

float MConstant::getIntensity(int x, int y, float radius) 
{
	float hyp = sqrt(x*x + y*y);
	if (hyp > radius) {
		return 0.0;
	} else {
		return 1.0;
	}
}
