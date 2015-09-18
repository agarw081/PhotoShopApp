//
//  TCalligraphyPen.h
//  Student Support
//
//  Created by Seth Johnson on 2/6/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//
//  This tool simulates the usage of a Calligraphy Pen.
//
//  It has a MOval mask with a radius of 7.0 (diameter of 15), an opacity of 1.0
//  (completely opaque), an angle of 70 degrees counter-clockwise from the x-axis,
//  and an elongation ratio of 0.333

#ifndef TCALLIGRAPHYPEN_H
#define TCALLIGRAPHYPEN_H

#include "Tool.h"

class TCalligraphyPen : public Tool 
{
public:
	TCalligraphyPen();
	
	std::string getName();
};

#endif
