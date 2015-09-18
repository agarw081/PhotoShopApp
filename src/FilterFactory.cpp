//
//  FilterFactory.cpp
//  Student Support
//
//  Created by Seth Johnson on 2/6/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#include "FilterFactory.h"
#include "Filter.h"
#include "Threshold.h"
#include "Saturation.h"
#include "AdjustRGB.h"
#include "Quantize.h"
#include "DetectEdges.h"
#include "Blur.h"
#include "MotionBlur.h"
#include "Sharpen.h"
#include "SpecialFilter.h"
#include <string.h>



Filter* FilterFactory::createFilter(char* filterName) 
{
	Filter* filter;
	if(strcmp(filterName, "Threshold"))
	{
		filter = new Threshold();
		return filter;
	}
	else if (strcmp(filterName, "Saturation"))
	{
		filter = new Saturation();
		return filter;
	}
	else if (strcmp(filterName, "AdjustRGB"))
	{
		filter = new AdjustRGB();
		return filter;
	}
	else if (strcmp(filterName, "Quantize"))
	{
		filter = new Quantize();
		return filter;
	}
	else if (strcmp(filterName, "DetectEdges"))
	{
		filter = new DetectEdges();
		return filter;
	}
	else if (strcmp(filterName, "Blur"))
	{
		filter = new Blur();
		return filter;
	}
	else if (strcmp(filterName, "MotionBlur"))
	{
		filter = new MotionBlur();
		return filter;
	}
	else if (strcmp(filterName, "Sharpen"))
	{
		filter = new Sharpen();
		return filter;
	}
	else if (strcmp(filterName, "SpecialFilter"))
	{
		filter = new SpecialFilter();
		return filter;
	}
	
	return filter;
}