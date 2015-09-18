//
//  TEraser.cpp
//  Student Support
//
//  Created by Seth Johnson on 2/6/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#include "TEraser.h"
#include "MConstant.h"
#include "ColorData.h"

TEraser::TEraser() 
{
	m_mask = new MConstant(10.0,1.0);
}

std::string TEraser::getName() 
{
	return "Eraser";
}

//  Eraser does not blend colors with the toolColor.  Here we are overriding the
//      superclass's colorBlendMath to set the canvasColor to the backgroundColor.
ColorData TEraser::colorBlendMath(float mask, ColorData toolColor, ColorData canvasColor, ColorData backgroundColor) 
{
	return backgroundColor*mask + canvasColor*(1-mask);
}
