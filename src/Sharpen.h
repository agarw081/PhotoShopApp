//
//  Sharpen.h
//  Created by Christian Wohlwend.

#ifndef SHARPEN_H
#define SHARPEN_H

#include "Sharpen.h"

class Sharpen : public Filter 
{
public:
	Sharpen();
	void buildKernelAndApply(PixelBuffer* buffer, float sharpenAmount);
	std::string getName();
protected:
	Kernel m_kernel;

};

#endif