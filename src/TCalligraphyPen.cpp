//
//  TCalligraphyPen.cpp
//  Student Support
//
//  Created by Seth Johnson on 2/6/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#include "TCalligraphyPen.h"
#include "MOval.h"

TCalligraphyPen::TCalligraphyPen() 
{
	m_mask = new MOval(7.0, 1.0, 70.0, 0.333);
}

std::string TCalligraphyPen::getName() 
{
	return "Caligraphy Pen";
}
