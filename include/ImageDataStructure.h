#pragma once
#include "Pixel.h"

class ImageDataStructure
{
public:
	ImageDataStructure(int height=0, int width=0, Pixel pixel=' ');

private:
	Pixel** m_Image;
	int m_width;
	int m_height;
};
