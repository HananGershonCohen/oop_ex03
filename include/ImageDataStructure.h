#pragma once
#include "Pixel.h"

class ImageDataStructure
{
public:
	ImageDataStructure(int , int, Pixel);
	Pixel** getImage() const;
;
private:
	Pixel** m_Image;
	int m_width;
	int m_height;
};
