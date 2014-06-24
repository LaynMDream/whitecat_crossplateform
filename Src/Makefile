%.o : %.cpp
	g++ -I /usr/include/freetype2 -I /usr/include/OpenLayer -c $<

THIRDPARTY_DIR = ../../..

INCLUDES = -I . -I $(THIRDPARTY_DIR)/midishare/include \
           -I /usr/include/freetype2

test: patch_splines_2.o
	g++ $(INCLUDES) -c MAIN_janv_2014_opensource_kbd.cpp

doc:
	doxygen Doxyfile

.PHONY: test doc
