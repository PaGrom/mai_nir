#include "timage.h"

class CHistogramm{
protected:
  int length;
  int* hist;

public:
  CHistogramm(void);
  void calculate(TImage *im);

  friend bool operator==(const CHistogramm& left,const CHistogramm& right);
};
