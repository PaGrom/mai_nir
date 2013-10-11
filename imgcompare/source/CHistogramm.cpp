#include "CHistogramm.h"
#include <iostream>

#define B 0.1

/**
 * Constructor
 */
CHistogramm::CHistogramm(void)
  : brght((int) MaxRGB)
{
	length = 3 * (brght + 1);
	hist= new int[length];
	for(int i=0; i< length; ++i) {
		printf("\n");
		hist[i]=0;
	}
}

/**
 * Calculates the Histogramm of an PPM image
 * devides each pixel into RGB
 */
void CHistogramm::calculate(TImage *im)
{
	Image img = im->getImg();

  for(int i = 0; i < im->getWth(); ++i) {
		for(int j = 0; j < im->getHgh(); ++j) {
      hist[(int) img.pixelColor(i, j).redQuantum()]++;
      hist[(brght+1) + (int)img.pixelColor(i, j).greenQuantum()]++;
			hist[2 * (brght+1) + (int)img.pixelColor(i, j).blueQuantum()]++;

      /*
      hist[im->getpoint(i, j) & 255]++;
			hist[256 + ((im->getpoint(i, j) >> 8) & 255)]++;
			hist[2 * 256 + ((im->getpoint(i, j) >> 16) & 255)]++;
      */
		}
	}
	for(int i=0; i< length/3; ++i)
		printf("%d ", hist[i]);
	printf("\n");
}

/**
 * Equality operator
 */
bool operator==(const CHistogramm& left, const CHistogramm& right) 
{
	int* hist1 = left.hist;
	int* hist2 = right.hist;
	long double sum1=0,sum2=0;
	bool result=0;
	double  res=0;

	if (left.length != right.length)
		return result;

	for(int i=0; i<right.length; ++i){
		sum1+=*(hist1+i);
		sum2+=*(hist2+i);
	}


	for (int i=0; i<left.length; ++i)
	{
		//result = result || !(*(hist1+i) == *(hist2+i));

		double x=(*(hist1+i))/sum1;
		double y=(*(hist2+i))/sum2;
		res += (abs(x-y));
		result = result || !res<B;
	}
	return !result;
}
