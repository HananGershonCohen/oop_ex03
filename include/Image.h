#pragma once
#include "ImageDataStructure.h"
#include "Pixel.h"
#include <iosfwd>
#include <iostream>
using std::cout;
using std::endl;

class Image
{
public:
	//Image();
	Image(int , int , Pixel );
	ImageDataStructure getImage() const;
	int getWidth() const;
	int getHeight() const;

private:
	ImageDataStructure m_Image;
	int m_width;
	int m_height;
};

std::ostream& operator<<(std::ostream&, const Image&);