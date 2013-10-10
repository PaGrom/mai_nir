#ifndef TIMAGE_H_
#define TIMAGE_H_

// #include <math.h>
// #include <stdlib.h>

#include <fstream>
using std::ifstream;
using std::ios_base;

#include <ImageMagick-6/Magick++.h>
using Magick::Image;
using Magick::Color;
using Magick::Geometry;

class TImage {
protected:
	Image img;
	Color max;

	int wth;
	int hgh;
	
	void getProps();	// wth, hgh, max

public:
	TImage(const char* file = nullptr);	// loading in constr if path specified
	~TImage();
	
	int getWth() const;
	int getHgh() const;
	int getMax(const char cl) const;	// cl: 'r', 'g', 'b'

	Image& getImg();
	void setImg(const Image& Image);
	
	void load(const char* file);
	void save(const char* file);
	void copy(TImage& image);

	// void filterSobel();

	TImage& operator=(TImage& image);
	friend bool operator==(TImage& left, TImage& right);
};

#endif
