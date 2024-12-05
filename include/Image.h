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
	Image(); // (defult) c-tor 1
	Image(int, int); // c-tor 2
	Image(int , int , Pixel ); // c-tor 3
	Image(const Image&); // copy c-tor
	bool operator==(const Image&)const;
	bool operator!=(const Image&)const;
	friend std::ostream& operator<<(std::ostream&, const Image&);


private:
	ImageDataStructure m_Image;
};

