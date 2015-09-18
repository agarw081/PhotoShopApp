//
//  Kernel.h
//
//  Created by Christian Wohlwend.

#ifndef KERNEL_H
#define KERNEL_H
#include <vector>

class Kernel 
{
public:
	Kernel();
	void initSize(int size);
	int getWidth();
	int getHeight();
	float getValue(int x, int y);
	
	void setValue(int x, int y, float v);
	void replaceZeros(float v);
	void setCenterValue(float v);
	float getCenter();
	float getData(int x, int y);
	void setDiagNWSE(float v);
	void setDiagNESW(float v);
	void setDiagNS(float v);
	void setDiagEW(float v);
	void buildDiamond(float v);
	float totalElementsInDiamond();
	void printKernel();
protected:
	int size;
	std::vector< std::vector<float> > kernel;
};

#endif