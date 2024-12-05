#include "ImageDataStructure.h"


ImageDataStructure::ImageDataStructure(int height, int width ,Pixel pixel)
	:m_height(height) , m_width(width)
{
	// Dynamic allocation of a two-dimensional array
	m_ImageDS = new Pixel*[m_height];
	for (int i = 0; i < m_height; i++)
	{
		m_ImageDS[i] = new Pixel[m_width];
	}

	// Initializing the pixels
	for (int i=0;i< height;i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			m_ImageDS[i][j] = pixel;
		}
	}
}

ImageDataStructure::ImageDataStructure(const ImageDataStructure& other)
	: m_height(other.m_height), m_width(other.m_width)
{
	m_ImageDS = new Pixel * [m_height];
	for (int i = 0; i < m_height; i++)
	{
		m_ImageDS[i] = new Pixel[m_width];
	}

	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			m_ImageDS[i][j] = other.m_ImageDS[i][j];
		}
	}
}

ImageDataStructure::~ImageDataStructure()
{
	if (m_ImageDS)
	{ 
		for (int i = 0; i < m_height; i++) 
		{
			delete[] m_ImageDS[i];  
		}
		delete[] m_ImageDS; 
		m_ImageDS = nullptr; 
	}
}


bool ImageDataStructure::operator==(const ImageDataStructure& other) const
{
	// Quick check for self-comparison
	if (this == &other)
		return true;

	if (!this->m_ImageDS || !other.m_ImageDS) // type: Pixel**
		return false;

	if (this->m_height != other.m_height || this->m_width != other.m_width) // type: int
		return false;

	for (int row = 0; row < m_height; row++)
		for (int col = 0; col < m_width; col++)
		{
			if (m_ImageDS[row][col] != other.m_ImageDS[row][col]) // type: Pixel
				return false;
		}
	return true;
}

bool ImageDataStructure::operator!=(const ImageDataStructure& other) const
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const ImageDataStructure& image)
{
	if (!image.m_ImageDS)
		return os;

	for (int i = 0; i < image.m_height; i++)
	{
		for (int j = 0; j < image.m_width; j++)
		{
			os << image.m_ImageDS[i][j];

		}
		os << endl;
	}

	return os;
}
