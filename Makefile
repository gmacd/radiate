
# TODO Debug/Release (NDEBUG for asserts)
# TODO src/ for src files
# TODO bin/ for .o files
# TODO Stick dependencies in separate dir
# TODO Disable exceptions, RTTI
# TODO Build tools - submodule?

TARGET=bin/radiate

SRCS_EXCL_MAIN= \
src/core/maths.cpp \
src/core/debug.cpp \
src/core/image.cpp

SRC_MAIN = src/main.cpp

SRCS = $(SRC_MAIN) $(SRCS_EXCL_MAIN)

SRCS_ALL = $(SRC_MAIN)

OBJS=$(SRCS:.cpp=.o)


CXX=clang
RM=rm -f


CPPFLAGS= \
	-g -DDEBUG \
	-Werror -Wall -Wextra \
	-Wno-extra-tokens \
	-std=c++1z \
	-fcolor-diagnostics

INCLUDES= \
	-Isrc \
	-I. \
	-Isrc/third/include

LDFLAGS= \
	-g -lc++

LDLIBS=
#	-lglfw3 \
#	-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo


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
