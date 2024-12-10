#pragma once
#include <iosfwd>

class Pixel
{
public:
	Pixel(unsigned char pixel = ' ');
	unsigned char getColor() const;
	bool operator==(const Pixel&)const;
	Pixel operator|(const Pixel&)const;
	Pixel operator&(const Pixel&)const;
	Pixel& operator=(const Pixel&);

private:
	unsigned char m_color;
};
// Global Function.
std::ostream& operator<< (std::ostream&, const Pixel&); 
bool operator!=(const Pixel&, const Pixel&);
void operator|=(Pixel&, const Pixel&);
void operator&=(Pixel& ,const Pixel&);