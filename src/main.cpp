#include <iostream> 
#include "Pixel.h"
#include "Image.h"
#include "ImageDataStructure.h"

using std::cout;
using std::endl;

const unsigned char BLACK = (unsigned char)219;
const unsigned char GRAY = (unsigned char)176;

int main()
{
	//Pixel p1(219);
	//Pixel p2;
	//Pixel p3;
	//cout << endl << "p1 is: " << p1;
	//cout << endl << "p2 is: " << p2;

	/*if (p1 == p2 == p3)
		cout << "equal";*/

	// p1 &= p2;
	//cout << endl << "p1 is: " << p1;
	//cout << endl << "p2 is: " << p2;
	Image image1;
	Image image2(20, 10, BLACK);
	Image image3 = image2;
	//ImageDataStructure image(10, 10, BLACK);

	cout << endl;

	cout << "image1 " << endl;
	cout << image1 << endl;
	cout << " image2" << endl;
	cout << image2 << endl;
	cout << "image3 " << endl;
	cout << image3 << endl;

	//if (image1 == image2)
	//	cout << "equal"; 
	//cout << "not";
	// cout << image;


	return 0;
}