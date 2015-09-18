//
//  DetectEdges.h
//  Created by Christian Wohlwend.

#ifndef DETECTEDGES_H
#define DETECTEDGES_H

#include "DetectEdges.h"

class DetectEdges : public Filter 
{
public:
	DetectEdges();
	void buildKernel(PixelBuffer* buffer);
	void buildFilter(PixelBuffer* buffer);
	std::string getName();
protected:
	Kernel m_kernel;

};

#endif