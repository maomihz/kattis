SRCS = $(wildcard src/*/*.cpp)
EXES = $(notdir $(SRCS:.cpp=))
VPATH = $(subst $() $(),:,$(dir $(SRCS)))

CXX = g++
CXXFLAGS = -g -std=c++11

SHELL = /bin/bash

.PHONY: clean

.SUFFIXES:
.PRECIOUS: %.cpp

.PHONY: all

all: $(EXES)

%.cpp:
	@./test.sh +$*

%: %.cpp
	[ -f $< ] && $(CXX) $(CXXFLAGS) -o $@ $<

run%: %
	@./$<

test%: %
	@./test.sh $<

test2%: %
	@./test.sh $< 2>/dev/null

rm%:
	$(RM) -r src/$*

clean:
	$(RM) $(EXES)
	$(RM) -r *.dSYM

