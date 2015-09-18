//
//  PixelBuffer.h
//
//  Created by CSCI3081W Guru
//  Copyright (c) 2015 CSCI3081W Guru. All rights reserved.
//

#ifndef PIXELBUFFER_H
#define PIXELBUFFER_H

class ColorData;

class PixelBuffer 
{
public:
	// Constructors
	PixelBuffer(int w, int h, ColorData backgroundColor);
	~PixelBuffer();
	// Setters
	void setPixel(int x, int y, const ColorData& newPixel);
	
	// Getters
	ColorData getPixel(int x, int y) const;
	ColorData const * const getData() const;
	int getHeight() const;
	int getWidth() const;
	
	// Member tasks
	void fillPixelBufferWithColor(ColorData initialPixels);
	
	// Static tasks
	static void copyPixelBuffer(PixelBuffer * sourceBuffer, PixelBuffer * destinationBuffer);
	
	ColorData getBackgroundColor();
private:
	// Array of pixel values
	ColorData * m_pixels;
	ColorData * m_backgroundColor;
	// Dimensions
	const int m_width;
	const int m_height;
};

#endif
