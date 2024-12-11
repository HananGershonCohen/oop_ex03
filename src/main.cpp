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

	Pixel p1(BLACK);
	Pixel p2(GRAY);
	Pixel p3(WHITE);


	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << p3 << std::endl;

	if (p1 == p1) { //  שוויון
		cout << "is equalS \n";
	}
	if (p1 != p2) { // אי שוויון
		cout << "is not equals \n";
	}

	// | בדיקה אופרטור 
	Pixel p4 = p3 | p2;
	//cout << "Operator | " << 
	cout << p4;
	cout << endl;


	// |= בדיקה אופרטור 
	p2 |= p1; // p2 השתנה ללבן
	cout << p2;
	cout << endl;

	// & בדיקה אופרטור 
	Pixel p5 = p4 & p1; // שחור עם אפור
	cout << p5;
	cout << endl;

	// &= בדיקה אופרטור 
	p5 &= p3; // השמה לבן לאפור
	cout << p5;
	cout << endl;
	cout << "Pixel test pinish" << endl;
	//=========================================
	   //============= טסטים של Image ============
	cout << endl;
	cout << "=============== test of Image =======================\n";
	cout << "The first image is white: \n";
	Image image1(6, 15); // תמונה לבנה בדיפולט
	cout << image1;

	cout << "The second image is: \n";
	Image image2(4, 20, p1); // תמונה שחורה
	cout << image2;
	cout << endl;

	cout << "The three image is: \n";
	Pixel p6(GRAY);
	Image image3(6, 18, p6);
	cout << image3;
	cout << endl;
    cout << "======= Copy constructor ========\n";
    Image copy_image1 = image2; // מופעל בנאי העקתה בהשמה
    cout << "The first image copy constructor is: \n";
    cout << copy_image1;
    cout << endl;

    Image copy_image2(image3); // מופעל בנאי העקתה
    cout << "The second image copy constructor is: \n";
    cout << copy_image2;
    cout << endl;

    if (copy_image1 == image2) {
        cout << "the Images are aquls \n";
    }
    if (copy_image2 != image2) {
        cout << "the Images are not aquls \n";
    }


    Image image7(1, 3, Pixel(' '));
    image7 = copy_image2;
    cout << image7;
    cout << endl;

    //======= אופרטור + חיבור תמונות =========
    Image image8(10, 8, Pixel(GRAY));
    Image image9(5, 15, Pixel(BLACK));

    // תמונה שמאלית נמוכה יותר
    Image image10, image11;
    image10 = image9 + image8;
    cout << "Image 10\n";
    cout << image10;
    cout << endl;

    // תמונה שמאלית גבוה יותר
    image11 = image8 + image9;
    cout << "Image 11\n";
    cout << image11;
    cout << endl;

    // מימוש אופרטור +=
    cout << "Image 10 += image11\n";
    image10 += image11 += image8;
    cout << image10;
    cout << endl;
    cout << endl;


    // מימוש אופרטור |
    Image image12(5, 15, Pixel(GRAY));
    Image image13(10, 7, Pixel(BLACK));
    cout << "Image 12\n";
    cout << image12 << endl;
    cout << "Image 13\n";
    cout << image13 << endl;
    Image image14 = image12 | image13;
    cout << "Image12 | image13\n";
    cout << image14;
    cout << endl;
    image14 = image13 | image12;
    cout << "Image13 | image12\n";
    cout << image14;
    cout << endl << endl;

    // מימוש אופרטור |=
    image14 |= image10;
    cout << "image14 ofter |= with image10: \n";
    cout << image14;
    cout << endl;


    // מימוש אופרטור &
    Image image15 = image12 & image13;
    cout << "image12 & image13: \n";
    cout << image15;
    cout << endl;


    // מימוש אופרטור &= 
    image14 = image12 &= image13;
    cout << "image14 ofter &= with image12 &= image13: \n";
    cout << image14;
    cout << endl;

    // מימוש אופרטור כפל בסקלאר *
    cout << "image14 * 5 is: \n";
    Image image16 = image14 * 5;
    cout << image16;
    cout << endl;

    //  מימוש אופרטור כפל בסקלאר * כפל ב0
    cout << "image14 * 0 is: \n";
    image16 = image14 * 0;
    cout << image16;
    cout << endl;

    // מימוש אופרטור * כפל משמאל
    cout << "3 * image14 is: \n";
    image16 = 3 * image14; // לשאול את מתן
    cout << image16;
    cout << endl;


    //  מימוש אופרטור כפל בסקלאר עם שינוי האיבייקט =*
    cout << "Change the image16 *= 2 is: \n";
    image16 *= 2;
    cout << image16;
    cout << endl;

    // כפל משמאל
    cout << "Change the 2 *= image16 is: \n";
    2 *= image16;
    cout << image16;
    cout << endl;

    // מימוש אופרטור אונארי ~ הופך שחור ללבן, לבן לשחור, אפור נשאר אפור
    Image image17(8, 12, Pixel(WHITE));
    Image image18(8, 12, Pixel(BLACK));
    Image image19(8, 12, Pixel(GRAY));
    Image image20 = image17 + image18 + image19;

    cout << "image befor operator ~ is: \n";
    cout << image20;
    cout << endl;

    cout << "image after operator ~ is: \n";
    Image image21 = ~(image17 + image18 + image19);
    cout << image21;
    cout << endl;

    // כ מימוש אופרטור () עם רפראנס שניתן לשינוי
    Pixel& p9 = image21(2, 2);
    Pixel p10(WHITE); // ניצור פיקסל לבן 
    cout << p9 << endl;
    p9 &= p10; // עושה השמה לפיקסל הבהיר 
    cout << p9 << endl;
    cout << "The image ofter change with reference is: \n";
    cout << image21;
    cout << endl;

    // מימוש אופרטור () עם רפראנס קבוע שאינו שניתן לשינוי
    const Pixel& p11 = image21(3, 3);
    cout << "The const pixel by reference is: \n";
    cout << p11;
    cout << endl << endl;

    cout << "======= End of the tests, goodbye!!! ======= \n";

    return 0;
	//// TEMP //
	//Pixel pix1, pix2(GRAY), pix3(BLACK);

	//cout << "pix1" << endl;
	//cout << pix1 << endl;
	//cout << "pix2" << endl;
	//cout << pix2 << endl;
	//cout << "pix3" << endl;
	//cout << pix3 << endl;

	//cout << "operator== AND operator!=" << endl;
	//if (pix1 == pix1)
	//	cout << "GOOD" << endl;
	//else cout << "NO GOOD" << endl;
	//if (pix1 != pix2)
	//	cout << "GOOD" << endl;
	//else cout << "NO GOOD" << endl;


	//cout << "pix1=pix2" << endl;
	//pix1 = pix2;
	//cout << pix1 << endl;
	//cout << "pix1=pix2=pix3" << endl;
	//pix1 = pix2 = pix3;
	//cout << pix1 << endl;

	//Image image1(10,10,GRAY);
	//Image image2(5, 5, WHITE);
	//Image image3(15, 15, BLACK);
	//cout << "image1" << endl;
	//cout << image1 << endl;
	//cout << "image2" << endl;
	//cout << image2 << endl;
	//cout << "image3" << endl;
	//cout << image3 << endl;
	//
	//cout << "~image1" << endl;
	//cout << ~image1 << endl;
	//cout << "~image2" << endl;
	//cout << ~image2 << endl;
	//cout << "~image3" << endl;
	//cout << ~image3 << endl;

	//cout << "image1" << endl;
	//cout << image1 << endl;
	//cout << "image2" << endl;
	//cout << image2 << endl;
	//cout << "image3" << endl;
	//cout << image3 << endl;

	//cout << "image1=image2" << endl;
	//image1 = image2;
	//cout << image1 << endl;
	//cout << "image1=image2=image3" << endl;
	//image1 = image2 = image3;
	//cout << image1 << endl;

	//cout << "image1*0" << endl;
	//cout << image1 * 0 << endl;
	//cout << "image1*1" << endl;
	//cout << image1*1<< endl;
	//cout << "image1*2" << endl;
	//cout << image1 * 2 << endl;
	//cout << "image1*3" << endl;
	//cout << image1 * 3 << endl;

	return 0;
}