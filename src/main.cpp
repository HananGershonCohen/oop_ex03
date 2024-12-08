#include <iostream> 
#include "Pixel.h"
#include "Image.h"
#include "ImageDataStructure.h"

using std::cout;
using std::endl;

const unsigned char BLACK = (unsigned char)219;
const unsigned char GRAY = (unsigned char)176;
const unsigned char WHITE = (unsigned char)32;

int main()
{
	Image image1(10,10,BLACK);
	cout << "image1" << endl;
	cout << image1 << endl;

	cout << "image1*3" << endl;
	cout << image1*3<< endl;

	return 0;
}