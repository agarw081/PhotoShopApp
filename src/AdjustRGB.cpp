//
//  AdjustRGB.cpp
//  Copyright (c) 2015 Christian Wohlwend.

#include "Filter.h" 
#include "AdjustRGB.h"
#include "PhotoShop.h"
#include "ColorData.h"
#include "PixelBuffer.h"
#include <iostream>
using std::cout;

AdjustRGB::AdjustRGB() 
{

}
void AdjustRGB::applyFilter(PixelBuffer* buffer, float channelRed, float channelGreen, float channelBlue)
{
    cout<<"AdjustRGB";
	for (int x = 0; x < buffer->getWidth(); x ++)
    {
        for (int y = 0; y < buffer->getHeight(); y++)
        {
            ColorData currentColor = buffer->getPixel(x,y);
            ColorData newColor = ColorData(0,0,0);
            float redChannel = currentColor.getRed();
            float greenChannel = currentColor.getGreen();
            float blueChannel = currentColor.getBlue();
            newColor.setRed(redChannel * channelRed);
            newColor.setGreen(greenChannel * channelGreen);
            newColor.setBlue(blueChannel * channelBlue);
            buffer->setPixel(x,y,newColor);
        }
    }
}

std::string AdjustRGB::getName() 
{
	return "AdjustRGB";
}