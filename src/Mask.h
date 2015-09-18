//
//  Mask.h
//  Student Support
//
//  Created by Seth Johnson on 2/9/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//
//  Mask is a wrapper for the array of floats representing the shape of
//  a tool. It is pure virtual, because a mask does not inherently have
//  a shape. Shapes are defined implicitly with getIntensity().

#ifndef MASK_H
#define MASK_H

class Mask 
{
public:
	Mask(float radius, float opacity);
	Mask();
	~Mask();
	float const *getFloatArray() const { return m_maskArray; }
	int getWidth() const { return m_width;}
	int getHeight() const {return m_height;}
	float getValue(int x, int y) const;
protected:
	float m_radius;
	float m_opacity;
	int m_height;
	int m_width;
	float *m_maskArray;
	void setValue(int x, int y, float v);
	void generateMask();
	virtual float getIntensity(int x, int y, float radius) = 0;
};

#endif
