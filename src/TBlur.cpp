//
//  TBlur.cpp
//
//  Created by Christian Wohlwend.

#include "TBlur.h"
#include "MLinear.h"
#include "Kernel.h"
#include "ColorData.h"
#include "Mask.h"
#include "PixelBuffer.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

TBlur::TBlur() 
{
	//m_mask = new MLinear(30, 0.2);
	Kernel m_kernel;
    //cout<<"Starting kernel init"<<endl;
    m_kernel.initSize(3);
    float AmountOfDiamondElem = m_kernel.totalElementsInDiamond();
    //cout<<"kennel init size"<<endl;
    m_kernel.buildDiamond(1/AmountOfDiamondElem);



	
}

void TBlur::applyKernelToBuffer(int toolX, int toolY, PixelBuffer* buffer)
{
	Kernel m_kernel;
    m_kernel.initSize(3);
    float AmountOfDiamondElem = m_kernel.totalElementsInDiamond();
    m_kernel.buildDiamond(1/AmountOfDiamondElem);

    PixelBuffer* copyBuffer = new PixelBuffer(buffer->getWidth(), buffer->getHeight(), buffer->getBackgroundColor());
	buffer->copyPixelBuffer(buffer, copyBuffer);
	int correctedX = 0;
	int correctedY = 0;
	for (int x= toolX-15; x<toolX+15; x++)
	{
		correctedY = 0;
		for (int y = toolY-15; y<toolY+15; y++)
		{
			float distanceToCenter = sqrt(pow((correctedX - 15),2) + pow( ((correctedY) - 15),2));
			if(distanceToCenter < 15)
			{
			ColorData currentColor = copyBuffer->getPixel(toolX,toolY);
			// Begin kernel application
			float correctedXRangeStart = x - floor((m_kernel.getWidth())/2);
			float correctedXRangeEnd = x + floor((m_kernel.getWidth())/2);
			float correctedYRangeStart = y - floor((m_kernel.getHeight())/2);
			float correctedYRangeEnd = y + floor((m_kernel.getHeight())/2);
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
					colorToAdd = (colorToAdd * m_kernel.getData(i - correctedXRangeStart,j - correctedYRangeStart));
					finalColor = finalColor + colorToAdd;
				}
			}
			buffer->setPixel(x,y,finalColor);
			}
			correctedY++;
		}
		correctedX++;

	}
}
Kernel TBlur::getKernel()
{
	return m_kernel;
}
std::string TBlur::getName() 
{
	return "Blur";
}