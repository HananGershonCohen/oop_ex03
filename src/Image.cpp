#include "Image.h"

Image::Image(int height, int width):m_Image(height ,width) {}

Image::Image(int height, int width, Pixel pixel) :m_Image(height, width, pixel) {}

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

std::ostream& operator<<(std::ostream& os, const Image& image)
{
	return os << image.m_Image;
}
