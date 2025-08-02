# File Name:  balanced_tree/makefile
# Build Date: Thu, Jul 24, 2025  5:33:43 PM
# Version:    0.2.0.1

# build settings
APP=balanced_tree
CXX=g++
CXXFLAGS=-Wall -std=c++20 -fPIC -g
CXXFLAGS=-std=c++20 -fPIC -g
SRC?=src
BLD?=build
OBJ?=build

# lib settings
LIBS=-L/usr/lib -L/usr/lib64 -L/usr/local/lib -L/usr/local/lib64
INCLUDES=-I/usr/local/include/cppunit/
LDFLAGS=$(INCLUDES) $(LIBS)

ifdef DEBUG
	CXXFLAGS += -DDEBUG
	echo TEST
endif

ifdef CYGWIN
	CXXFLAGS +=-DCYGWIN
	LDFLAGS += -lfmt -lcppunit.dll
else
	LDFLAGS += -lfmt -lcppunit
endif

all: $(BLD)/$(APP) $(BLD)/$(APP)_test $(BLD)/lib$(APP).so $(BLD)/lib$(APP).a

rebuild: clean all

run_file:
	@bash arch.sh

$(BLD)/$(APP): $(OBJ)/$(APP).o $(BLD)/tree.o $(BLD)/node.o
	 $(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

$(BLD)/$(APP)_test: $(OBJ)/$(APP)_test.o $(OBJ)/tree.o $(OBJ)/node.o
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

$(BLD)/lib$(APP).so: $(BLD)/$(APP).o
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@
	-chmod 755 $(BLD)/lib$(APP).so

$(BLD)/lib$(APP).a: $(BLD)/$(APP).o
	-ar rvs $@ $(BLD)/$(APP).o
	-chmod 755 $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

install:
	cp ./$(BLD)/$(APP) ./$(prefix)/bin/$(APP)

uninstall:
	-rm ./$(prefix)/bin/$(APP)

clean:
	-rm -f ./$(OBJ)/*.o
	-rm -f ./$(BLD)/*.o
	-rm -f ./$(BLD)/$(APP)*

help:
	@echo  '  all         - build all'
	@echo  '  $(APP)          - build $(APP) executable'
	@echo  '  $(APP).o        - build not link'
	@echo  '  $(APP)_test     - build cppunit test'
	@echo  '  $(APP)_test.o   - build cppunit test'
	@echo  '  clean                  - remove all files from build dir'
	@echo  '  install                - copy files to usr/local'
	@echo  '  dist                   - create distribution, tar.gz'
