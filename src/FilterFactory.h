//
//  FilterFactory.h
//  Created by Christian Wohlwend.

#ifndef FILTERFACTORY_H
#define FILTERFACTORY_H

#include <vector>
#include "Threshold.h"
#include "Saturation.h"
#include "AdjustRGB.h"
#include "Quantize.h"
#include "Blur.h"
#include "MotionBlur.h"
#include "Sharpen.h"
#include "SpecialFilter.h"

class Filter;

class FilterFactory 
{
public:
	static Filter* createFilter(char* filterName);
};

#endif