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
	Image(const ImageDataStructure& imageDS); // c-tor 4 (Tzvi)
	Image(const Image&); // copy c-tor
	int GetHeight() const;
	int GetWidth() const;
	Image operator~();
	Pixel& operator()(unsigned int, unsigned int);
	const Pixel& operator()(unsigned int, unsigned int) const;
	bool operator==(const Image&)const;
	Image& operator=(const Image&) = default;
	Image operator+(const Image& other) const;
	Image operator*(unsigned int n)const;
	friend Image operator*(unsigned int n, const Image& image);
	void operator *=(unsigned int n);
	Image operator|(const Image&) const;
	Image operator&(const Image&) const;
	friend std::ostream& operator<<(std::ostream&, const Image&);

private:
	ImageDataStructure m_Image;
};

bool operator!=(const Image&, const Image&);
Image& operator += (Image& ,const Image&);
Image& operator|=(Image&, const Image&);
Image& operator&=(Image&, const Image&);