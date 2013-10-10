#include "timage.h"

/*
**	public:
*/

TImage::TImage(const char* file)
	: max(Color(0, 0, 0)), wth(0), hgh(0)
{
	if (file != nullptr)
		load(file);
}

TImage::~TImage() {}

int TImage::getWth() const {
	return wth;
}

int TImage::getHgh() const {
	return hgh;
}

// cl: 'r', 'g', 'b'
int TImage::getMax(const char cl) const {
	if (cl == 'r')
		return max.redQuantum();
	else if (cl == 'g')
		return max.greenQuantum();
	else if (cl == 'b')
		return max.blueQuantum();
	
	return 0;
}

Image& TImage::getImg() {
	return img;
}

<<<<<<< HEAD
	FILE *fp;
	fp = fopen(file,"r");

	if (fp == NULL) {
		perror ("Error opening file");
		exit(0);
	}

	char* c = (char*) malloc(100* sizeof(char));

	fgets(c,sizeof(c),fp);
	fgets(c,sizeof(c),fp);

	if(c[0]!='#')
		sscanf(c,"%d%d",&w,&h);
	else
		fscanf(fp, "%d%d", &w, &h);
	fscanf(fp, "%d", &max);
	image = (int*)malloc(sizeof(int)*(w*h));
	printf("%d\n", __LINE__);
		printf("image w=%d image h=%d \n",w,h);
	int i = 0;
	while(fscanf(fp, "%d", &image[i]) != EOF) {
		printf("read %d line %d\n",image[i],i);
		i++;
	}
	
	fclose(fp);
}

void TImage::save(char* file)
{
	FILE *fp;
	fp = fopen(file,"w");
	if (fp == NULL) {
		perror ("Error opening file");
		exit(0);
	}
=======
void TImage::setImg(const Image& image) {
	img = image;
	getProps();	// wth, hgh, max
}

void TImage::load(const char* file) {
	img.read(file);
	getProps(); // wth, hgh, max
}
>>>>>>> 20a5bc7ca560f549505c5f1fe921a30757e43f94

void TImage::save(const char* file) {
	img.write(file);
}

void TImage::copy(TImage& image) {
	img = image.img;	// automatic dealloc
	wth = image.wth;
	hgh = image.hgh;
	max = image.max;
}

TImage& TImage::operator=(TImage& image) {
	copy(image);
	return *this;
}

bool operator==(TImage& left, TImage& right) {
	// comparing only imgs, because other props equal to img attributes
	if (left.img.compare(right.img))
		return true;
	
	return false;
}
/*
void TImage::filterSobel()
{
	int z[3][3];
	int Gx,Gy,G;
	int Wx[3][3] = {{-1,-2,-1},{0,0,0},{1,2,1}};
	int Wy[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};

	int *buf;
	buf = (int*)malloc(sizeof(int)*(w*h));

	for(int y=1;y<=h;y++)
	{
		for(int x=1;x<=w;x++)
		{
			z[0][0] = getpoint(x-1,y-1);
			z[0][1] = getpoint(x,y-1);
			z[0][2] = getpoint(x+1,y-1);
			z[1][0] = getpoint(x-1,y);
			z[1][1] = getpoint(x,y);
			z[1][2] = getpoint(x+1,y);
			z[2][0] = getpoint(x-1,y+1);
			z[2][1] = getpoint(x,y+1);
			z[2][2] = getpoint(x+1,y+1);
			Gx = 0;
			Gy = 0;
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
				{
					Gx += Wx[i][j] * z[i][j];
					Gy += Wy[i][j] * z[i][j];
				}

			G=sqrt(Gx*Gx+Gy*Gy);
			if(G>max) G=max;
			//if(G<max*0.2) G=0;
			buf[(y-1)*w+x-1] = G;
		}
	}
	for(int y=1;y<=h;y++)
		for(int x=1;x<=w;x++)
			image[(y-1)*w+x-1] = buf[(y-1)*w+x-1];
}
*/

/*
** protected:
*/

void TImage::getProps() {
	wth = img.size().width();
	hgh = img.size().height();

	// finding max values of red, green, blue
	for (int i = 0; i < hgh; i++)
		for (int j = 0; j < wth; j++) {
			if (max.redQuantum() < img.pixelColor(j, i).redQuantum())
				max.redQuantum(img.pixelColor(j, i).redQuantum());

			if (max.greenQuantum() < img.pixelColor(j, i).greenQuantum())
				max.greenQuantum(img.pixelColor(j, i).greenQuantum());

			if (max.blueQuantum() < img.pixelColor(j, i).blueQuantum())
				max.blueQuantum(img.pixelColor(j, i).blueQuantum());
		}
}
