%.o : %.cpp
	g++ -I /usr/include/freetype2 -I /usr/include/OpenLayer -c $<

THIRDPARTY_DIR = ../../..

INCLUDES = -I . -I $(THIRDPARTY_DIR)/midishare/include \
           -I /usr/include/freetype2

test: spline.o patch_splines_2.o
	g++ -c test.cpp
	g++ -o $@ spline.o patch_splines_2.o test.o $$(pkg-config allegro --libs) -lopenlayer -lGLU -lGL

more: patch_splines_2.o
	g++ $(INCLUDES) -c MAIN_janv_2014_opensource_kbd.cpp

doc:
	doxygen Doxyfile

clean:
	rm -f *~ *.o test

.PHONY: doc more clean
