//
//  THighlighter.cpp
//  Student Support
//
//  Created by Seth Johnson on 2/6/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#include "THighlighter.h"
#include "MOval.h"
#include "ColorData.h"

THighlighter::THighlighter() 
{
	m_mask = new MOval(7.0, 0.4, 90, 0.3);
}

std::string THighlighter::getName() 
{
	return "Highlighter";
}

//  Overrides the super's function to include the luminance of the canvasColor in
//      the calculation of the tool's intensity
ColorData THighlighter::colorBlendMath(float mask, ColorData toolColor, ColorData canvasColor, ColorData backgroundColor) 
{
	float L = canvasColor.getLuminance();
	float intensity = mask*L;
	return toolColor*intensity + canvasColor*(1.0-intensity);
}
