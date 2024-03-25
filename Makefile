NAME = slproj

INCLUDES  = -I src
INCLUDES += -I src/c
INCLUDES += -I src/c++
INCLUDES += -I src/util

SOURCE  = $(wildcard src/*.cpp)
SOURCE += $(wildcard src/**/*.cpp)

BUILD_FLAGS = -s
COMPILE_FLAGS = -Wall -Werror -pedantic

COMPILER = g++

all: object
	${COMPILER} *.o -o bin/${NAME} ${BUILD_FLAGS}

object:
	${COMPILER} -c ${SOURCE} ${COMPILE_FLAGS} ${INCLUDES}