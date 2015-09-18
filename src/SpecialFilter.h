//
//  SpecialFilter.h
//  Created by Christian Wohlwend.

#ifndef SPECIALFILTER_H
#define SPECIALFILTER_H

#include "SpecialFilter.h"

class SpecialFilter : public Filter 
{
public:
	SpecialFilter();
	void buildKernel(PixelBuffer* buffer);
	void buildFilter(PixelBuffer* buffer);
	std::string getName();
protected:
	Kernel m_kernel;

};

#endif