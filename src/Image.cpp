#include "Image.h"

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

Image Image::operator~()
{
	return ~m_Image;
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

bool operator!=(const Image& right ,const Image& left)
{
	return !(right == left);
}

// Remember to change the function to be more beautiful.
Image Image::operator+(const Image& other) const
{
	Image temp;
	temp.m_Image = m_Image + other.m_Image;
	return temp;
}

Image& operator+=(Image& right, const Image& left)
{
	return (right = right + left);
}

Image operator*(const Image& image, unsigned int n)
{
	if (n == 0)
		return Image();

	Image temp; 	
	for (unsigned i = 0; i < n; i++)
		temp += image;

	return temp;
}

Image operator*(unsigned int n, const Image& image)
{
	return image * n;
}

Image& operator*=(Image& image, unsigned int n)
{
	return (image = image * n);
}

Image Image::operator|(const Image& other) const
{
	return Image(m_Image | other.m_Image);
}

Image& operator|=(Image& right, const Image& left)
{
	return (right = right | left);
}

Image Image::operator&(const Image& other) const
{
	return Image(m_Image & other.m_Image);
}

Image& operator&=(Image& right, const Image& left)
{
	return (right = right & left);
}


std::ostream& operator<<(std::ostream& os, const Image& image)
{
	return os << image.m_Image;
}
