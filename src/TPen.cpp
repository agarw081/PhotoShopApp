//
//  TPen.cpp
//  Student Support
//
//  Created by Seth Johnson on 2/6/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//


#include "TPen.h"
#include "MConstant.h"

TPen::TPen() 
{
	m_mask = new MConstant(1.0, 1.0);
}

std::string TPen::getName() 
{
	return "Pen";
}