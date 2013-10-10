#include "timage.h"

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
	if (argc != 2) return 1;

	TImage img(argv[1]);
	cout << img.getWth() << "x" << img.getHgh() << endl
		 << img.getMax('r') << " " << img.getMax('g') << " " << img.getMax('b')
		 << endl;

	Image pic = img.getImg();
	pic.pixelColor(100, 100, Color("white"));
	pic.write("pic1.jpg");

	pic.pixelColor(200, 100, Color("green"));

	TImage img2;
	img2.setImg(pic);
	if (img == img2)
		cout << "the same\n";
	else
		cout << "different\n";

	img2.save("pic2.jpg");
	
	TImage img3(argv[1]);
	if (img == img3)
		cout << "the same\n";
	else
		cout << "different\n";

	return 0;
}
