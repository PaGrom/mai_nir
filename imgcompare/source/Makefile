CC=g++
CFLAGS=-std=c++11 -Wall -c
MAGICK=`Magick++-config --cppflags --cxxflags --ldflags --libs`

all: test

timage.o: timage.cpp
	$(CC) $(CFLAGS) $(MAGICK) timage.cpp -o timage.o

testTImage.o: testTImage.cpp
	$(CC) $(CFLAGS) $(MAGICK) testTImage.cpp -o testTImage.o

test: testTImage.o timage.o
	$(CC) $(MAGICK) testTImage.o timage.o -o test

clean:
	rm *.o
