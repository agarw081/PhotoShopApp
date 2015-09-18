//
//  TBlur.h
//
//  Created by Christian Wohlwend.

#ifndef TBLUR_H
#define TBLUR_H

#include "Tool.h"
#include "Kernel.h"

class TBlur : public Tool 
{
public:
	TBlur();
	void applyKernelToBuffer(int toolX, int toolY, PixelBuffer* buffer);
	Kernel getKernel();
	std::string getName();
protected:
	Kernel m_kernel;
};

#endif