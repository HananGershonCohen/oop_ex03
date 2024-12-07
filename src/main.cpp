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
	//Image image1(10, 20, BLACK);
	//Image image2;
	//image1 = image2;
	////Image image3 = image2;
	////ImageDataStructure image(10, 10, BLACK);

	//cout << endl;


	////cout << "image3 " << endl;
	////cout << image3 << endl;


	//if (image1 == image2)
	//	cout << "equal"; 
	//cout << "not";
	// cout << image;


	ImageDataStructure image1(10, 10, BLACK);
	ImageDataStructure image2(10, 10, GRAY);
	//ImageDataStructure image3;

	//image3 = image2;
	//cout << "image1 " << endl;
	cout << image1 + image2 << endl;

	image1 += image2;

	cout << "image1 after " << endl;
	cout << image1 << endl;
	cout << " image2" << endl;
	cout << image2 << endl;
//	cout << "image3 " << endl;
	//cout << image3 << endl;


	return 0;
}