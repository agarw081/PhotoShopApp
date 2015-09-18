//
//  TStamp.h
//
//  Created by Christian Wohlwend


#ifndef TSTAMP_H
#define TSTAMP_H

#include "Tool.h"

class TStamp : public Tool 
{
public:
	TStamp();
	void applyStamp(int toolX, int toolY, PixelBuffer* buffer, PixelBuffer* stamp, ColorData stampColorAdjust);

	
	std::string getName();
};

#endif