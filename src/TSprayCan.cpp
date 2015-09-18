//
//  TSprayCan.cpp
//  Student Support
//
//  Created by Seth Johnson on 2/6/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#include "TSprayCan.h"
#include "MLinear.h"

TSprayCan::TSprayCan() 
{
	m_mask = new MLinear(30, 0.2);
	
}


std::string TSprayCan::getName() 
{
	return "Spray Can";
}