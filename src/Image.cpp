#include "Image.h"

Image::Image(int height, int width, Pixel pixel) 
	:m_Image(height, width, pixel),m_height(height), m_width(width)
{}

ImageDataStructure Image::getImage() const
{
	return m_Image;
}


int Image::getWidth() const
{
	return m_width;
}

int Image::getHeight() const
{
	return m_height;
}


//Image::~Image()
//{
//}
//
std::ostream& operator<<(std::ostream& os, const Image& image)
{
	// check if Image NOT NULLPTR
	/*if (image.getImage() == nullptr)
		return os;*/
	for (int i = 0; i < image.getHeight(); i++)
	{
		for (int j = 0; j < image.getWidth(); j++)
		{
			os << image.getImage().getImage()[i][j];
		}
		os << endl;
	}

	return os;
}
