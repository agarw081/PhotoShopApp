//
//  ColorData.cpp
//
//  Created by CSCI3081W Guru on 1/15/15.
//  Copyright (c) 2015 CSCI3081W Guru. All rights reserved.
//

#include "ColorData.h"


ColorData::ColorData() : m_red(1), m_green(1), m_blue(1), m_alpha(1)
{
	
}
ColorData::ColorData(float r, float g, float b ) : m_red(r), m_green(g), m_blue(b), m_alpha(1)
{
	
}
ColorData::ColorData(float r, float g, float b, float a)
: m_red(r), m_green(g), m_blue(b), m_alpha(a) 
{
	
}

void ColorData::setRed(float r)
{
	m_red = r;
}

void ColorData::setGreen(float g)
{
	m_green = g;
}

void ColorData::setBlue(float b)
{
	m_blue = b;
}

void ColorData::setAlpha(float a)
{
	m_alpha = a;
}


float ColorData::getRed() const
{
	return m_red;
}

float ColorData::getGreen() const
{
	return m_green;
}

float ColorData::getBlue() const
{
	return m_blue;
}

float ColorData::getAlpha() const
{
	return m_alpha;
}

ColorData ColorData::clampedColor() const
{
	ColorData::component clampedRed = ColorData::clampValue(this->getRed(), 0.f, 1.f);
	ColorData::component clampedGreen = ColorData::clampValue(this->getGreen(), 0.f, 1.f);
	ColorData::component clampedBlue = ColorData::clampValue(this->getBlue(), 0.f, 1.f);
	ColorData::component clampedAlpha = ColorData::clampValue(this->getAlpha(), 0.f, 1.f);
	
	return ColorData(clampedRed, clampedGreen, clampedBlue, clampedAlpha);
}

// Apply component-wise arithmatic operations
ColorData operator* (const ColorData& a, float f)
{
	return ColorData(a.m_red*f, a.m_green*f, a.m_blue*f, a.m_alpha*f);
}
ColorData operator+ (const ColorData& a, const ColorData& b)
{
	return ColorData(a.m_red + b.m_red, a.m_green + b.m_green, a.m_blue + b.m_blue, a.m_alpha + b.m_alpha);
}

ColorData operator- (const ColorData& a, const ColorData& b)
{
	return ColorData(a.m_red - b.m_red, a.m_green - b.m_green, a.m_blue - b.m_blue, a.m_alpha - b.m_alpha);
}

float ColorData::getLuminance() const
{
	return 0.2126*m_red + 0.7152*m_green + 0.0722*m_blue;
}
