//
//  Saturation.cpp
//  Copyright (c) 2015 Christian Wohlwend.

#include "Filter.h" 
#include "Saturation.h"
#include "PhotoShop.h"
#include "ColorData.h"
#include "PixelBuffer.h"
#include <iostream>
using std::cout;

Saturation::Saturation() 
{

}
void Saturation::applyFilter(PixelBuffer* buffer, float saturation_amount)
{
    cout<<"Saturation";
	for (int x = 0; x < buffer->getWidth(); x ++)
    {
        for (int y = 0; y < buffer->getHeight(); y++)
        {
            ColorData currentColor = buffer->getPixel(x,y);
            float luminence = currentColor.getLuminance();
            ColorData newColor = ColorData(0,0,0);
            float redChannel = currentColor.getRed();
            float greenChannel = currentColor.getGreen();
            float blueChannel = currentColor.getBlue();
            float redDifference = (redChannel - luminence) * saturation_amount;
            float greenDifference = (greenChannel - luminence) * saturation_amount;
            float blueDifference = (blueChannel - luminence) * saturation_amount;
            newColor.setRed(luminence + redDifference);
            newColor.setGreen(luminence + greenDifference);
            newColor.setBlue(luminence + blueDifference);
            buffer->setPixel(x,y,newColor);
        }
    }
}

std::string Saturation::getName() 
{
	return "Saturation";
}