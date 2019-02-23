SRCS = $(wildcard src/*/*.cpp)
EXES = $(notdir $(SRCS:.cpp=))
VPATH = $(subst $() $(),:,$(dir $(SRCS)))

CXX = g++
CXXFLAGS = -g -std=c++11

.PHONY: clean

.SUFFIXES:
.PRECIOUS: %.cpp

.PHONY: all

all: $(EXES)

%.cpp:
	mkdir -p src/$*
	cp --no-clobber template.h src/$*/$@
	bash -c "touch src/$*/$*{1..9}.txt"

%: %.cpp
	[ -f $< ] && $(CXX) $(CXXFLAGS) -o $@ $<

run%: %
	@./$<

test%: %
	@for t in src/$*/$**.txt; do \
		if [ -s $$t ]; then \
			echo "\n\n\e[36m=** $${t##*/} **=\e[0m"; \
			./$< < $$t; \
		fi; \
	done
rm%:
	$(RM) -r src/$*

clean:
	$(RM) $(EXES)
	$(RM) -r *.dSYM

