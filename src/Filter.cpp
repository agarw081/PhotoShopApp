//
//  Filter.cpp
//  Created by Christian Wohlwend
//
//

#include "Filter.h"
#include "ColorData.h"
#include "PixelBuffer.h"
#include <cmath>
#include <iostream>
#include "Kernel.h"

using std::cout;
using std::endl;

Filter::Filter() 
{

}

void Filter::applyFilter(PixelBuffer* buffer, Kernel kernel)
{
	PixelBuffer* copyBuffer = new PixelBuffer(buffer->getWidth(), buffer->getHeight(), buffer->getBackgroundColor());
	buffer->copyPixelBuffer(buffer, copyBuffer);
	kernel.printKernel();
	for (int x= 0; x<buffer->getWidth(); x++)
	{
		for (int y = 0; y<buffer->getHeight(); y++)
		{
			ColorData currentColor = copyBuffer->getPixel(x,y);
			float correctedXRangeStart = x - floor((kernel.getWidth())/2);
			float correctedXRangeEnd = x + floor((kernel.getWidth())/2);
			float correctedYRangeStart = y - floor((kernel.getHeight())/2);
			float correctedYRangeEnd = y + floor((kernel.getHeight())/2);
			ColorData colorToAdd = ColorData(0,0,0,1);
			ColorData finalColor = ColorData(0,0,0,1);
			for (int i = correctedXRangeStart; i<= correctedXRangeEnd; i++)
			{
				for (int j = correctedYRangeStart; j<= correctedYRangeEnd; j++)
				{
					if (i <= 0 || i >= buffer->getWidth() || j <= 0 || j >= buffer->getHeight())
					{
						colorToAdd = currentColor;
					}
					else
					{
						colorToAdd = copyBuffer->getPixel(i,j);
					}
					colorToAdd = (colorToAdd * kernel.getData(i - correctedXRangeStart,j - correctedYRangeStart));
					finalColor = finalColor + colorToAdd;
				}
			}
			buffer->setPixel(x,y,finalColor);
		}
	}
}
void Filter::applyToBuffer(int x, int y, ColorData c, PixelBuffer* buffer)
{
	buffer->setPixel(x, y, c);
}