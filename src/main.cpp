#include <iostream> 
#include "Pixel.h"

using std::cout;
using std::endl;


int main()
{
	Pixel p1(219);
	Pixel p2;
	cout << endl << "p1 is: " << p1;
	cout << endl << "p2 is: " << p2;

	 p1 &= p2;
	cout << endl << "p1 is: " << p1;
	cout << endl << "p2 is: " << p2;

	 
	return 0;
}