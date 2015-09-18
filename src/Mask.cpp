//
//  Mask.cpp
//  Student Support
//
//  Created by Seth Johnson on 2/9/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#include "Mask.h"
#include <cmath>
#include <iostream>

using std::fill;

Mask::Mask() 
{
	m_maskArray = NULL;
}

Mask::Mask(float radius, float opacity) : m_opacity(opacity), m_radius(radius), m_height(ceil(radius)*2+1),m_width(ceil(radius)*2+1)  
{
	m_maskArray = new float[m_width*m_height];
	fill(m_maskArray, m_maskArray+m_width*m_height, 1.f);
}

Mask::~Mask() 
{
	delete [] m_maskArray;
}

float Mask::getValue(int x, int y) const 
{
	if (m_maskArray == NULL || x < 0 || x > m_width || y < 0 || y > m_width) {
		return 0.f;
	}
	else 
	{
		return m_maskArray[y*m_width + x];
	}
	
}

void Mask::setValue(int x, int y, float v) 
{
	if (m_maskArray == NULL || x < 0 || x > m_width || y < 0 || y > m_width)
	{
		return;
	}
	else 
	{
		m_maskArray[y*m_width + x] = v;
	}
}

void Mask::generateMask() {
	for (int j = 0; j < getHeight(); j++) 
	{
		for (int i = 0; i < getWidth(); i++) 
		{
			int x = i-getWidth()/2;
			int y = j-getHeight()/2;
			float intensity = m_opacity*getIntensity(x,y,m_radius);
			setValue(i, j, intensity);
		}
	}
}
