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
	Pixel pix1, pix2(GRAY), pix3(BLACK);

	cout << "pix1" << endl;
	cout << pix1 << endl;
	cout << "pix2" << endl;
	cout << pix2 << endl;
	cout << "pix3" << endl;
	cout << pix3 << endl;

	cout << "operator== AND operator!=" << endl;
	if (pix1 == pix1)
		cout << "GOOD" << endl;
	else cout << "NO GOOD" << endl;
	if (pix1 != pix2)
		cout << "GOOD" << endl;
	else cout << "NO GOOD" << endl;


	cout << "pix1=pix2" << endl;
	pix1 = pix2;
	cout << pix1 << endl;
	cout << "pix1=pix2=pix3" << endl;
	pix1 = pix2 = pix3;
	cout << pix1 << endl;

	Image image1(10,10,GRAY);
	Image image2(5, 5, WHITE);
	Image image3(15, 15, BLACK);
	cout << "image1" << endl;
	cout << image1 << endl;
	cout << "image2" << endl;
	cout << image2 << endl;
	cout << "image3" << endl;
	cout << image3 << endl;
	
	cout << "~image1" << endl;
	cout << ~image1 << endl;
	cout << "~image2" << endl;
	cout << ~image2 << endl;
	cout << "~image3" << endl;
	cout << ~image3 << endl;

	cout << "image1" << endl;
	cout << image1 << endl;
	cout << "image2" << endl;
	cout << image2 << endl;
	cout << "image3" << endl;
	cout << image3 << endl;

	cout << "image1=image2" << endl;
	image1 = image2;
	cout << image1 << endl;
	cout << "image1=image2=image3" << endl;
	image1 = image2 = image3;
	cout << image1 << endl;

	cout << "image1*0" << endl;
	cout << image1 * 0 << endl;
	cout << "image1*1" << endl;
	cout << image1*1<< endl;
	cout << "image1*2" << endl;
	cout << image1 * 2 << endl;
	cout << "image1*3" << endl;
	cout << image1 * 3 << endl;

	return 0;
}