# TODO src/ for src files
# TODO bin/ for .o files
# TODO Stick dependencies in separate dir
# TODO Disable exceptions, RTTI

TARGET=bin/radiate

SRCS_EXCL_MAIN= \
src/core/camera.cpp \
src/core/debug.cpp \
src/core/image.cpp \
src/core/rnd.cpp \
src/core/timer.cpp \
src/core/vec4.cpp \
src/obj/intersect.cpp \
src/obj/obj.cpp \
src/obj/scene.cpp

SRC_MAIN = src/main.cpp

SRCS = $(SRC_MAIN) $(SRCS_EXCL_MAIN)

SRCS_ALL = $(SRC_MAIN)

OBJS=$(SRCS:.cpp=.o)


CXX=clang
RM=rm -f


CPPFLAGS= \
	-Werror -Wall -Wextra \
	-Wno-extra-tokens \
	-std=c++1z \
	-fcolor-diagnostics

INCLUDES= \
	-Isrc \
	-Isrc/third/include \
	-I.

LDFLAGS= \
	-stdlib=libc++ -lc++

LDLIBS=
#	-lglfw3 \
#	-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo


DEBUG ?= 0
ifeq ($(DEBUG), 1)
	# Debug
	CPPFLAGS += -g -DDEBUG
	LDFLAGS += -g
else
	# Release (Default)
	CPPFLAGS += -O3
endif


%.o : %.cpp
	$(CXX) $(CPPFLAGS) $(INCLUDES) -MMD -c -o $@ $<


all: radiate

radiate: $(OBJS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS)

clean:
	$(RM) $(OBJS) $(TARGET)

distclean: clean
	find . -type f -name '*.d' -exec rm {} +

-include $(SRCS_ALL:.cpp=.d)
