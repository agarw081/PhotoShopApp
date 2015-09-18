//
//  MotionBlur.h
//  Created by Christian Wohlwend.

#ifndef MOTIONBLUR_H
#define MOTIONBLUR_H

#include "MotionBlur.h"

class MotionBlur : public Filter 
{
public:
	MotionBlur();
	void buildKernelAndApply(PixelBuffer* buffer, float blurAmount, int blurDirection);
	std::string getName();
protected:
	Kernel m_kernel;

};

#endif