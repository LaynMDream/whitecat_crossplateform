%.o : %.cpp
	g++ -I /usr/include/freetype2 -I /usr/include/OpenLayer -c $<

test: patch_splines_2.o
	g++ -I /usr/include/freetype2 -c MAIN_avec_objets.cpp

doc:
	doxygen Doxyfile

.PHONY: test doc
