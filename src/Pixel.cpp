#include "Pixel.h"
#include <iostream>

Pixel::Pixel(unsigned char pixel) : m_color(pixel){}

unsigned char Pixel::getColor() const
{
	return m_color;
}

bool Pixel::operator==(const Pixel& other) const
{
	return (this->m_color == other.m_color);
}

bool operator!=(const Pixel& left, const Pixel& right)
{
	return !(left == right);
}

Pixel Pixel::operator|(const Pixel& other) const
{
	return (Pixel(m_color >= other.m_color ? m_color : other.m_color));
}

void operator|=(Pixel& left, const Pixel& right)
{
	left = left | right;
}

Pixel Pixel::operator&(const Pixel& other) const
{
	return (Pixel(this->m_color <= other.m_color ? m_color : other.m_color));
}

void operator&=(Pixel& left,const Pixel& right)
{
	left = left & right;
}

Pixel& Pixel::operator=(const Pixel& other)
{
	m_color = other.m_color;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Pixel& pixel)
{
	 return os << pixel.getColor(); 	 // return ostream
}
