%.o : %.cpp
	g++ -I /usr/include/freetype2 -I /usr/include/OpenLayer -c $<

THIRDPARTY_DIR = ../../..

INCLUDES = -I . -I $(THIRDPARTY_DIR)/midishare/include \
           -I /usr/include/freetype2

LIBS = $(shell pkg-config allegro --libs) -lopenlayer -lGL

test: spline.o curve_node.o test.o
	g++ -o $@  $(LIBS) spline.o curve_node.o test.o

more: patch_splines_2.o
	g++ $(INCLUDES) -c MAIN_janv_2014_opensource_kbd.cpp

doc:
	doxygen Doxyfile

clean:
	rm -f *~ *.o test

.PHONY: doc more clean
