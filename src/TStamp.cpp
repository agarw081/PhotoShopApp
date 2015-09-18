//
//  TStamp.cpp
//
//  Created by Christian Wohlwend

#include "TStamp.h"
#include "ColorData.h"
#include "PixelBuffer.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

TStamp::TStamp() 
{

}

void TStamp::applyStamp(int toolX, int toolY, PixelBuffer* buffer, PixelBuffer* stamp, ColorData stampColorAdjust)
{
	int stampHeight = stamp->getHeight();
	int stampWidth = stamp->getWidth();
	int stampX = 0;
	int stampY = 0;
	for (int x = toolX - (stampWidth/2); x <toolX + (stampWidth/2); x++)
	{
		stampY = 0;
		for (int y = toolY - (stampHeight/2); y<toolY + (stampHeight/2); y++)
		{
			ColorData stampColor = ColorData(0,0,0,0);
			ColorData bufferColor = ColorData(0,0,0,0);
			if (!(x <= 0 || x >= buffer->getWidth() || y <= 0 || y >= buffer->getHeight()))
			{
				stampColor = stamp->getPixel(stampX,stampY);
				bufferColor = buffer ->getPixel(x,y);
				stampColor.setRed(stampColor.getRed() * stampColorAdjust.getRed());
				stampColor.setGreen(stampColor.getGreen() * stampColorAdjust.getGreen());
				stampColor.setBlue(stampColor.getBlue() * stampColorAdjust.getBlue());
				float  stampDifference = stampColor.getAlpha();
				float bufferDifference = (1 - stampDifference);
				stampColor = (stampColor * stampDifference) + (bufferColor * bufferDifference);
				buffer -> setPixel(x,y,stampColor);
			}
			stampY++;
		}
		stampX++;
	}
}
std::string TStamp::getName() 
{
	return "TStamp";
}