//
//  Blur.h
//  Created by Christian Wohlwend.

#ifndef BLUR_H
#define BLUR_H

#include "Blur.h"

class Blur : public Filter 
{
public:
	Blur();
	void buildKernelAndApply(PixelBuffer* buffer, float blurAmount);
	std::string getName();
protected:
	Kernel m_kernel;

};

#endif