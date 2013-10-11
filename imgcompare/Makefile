SRC_CPP = CHistogramm.cpp main.cpp  timage.cpp

SRC_C =
SRC_DIR = source
OBJ_DIR = debug
vpath %.cpp $(SRC_DIR)
vpath %.c $(SRC_DIR)
vpath %.o $(OBJ_DIR)
vpath % $(OBJ_DIR)

LIB_INC = -I../LIB/tinyxml
CFLAGS = -Wall $(LIB_INC) -DPOSIX_PORTING -DUSE_TEST_FILE
MAGICK=`Magick++-config --cppflags --cxxflags --ldflags --libs`
#TARGET = -DMOXA_UC74XX

ifndef $(TARGET)
CXX = g++
else
CXX = mxscaleb-g++
endif

APPNAME = imgcompare


all:$(APPNAME)

$(APPNAME): $(patsubst %.cpp,%.o,$(SRC_CPP)) $(patsubst %.c,%.o,$(SRC_C))
	$(CXX) $(addprefix $(OBJ_DIR)/,$(notdir $^)) -o $(OBJ_DIR)/$@

%.o: %.cpp
	$(CXX) $(CFLAGS) $(MAGICK) -c $< -o $(OBJ_DIR)/$@

%.o: %.c
	gcc $(CFLAGS) $(MAGICK) -c $< -o $(OBJ_DIR)/$@

cleanobj:
	-rm $(OBJ_DIR)/*.o

clean: cleanobj
	-rm $(OBJ_DIR)/$(APPNAME)
