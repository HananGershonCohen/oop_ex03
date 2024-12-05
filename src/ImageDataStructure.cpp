#include "ImageDataStructure.h"


ImageDataStructure::ImageDataStructure(int height, int width ,Pixel pixel):m_height(height) , m_width(width)
{
	// Dynamic allocation of a two-dimensional array
	m_Image = new Pixel*[m_height];
	for (int i = 0; i < m_height; i++)
	{
		m_Image[i] = new Pixel[m_width];
	}

	// Initializing the pixels
	for (int i=0;i< height;i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			m_Image[i][j] = pixel;
		}
	}
}
