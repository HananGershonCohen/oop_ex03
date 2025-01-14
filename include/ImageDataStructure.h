#pragma once
#include <iostream>
#include "Pixel.h"
#include <concepts>

using std::cout;
using std::endl;


class ImageDataStructure
{
public:
	ImageDataStructure(int height=0, int width=0, Pixel pixel=' '); 
	ImageDataStructure(const ImageDataStructure&); // copy c-tor
	ImageDataStructure(int, int, Pixel**& pixel);
	~ImageDataStructure();
	int GetHeight()const;
	int GetWidth()const;
	ImageDataStructure operator~();
	bool operator==(const ImageDataStructure&)const;
	ImageDataStructure& operator=(const ImageDataStructure&);
	Pixel& operator()(unsigned int, unsigned int);
	const Pixel& operator()(unsigned int, unsigned int) const;
	ImageDataStructure operator+(const ImageDataStructure&) const;
	ImageDataStructure operator|(const ImageDataStructure&) const;
	ImageDataStructure operator&(const ImageDataStructure&) const;
	friend std::ostream& operator<<(std::ostream&, const ImageDataStructure&);

private:
	Pixel** m_ImageDS = nullptr;
	int m_width; 
	int m_height;
	void copy(const ImageDataStructure&);
	Pixel** allocImage(int, int) const;

	void deleteImage();
};

