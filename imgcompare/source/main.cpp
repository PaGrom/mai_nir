#include <iostream>
#include <math.h>
#include <fstream>
#include <stdlib.h>
#include "CHistogramm.h"

int main(int argc, char** argv){

// 	CHistogramm hist;
//	CHistogramm hist2;

	TImage img, img2;

	if(argc<3)
	{
		printf("%s src.pgm dst.pgm\n", argv[0]);
		exit(1);
	}

	img.load(argv[1]);

	printf("The image is loaded\n");
	img.save(argv[2]);
	//hist.calculate(&img);
	//hist2.calculate(&img2);
	
	//printf("histogramms 1 and 2 are equale? %s \n", (hist==hist2)?"true":"false");
	//printf("histogramms 1 and 1 are equale? %s \n", (hist==hist2)?"true":"false");

	return 0;
}

