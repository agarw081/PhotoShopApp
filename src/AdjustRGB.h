//
//  AdjustRGB.h
//  Created by Christian Wohlwend.

#ifndef ADJUST_RGB
#define ADJUST_RGB

#include "Filter.h"

class AdjustRGB : public Filter 
{
public:
	AdjustRGB();
	void applyFilter(PixelBuffer* buffer, float channelRed, float channelGreen, float channelBlue );
	std::string getName() ;
};

#endif