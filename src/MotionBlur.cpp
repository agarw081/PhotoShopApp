//
//  MotionBlur.cpp
//  Copyright (c) 2015 Christian Wohlwend.

#include "Filter.h" 
#include "MotionBlur.h"
#include "PhotoShop.h"
#include "ColorData.h"
#include "PixelBuffer.h"
#include "Kernel.h"
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

MotionBlur::MotionBlur() 
{

}
void MotionBlur::buildKernelAndApply(PixelBuffer* buffer, float blurAmount, int blurDirection)
{
    blurAmount = ceil(blurAmount);
    if(int(blurAmount) % 2 == 0)
    {
        blurAmount++;
    }
    Kernel m_kernel;
    cout<<"Starting kernel init"<<endl;
    m_kernel.initSize(blurAmount);
    cout<<"kennel init size"<<endl;
    if (blurDirection == 1)
    {
        m_kernel.setDiagNS(1/blurAmount);
    }
    else if (blurDirection == 0)
    {
        m_kernel.setDiagEW(1/blurAmount);
    }
    else if (blurDirection == 2)
    {
        m_kernel.setDiagNESW(1/blurAmount);
    }
    else if (blurDirection == 3)
    {
        m_kernel.setDiagNWSE(1/blurAmount);
    }
    m_kernel.printKernel();
    cout<<"kernel successfully built, onto applying filter"<<endl;
    Filter::applyFilter(buffer, m_kernel);
}

std::string MotionBlur::getName() 
{
	return "Blur";
}
