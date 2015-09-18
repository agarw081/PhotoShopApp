//
//  Quantize.h
//  Created by Christian Wohlwend.

#ifndef QUANTIZE_H
#define QUANTIZE_H

#include "Filter.h"

class Quantize : public Filter 
{
public:
	Quantize();
	void applyFilter(PixelBuffer* buffer, float binNum);
	std::string getName() ;
};

#endif