#include "ImageDataStructure.h"
const unsigned char BLACK = (unsigned char)219;
const unsigned char WHITE = (unsigned char)32;

ImageDataStructure::ImageDataStructure(int height, int width ,Pixel pixel)
	:m_height(height) , m_width(width)
{
	// Dynamic allocation of a two-dimensional array
	m_ImageDS = allocImage(m_height, m_width);

	// Initializing the pixels
	for (int i=0;i< height;i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			m_ImageDS[i][j] = pixel;
		}
	}
}

ImageDataStructure::ImageDataStructure(const ImageDataStructure& other) // coyp c-tor
	: m_height(other.m_height), m_width(other.m_width)
{
	m_ImageDS = allocImage(m_height, m_width);
	this->copy(other);
}

ImageDataStructure::ImageDataStructure(int height, int width, Pixel**& pixel)
	: m_height{ height }, m_width{ width }, m_ImageDS{ pixel }
{
}

void ImageDataStructure::copy(const ImageDataStructure& other)
{
	if (!other.m_ImageDS)
		return; // nullptr

	m_height = other.m_height;
	m_width = other.m_width;

	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			m_ImageDS[i][j] = other.m_ImageDS[i][j];
		}
	}
} 

Pixel** ImageDataStructure::allocImage(int height, int width)const
{
	if (height <= 0 || width <= 0)
		return nullptr; // invalid size

	Pixel** image = new Pixel * [height];
	for (int i = 0; i < height; i++)
	{
		image[i] = new Pixel[width];
	}

	return image;
}

void ImageDataStructure::deleteImage()
{
	if (m_ImageDS)
	{
		for (int i = 0; i < m_height; i++)
		{
			delete[] m_ImageDS[i];
		}
		if (m_width)
			delete[] m_ImageDS;
		m_ImageDS = nullptr;
	}
}

ImageDataStructure::~ImageDataStructure()
{
	this->deleteImage();
}

int ImageDataStructure::GetHeight()const
{
	return m_height;
}

int ImageDataStructure::GetWidth()const
{
	return m_width;
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

void ImageDataStructure::operator=(const ImageDataStructure& other)
{

	if (this == &other)
		return; 

	if (!other.m_ImageDS)
		return; // nullptr

	this->deleteImage();
	this->m_ImageDS = allocImage(other.m_height, other.m_width);// the members height, width update in "copy" function.
	this->copy(other);
}

Pixel& ImageDataStructure::operator()(unsigned int height, unsigned int width)
{
	if (!m_ImageDS)
		throw std::runtime_error("Image data structure is not initialized");

	if (height >= (unsigned int)m_height || width >= (unsigned int)m_width)
		throw std::out_of_range("Pixel index out of range");

	return m_ImageDS[height][width];
}

const Pixel& ImageDataStructure::operator()(unsigned int height, unsigned int width) const
{
	return const_cast<ImageDataStructure*>(this)->operator()(height, width);

}

ImageDataStructure ImageDataStructure::operator+(const ImageDataStructure& other) const
{
	if (!m_ImageDS || !other.m_ImageDS)
		return ImageDataStructure(0, 0, Pixel()); // nullptr

	int newRow = (m_height > other.m_height) ? m_height : other.m_height;// max();
	int newCol = m_width + other.m_width;
	Pixel** newMatrix = allocImage(newRow, newCol);

	for (int i = 0; i < newRow; i++)
	{

		for (int j = 0; j < newCol; j++)
		{
			if (m_width > j && m_height > i)
				newMatrix[i][j] = m_ImageDS[i][j];

			else if (j >= m_width && j - m_width < other.m_width && i < other.m_height)
				newMatrix[i][j] = other.m_ImageDS[i][j - m_width];
			else
				newMatrix[i][j] = Pixel();
		}
	}
	return ImageDataStructure(newRow, newCol, newMatrix);
}

void ImageDataStructure::operator~()
{
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			if (m_ImageDS[i][j] == BLACK)
				m_ImageDS[i][j] = WHITE;
			else if (m_ImageDS[i][j] == WHITE)
				m_ImageDS[i][j] = BLACK;
		}
	}
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
