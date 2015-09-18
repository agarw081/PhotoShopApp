//
//  Blur.cpp
//  Copyright (c) 2015 Christian Wohlwend.

#include "Filter.h" 
#include "Blur.h"
#include "PhotoShop.h"
#include "ColorData.h"
#include "PixelBuffer.h"
#include "Kernel.h"
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

Blur::Blur() 
{

}
void Blur::buildKernelAndApply(PixelBuffer* buffer, float blurAmount)
{
    blurAmount = ceil(blurAmount);
    if(int(blurAmount) % 2 == 0)
    {
        blurAmount++;
    }
    Kernel m_kernel;
    cout<<"Starting kernel init"<<endl;
    m_kernel.initSize(blurAmount);
    float AmountOfDiamondElem = m_kernel.totalElementsInDiamond();
    cout<<"kennel init size"<<endl;

    m_kernel.buildDiamond(1/AmountOfDiamondElem);
    cout<<"amount of elem in diamond = ";
    cout<<AmountOfDiamondElem<<endl;
    cout<<"Value of diamond elem = ";
    cout<<(1/AmountOfDiamondElem)<<endl;
    m_kernel.printKernel();
    cout<<"kernel successfully built, onto applying filter"<<endl;
    Filter::applyFilter(buffer, m_kernel);
}

std::string Blur::getName() 
{
	return "Blur";
}