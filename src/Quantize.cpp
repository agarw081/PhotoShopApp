//
//  Quantize.cpp
//  Copyright (c) 2015 Christian Wohlwend.

#include "Filter.h" 
#include "Quantize.h"
#include "PhotoShop.h"
#include "ColorData.h"
#include "PixelBuffer.h"
#include <iostream>
#include <cmath>
#include <vector>
using std::cout;
using std::endl;

Quantize::Quantize() 
{

}
void Quantize::applyFilter(PixelBuffer* buffer, float binNum)
{
    cout<<"Quantize";
    //Construct list of bin numbers
    std::vector<float> bins;
    float j = 0;
    for (int x = 0; x <= binNum; x++)
    {
        bins.push_back (j);
        j = j + (1/binNum);
    }
    
	for (int x = 0; x < buffer->getWidth(); x ++)
    {
        for (int y = 0; y < buffer->getHeight(); y++)
        {
            ColorData currentColor = buffer->getPixel(x,y);
            ColorData newColor = ColorData(0,0,0);
            float redChannel = currentColor.getRed();
            float greenChannel = currentColor.getGreen();
            float blueChannel = currentColor.getBlue();
            float redMax = 999;
            float greenMax = 999;
            float blueMax = 999;
            for (int x = 0; x <= binNum; x++)
            {
                float redChannelDifference = std::abs(redChannel - bins[x]);
                float greenChannelDifference = std::abs(greenChannel - bins[x]);
                float blueChannelDifference = std::abs(blueChannel - bins[x]);
                if (redChannelDifference <= redMax)
                {
                    newColor.setRed(bins[x]);
                    redMax = redChannelDifference;
                }
                if (greenChannelDifference <= greenMax)
                {
                    newColor.setGreen(bins[x]);
                    greenMax = greenChannelDifference;
                }
                if (blueChannelDifference <= blueMax)
                {
                    newColor.setBlue(bins[x]);
                    blueMax = blueChannelDifference;
                }
            }
            buffer->setPixel(x,y,newColor);
        }
    }
}

std::string Quantize::getName() 
{
	return "Quantize";
}