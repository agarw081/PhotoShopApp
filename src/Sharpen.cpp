//
//  Sharpen.cpp
//  Copyright (c) 2015 Christian Wohlwend.

#include "Filter.h" 
#include "Sharpen.h"
#include "PhotoShop.h"
#include "ColorData.h"
#include "PixelBuffer.h"
#include "Kernel.h"
#include <iostream>
using std::cout;
using std::endl;

Sharpen::Sharpen() 
{

}
void Sharpen::buildKernelAndApply(PixelBuffer* buffer, float sharpenAmount)
{
    Kernel m_kernel;
    cout<<"Starting kernel init"<<endl;
    m_kernel.initSize(3);
    cout<<"kennel init at size 3"<<endl;
    m_kernel.setCenterValue(sharpenAmount);
    cout<<"Set center value to 8"<<endl;
    m_kernel.replaceZeros(-((sharpenAmount-1)/8));
    cout<<"replaced Zeros"<<endl;
    m_kernel.printKernel();
    cout<<"kernel successfully built, onto applying filter"<<endl;
    Filter::applyFilter(buffer, m_kernel);
}

std::string Sharpen::getName() 
{
	return "Sharpen";
}
