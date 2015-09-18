//
//  Saturation.h
//  Created by Christian Wohlwend.

#ifndef SATURATION_H
#define SATURATION_H

#include "Filter.h"

class Saturation : public Filter 
{
public:
	Saturation();
	void applyFilter(PixelBuffer* buffer, float saturation_amount);
	std::string getName() ;
};

#endif