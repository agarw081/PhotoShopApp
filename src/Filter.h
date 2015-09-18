//
//  Filter.h
//  Created by Christian Wohlwend
//
//  Tool is the representation of a particular PaintShop tool.
//  This baseclass is abstract and does not provide a default mask.
//  Tools inherited from this class should provide a name and a mask.
//  Inherited classes may optionally override the default colorBlendMath.


#ifndef FILTER_H
#define FILTER_H 

#include <string>
#include "Kernel.h"

class PixelBuffer;
class ColorData;

/// This is the superclass for Tools.
class Filter 
{
public:
	Filter();
	
	void applyFilter(PixelBuffer* buffer, Kernel kernel);
	virtual void applyToBuffer(int x, int y, ColorData c, PixelBuffer* buffer);

	
};

#endif