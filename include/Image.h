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
	Image() = default; // (defult) c-tor 1
	Image(int, int); // c-tor 2
	Image(int , int , Pixel ); // c-tor 3
	Image(const Image&); // copy c-tor
	int GetHeight() const;
	int GetWidth() const;
	void operator~();
	Pixel& operator()(unsigned int, unsigned int);
	const Pixel& operator()(unsigned int, unsigned int) const;
	bool operator==(const Image&)const;
	bool operator!=(const Image&)const;
	void operator=(const Image&);
	Image operator+(const Image& other) const;
	void operator += (const Image& other);
	friend std::ostream& operator<<(std::ostream&, const Image&);

private:
	ImageDataStructure m_Image;
};

