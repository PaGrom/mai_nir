#include "CHistogramm.h"
#include <iostream>

#define B 0.1

/**
 * Constructor
 */
CHistogramm::CHistogramm(void)
{
  length = 3*256;
  hist= new int[3*256];
  for(int i=0; i< length; ++i)
  {
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
	printf("\n");
  for(int i=0; i<im->getw(); ++i){
    for(int j=0; j<im->geth(); ++j){
      hist[im->getpoint(i,j)&255]++;
      hist[256+((im->getpoint(i,j)>>8)&255)]++;
      hist[2*256+((im->getpoint(i,j)>>16)&255)]++;
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
