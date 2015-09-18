//
//  Kernel.cpp
//
//  Created by Christian Wohlwend.
//

#include "Kernel.h"
#include <cmath>
#include <iostream>
#include <vector>

//using std::vector;
using std::cout;
using std::endl;

Kernel::Kernel()
{
	//std::vector< std::vector<float> > kernel;
}
void Kernel::initSize(int sizeInput)
{
	size = sizeInput;
	kernel.resize(size);
	for (int i = 0; i<size; i++)
	{
		kernel[i].resize(size);
		std::vector<float> tempRow;
		for (int j = 0; j<size; j++)
		{
			tempRow.push_back(0);
		}
		kernel.push_back(tempRow);
	}
}
int Kernel::getWidth()
{
	return size;
}
int Kernel::getHeight()
{
	return size;
}
void Kernel::setValue(int x, int y, float v)
{
	kernel[x][y] = v;
}
void Kernel::setDiagNWSE(float v)
{

	for (int i = 0; i<size; i++)
	{
		kernel[i][i] = v;
	}
}
void Kernel::setDiagNESW(float v)
{

	for (int i = 0; i<size; i++)
	{
		kernel[i][(-i+size)-1] = v;
	}
}
void Kernel::setDiagNS(float v)
{

	for (int i = 0; i<size; i++)
	{
		kernel[i][ceil(size/2)] = v;
	}
}
void Kernel::setDiagEW(float v)
{

	for (int i = 0; i<size; i++)
	{
		kernel[floor(size/2)][i] = v;
	}
}
void Kernel::buildDiamond(float v)
{
	int startingPoint = ceil(size/2);
	int amountOnLayer = 1;
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < amountOnLayer; y++)
		{
			kernel[x][startingPoint]= v;
			startingPoint++;
		}
		if (x >= (size/2))
		{
			amountOnLayer = amountOnLayer - 2;
		}
		else
		{
			amountOnLayer = amountOnLayer + 2;
		}
		startingPoint = ceil(size/2);
		startingPoint = startingPoint - ceil(amountOnLayer/2);
	}
}
float Kernel::totalElementsInDiamond()
{
	int startingPoint = ceil(size/2);
	float amountOnLayer = 1;
	float totalThings = 0;
	for (int x = 0; x < size; x++)
	{
		totalThings = totalThings + amountOnLayer;
		for (int y = 0; y < amountOnLayer; y++)
		{
			startingPoint++;
		}
		if (x >= (size/2))
		{
			amountOnLayer = amountOnLayer - 2;
		}
		else
		{
			amountOnLayer = amountOnLayer + 2;
		}
		startingPoint = ceil(size/2);
		startingPoint = startingPoint - ceil(amountOnLayer/2);
	}
	return totalThings;
}
void Kernel::replaceZeros(float v)
{
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
		{
			if (kernel[i][j] == 0)
			{
				kernel[i][j] = v;
			}
		}
	}
}
void Kernel::setCenterValue(float v)
{
	float midValue = ceil(size/2);
	kernel[midValue][midValue] = v;

}
float Kernel::getCenter()
{
	float midValue = ceil(size/2);
	return midValue;
}
float Kernel::getData(int x, int y)
{
	return kernel[x][y];
}
void Kernel::printKernel()
{
	for(int i= 0; i<size; i++)
	{
		for (int j =0; j<size; j++)
		{
			cout<<kernel[i][j];
			cout<<"  ";
		}
		cout<<""<<endl;
	}
}