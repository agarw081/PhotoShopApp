//
//  Threshold.h
//  Created by Christian Wohlwend.

#ifndef THRESHOLD_H
#define THRESHOLD_H

#include "Filter.h"

class Threshold : public Filter 
{
public:
	Threshold();
	void applyFilter(PixelBuffer* buffer, float threshold_amount);
	std::string getName() ;
};

#endif