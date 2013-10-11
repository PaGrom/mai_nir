#include "timage.h"

class CHistogramm{
protected:
  const int brght;

  int length;
  int* hist;

public:
  CHistogramm(void);
  void calculate(TImage *im);

  friend bool operator==(const CHistogramm& left,const CHistogramm& right);
};
