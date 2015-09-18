//
//  Threshold.cpp
//  Copyright (c) 2015 Christian Wohlwend.

#include "Filter.h" 
#include "Threshold.h"
#include "PhotoShop.h"
#include "ColorData.h"
#include "PixelBuffer.h"
#include <iostream>
#include <cmath>
using std::cout;

Threshold::Threshold() 
{

}
void Threshold::applyFilter(PixelBuffer* buffer, float threshold_amount)
{
    cout<<"threshold";
	for (int x = 0; x < buffer->getWidth(); x ++)
    {
        for (int y = 0; y < buffer->getHeight(); y++)
        {
            ColorData currentColor = buffer->getPixel(x,y);
            ColorData newColor = ColorData(0,0,0);
            float redChannel = currentColor.getRed();
            float greenChannel = currentColor.getGreen();
            float blueChannel = currentColor.getBlue();
            if (threshold_amount >= redChannel)
            {
                newColor.setRed(0.0);
            }
            else
            {
                newColor.setRed(1.0);
            }
            if (threshold_amount >= greenChannel)
            {
                newColor.setGreen(0.0);
            }
            else
            {
                newColor.setGreen(1.0);
            }
            if(threshold_amount >= blueChannel)
            {
                newColor.setBlue(0.0);
            }
            else
            {
                newColor.setBlue(1.0);
            }
            buffer->setPixel(x,y,newColor);
        }
    }
}

std::string Threshold::getName() 
{
	return "Threshold";
}