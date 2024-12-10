﻿#include "Image.h"

Image::Image(int height, int width):m_Image(height ,width) {}

Image::Image(int height, int width, Pixel pixel) :m_Image(height, width, pixel) {}

Image::Image(const ImageDataStructure& imageDS)
	:m_Image{ imageDS } {}

Image::Image(const Image& other) :m_Image(other.m_Image) {}

int Image::GetHeight()const
{
	return m_Image.GetHeight();
}

int Image::GetWidth()const
{
	return m_Image.GetWidth();
}

void Image::operator~()
{
	 ~m_Image;
}

Pixel& Image::operator()(unsigned int height, unsigned int width)
{ 
	return m_Image(height, width);
}

const Pixel& Image::operator()(unsigned int height, unsigned int width) const
{
	return m_Image(height, width);
}

bool Image::operator==(const Image& other) const
{
	return (m_Image == other.m_Image); 
}

bool  Image::operator!=(const Image& other)const
{
	return !(*this == other);
}

void Image::operator=(const Image& other)
{
	this->m_Image = other.m_Image;
}


// Remember to change the function to be more beautiful.
Image Image::operator+(const Image& other) const
{
	Image temp;

	temp.m_Image = m_Image + other.m_Image;

	return temp;

}

void Image::operator+=(const Image& other)
{
	*this = *this + other;
}

Image Image::operator*(unsigned int n) const
{
	if (n == 0)
		return Image();
	Image temp(m_Image.GetHeight(), m_Image.GetWidth() * n); // éöéøú úîåðä áâåãì îúàéí		
	for (int i = 0; i < n; i++)
		temp += *this;

	return temp;
}

void Image::operator*=(unsigned int n)
{
	if (n == 0)
	{
		*this = Image();
		return;
	}
	*this = n * *this;
}

Image Image::operator|(const Image& other) const
{
	//i need to check if is nullptr

	/*Image temp;
	temp.m_Image = m_Image | other.m_Image;
	return temp;*/
	return Image(m_Image | other.m_Image);
}

void Image::operator|=(const Image& other)
{
	*this = *this | other;
}

Image Image::operator&(const Image& other) const
{
	return Image(m_Image & other.m_Image);
}

void Image::operator&=(const Image& other)
{
	*this = *this & other;
}

Image operator*(unsigned int n, const Image& image)
{
	return image * n;
}


std::ostream& operator<<(std::ostream& os, const Image& image)
{
	return os << image.m_Image;
}
