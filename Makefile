#
# Makefile for CubeGame
# Author: Esa Varemo
#


#Directory for *.o, *.d, etc.
BUILDDIR=build
SRCDIR=src
TARGETDIR=target

SOURCES=Entity.cpp Cube.cpp Game.cpp Main.cpp entry.cpp Ground.cpp GameTimer.cpp Stage.cpp utils.cpp
DEPLOY=stage.txt
EXECUTABLE=cubeGame

OBJECTS=$(addprefix $(BUILDDIR)/,$(SOURCES:.cpp=.o))
DEPFILES=$(addprefix $(BUILDDIR)/,$(SOURCES:.cpp=.d))


CC=g++
LIBS=-lGL -lGLU -lglut
CFLAGS=-Wall -MMD -std=c++11 -g

all: $(EXECUTABLE) | $(TARGETDIR)
	cp $(BUILDDIR)/$(EXECUTABLE) $(TARGETDIR)/
	cp $(DEPLOY) $(TARGETDIR)/

$(EXECUTABLE): $(OBJECTS) | $(BUILDDIR)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS) -o $(BUILDDIR)/$(EXECUTABLE)

$(OBJECTS): $(BUILDDIR)/%.o: $(SRCDIR)/%.cpp | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR):
	-mkdir $(BUILDDIR)

$(TARGETDIR):
	-mkdir $(TARGETDIR)

clean:
	rm $(EXECUTABLE) $(BUILDDIR) -r

run: all
	cd $(TARGETDIR); ./$(EXECUTABLE)
-include $(DEPFILES)
