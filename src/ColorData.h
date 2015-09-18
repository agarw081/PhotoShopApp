//
//  ColorData.h
//
//  Created by CSCI3081W Guru on 1/15/15.
//  Copyright (c) 2015 CSCI3081W Guru. All rights reserved.
//

#ifndef COLORDATA_H
#define COLORDATA_H

class ColorData 
{
public:
	// Specify the type of each color channel as a float
	typedef float component;
	
	// Constructors
	ColorData();
	ColorData(float r, float g, float b );
	ColorData(float r, float g, float b, float a);
	
	// Float Setters
	void setRed(float r);
	void setBlue(float b);
	void setGreen(float g);
	void setAlpha(float a);
	
	// Float Getters
	float getRed() const;
	float getBlue() const;
	float getGreen() const;
	float getAlpha() const;
	float getLuminance() const;
	// Member Tasks
	ColorData clampedColor() const; // Create a new colorData with clamped values
	
	// Arithmatic operators (friends so that non-member functions can access private variables)
	friend ColorData operator* (const ColorData& a, float f);
	friend ColorData operator+ (const ColorData& a, const ColorData& b);
	friend ColorData operator- (const ColorData& a, const ColorData& b);
	
private:
	// General helper function for clamping values between 0 and 1
	static inline float clampValue(float input, float a, float b)
	{return input < a ? a : (input > b ? b : input);}
	
	// Member Variables
	component m_red;
	component m_green;
	component m_blue;
	component m_alpha;
	
};

#endif
