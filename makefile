# File Name:  balanced_tree/makefile
# Build Date: Thu, Jul 24, 2025  5:33:43 PM
# Version:    0.2.0.1

# build settings
APP=balanced_tree
CXX=g++
CXXFLAGS=-Wall -std=c++20 -fPIC -g
SRC?=src
BLD?=build
OBJ?=build

# lib settings
LIBS=-L/usr/lib -L/usr/lib64 -L/usr/local/lib -L/usr/local/lib64
INCLUDES=-I/usr/local/include/cppunit/
LDFLAGS=$(INCLUDES) $(LIBS)

ifdef DEBUG
	CXXFLAGS += -DDEBUG
endif

ifdef CYGWIN
	CXXFLAGS +=-DCYGWIN
	LDFLAGS += -lfmt -lcppunit.dll
else
	LDFLAGS += -lfmt -lcppunit
endif

all: $(BLD)/balanced_tree $(BLD)/balanced_tree_test $(BLD)/libbalanced_tree.so $(BLD)/libbalanced_tree.a

rebuild: clean all

run_file:
	@bash arch.sh

$(BLD)/balanced_tree: $(OBJ)/balanced_tree.o $(BLD)/tree.o $(BLD)/node.o
	 $(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

$(BLD)/balanced_tree_test: $(OBJ)/balanced_tree_test.o $(OBJ)/tree.o $(OBJ)/node.o
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

$(BLD)/libbalanced_tree.so: $(BLD)/balanced_tree.o
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@
	-chmod 755 $(BLD)/libbalanced_tree.so

$(BLD)/libbalanced_tree.a: $(BLD)/balanced_tree.o
	-ar rvs $@ $(BLD)/balanced_tree.o
	-chmod 755 $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

install:
	cp ./$(BLD)/balanced_tree ./$(prefix)/bin/balanced_tree

uninstall:
	-rm ./$(prefix)/bin/balanced_tree

clean:
	-rm -f ./$(OBJ)/*.o
	-rm -f ./$(BLD)/*.o
	-rm -f ./$(BLD)/balanced_tree*

help:
	@echo  '  all         - build all'
	@echo  '  balanced_tree          - build balanced_tree executable'
	@echo  '  balanced_tree.o        - build not link'
	@echo  '  balanced_tree_test     - build cppunit test'
	@echo  '  balanced_tree_test.o   - build cppunit test'
	@echo  '  clean                      - remove all files from build dir'
	@echo  '  install                    - copy files to usr/local'
	@echo  '  dist                       - create distribution, tar.gz'
