# Project: White_Cat

DEBUG   = no
CPP      = g++
CC       = gcc
WINDRES  = windres

Main-S = ../Src/MAIN_janv_2014_opensource_kbd.cpp
Main-O = ../whitecatbuild/build/white_cat_for_mingw/obj/MAIN.o
WCt-RC = WhiteCat_private.rc
RES      = ../whitecatbuild/build/white_cat_for_mingw/obj/WhiteCat_private.res
OBJ      = ../whitecatbuild/build/white_cat_for_mingw/obj/MAIN.o $(RES)
LINKOBJ  = ../whitecatbuild/build/white_cat_for_mingw/obj/MAIN.o $(RES)

LIBS     = -static-libgcc -L"C:/MinGW/lib" -L"../whitecatlib/lib/windows/audiere-1.9.4-win32/lib" -L"../whitecatlib/lib/windows/enttec_pro" -L"../whitecatlib/lib/windows/midishare/librairies" -L"../whitecatlib/lib/windows/odmxusb_terry" -L"../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/lib" -L"../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/x86/mingw/lib" -mwindows -lopenlayer -lglyph-agl -lfreetype -llogg -lvorbis -lalleggl -ljpgalleg -lalleg44.dll -luser32 -lgdi32 -lglu32 -lopengl32 -lwsock32 -liphlpapi -lpng12.dll -lz -lhpdf ../whitecatlib/lib/windows/odmxusb_terry/FTD2XX.lib ../whitecatlib/lib/windows/enttec_pro/ftd2xx.lib ../whitecatlib/lib/windows/midishare/libraries/mshare32.lib ../whitecatlib/lib/windows/audiere-1.9.4-win32/lib/audiere.lib ../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/x86/mingw/lib/libopencv_calib3d248.dll.a ../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/x86/mingw/lib/libopencv_contrib248.dll.a ../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/x86/mingw/lib/libopencv_core248.dll.a ../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/x86/mingw/lib/libopencv_features2d248.dll.a ../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/x86/mingw/lib/libopencv_flann248.dll.a ../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/x86/mingw/lib/libopencv_gpu248.dll.a ../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/x86/mingw/lib/libopencv_highgui248.dll.a ../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/x86/mingw/lib/libopencv_imgproc248.dll.a ../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/x86/mingw/lib/libopencv_legacy248.dll.a ../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/x86/mingw/lib/libopencv_ml248.dll.a ../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/x86/mingw/lib/libopencv_nonfree248.dll.a ../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/x86/mingw/lib/libopencv_objdetect248.dll.a ../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/x86/mingw/lib/libopencv_ocl248.dll.a ../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/x86/mingw/lib/libopencv_photo248.dll.a ../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/x86/mingw/lib/libopencv_stitching248.dll.a ../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/x86/mingw/lib/libopencv_superres248.dll.a ../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/x86/mingw/lib/libopencv_ts248.a ../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/x86/mingw/lib/libopencv_video248.dll.a ../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/x86/mingw/lib/libopencv_videostab248.dll.a ../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/lib/libz.a -pg
INCS     = -I"../whitecatlib/lib/windows/audiere-1.9.4-win32/include" -I"../whitecatlib/lib/windows/Cserial" -I"../whitecatlib/lib/windows/dashard" -I"../whitecatlib/lib/windows/enttec_pro" -I"../whitecatlib/lib/windows/midishare/include" -I"../whitecatlib/lib/windows/odmxusb_terry" -I"C:/MinGW/include" -I"../Src" -I"../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/include"
CXXINCS  = -I"../whitecatlib/lib/windows/audiere-1.9.4-win32/include" -I"../whitecatlib/lib/windows/Cserial" -I"../whitecatlib/lib/windows/dashard" -I"../whitecatlib/lib/windows/enttec_pro" -I"../whitecatlib/lib/windows/midishare/include" -I"../whitecatlib/lib/windows/odmxusb_terry" -I"C:/MinGW/include" -I"../Src" -I"../whitecatlib/lib/windows/compiledlibsforGCC4_8_1/include"

RM = rm -rf

ifeq ($(DEBUG),yes)
	CXXFLAGS = $(CXXINCS) -pg -g
	CFLAGS   = $(INCS) -pg -g
	BIN      = ../whitecatbuild/build/white_cat_for_mingw/white_cat_ntb_dbg.exe	
	LDFLAGS=
else
	CXXFLAGS = $(CXXINCS) -pg
	CFLAGS   = $(INCS) -pg
	BIN      = ../whitecatbuild/build/white_cat_for_mingw/white_cat_ntb.exe	
	LDFLAGS=
endif

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(Main-O) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

$(Main-O) : $(Main-S)
	$(CPP) -c $(Main-S) -o $(Main-O) $(CXXFLAGS)

$(RES) : $(WCt-RC) 
	$(WINDRES) -i $(WCt-RC) --input-format=rc -o $(RES) -O coff 