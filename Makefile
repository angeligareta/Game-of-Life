CXX=g++
CXXFLAGS=-std=c++11

SRCDIR=src
BUILDDIR=build
TARGET=bin/lifegame

SOURCES=$(shell find $(SRCDIR) -type f -name *.cpp)
OBJECTS=$(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(BUILDDIR)/ExtendedCells
	@echo " $(CXX) $(CXXFLAGS) $(INC) -c -o $@ $<"; $(CXX) $(CXXFLAGS) -c -o $@ $<

all: ${OBJECTS}
	$(CXX) $(CXXFLAGS) ${OBJECTS} -o ${TARGET}

clean: 
	rm -r ${BUILDDIR} ${TARGET}