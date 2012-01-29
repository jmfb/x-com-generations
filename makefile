#==============================================================================
# Constants used for later in the build script.
#==============================================================================
expected_build_file = dependecies.txt
output_file = xcom.exe

#==============================================================================
# Use a dummy variable that executes a shell command to generate the build file.
# This is at the top of the file because it must be "evaluated" prior to the
# include statement.
#==============================================================================
dummy = $(shell g++ -std=c++0x -MM *.cpp > $(expected_build_file))
ifeq ($(dummy),dummy)
endif
build_file = $(wildcard $(expected_build_file))

#==============================================================================
# Default target.  Links the executable by expecting every cpp file to generate
# an object file.
# - subsystem: Which linker subsystem is used: 'console' or 'windows'.
#==============================================================================
objects = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
subsystem = -Xlinker --subsystem -Xlinker console
options = -std=c++0x -O3 -Wall
libraries = -lopengl32 -lgdi32
xcom: $(objects)
	g++ $(options) -o $(output_file) $(subsystem) $(objects) $(libraries)

#==============================================================================
# Makefile preparation.  Clears out known suffixes and only recognizes object
# files and cpp files.  Redefines the implicit rule for building object files
# from cpp files.
#==============================================================================
includes = 
.SUFFIXES:
.SUFFIXES: .o .cpp
.cpp.o:
	g++ $(options) $(includes) -c -o $@ $<

#==============================================================================
# Include the build file.  This file contains the g++ generated listing of
# file dependencies generated from #include directives in all cpp files.
# Example: main.o: main.cpp Error.h
#==============================================================================
ifeq ($(build_file),$(expected_build_file))
include $(expected_build_file)
endif

#==============================================================================
# Clean directive.  This will delete all intermediate files generated during
# the build process.  This handles the case when there are no files to delete.
#==============================================================================
clean_target = $(build_file) $(wildcard xcom.exe) $(wildcard *.o)
empty_target = $(wildcard doesnotexist) $(wildcard doesnotexist) $(wildcard doesnotexist)
.PHONY: clean
clean:
ifneq ($(clean_target),$(empty_target))
	-del $(clean_target)
endif
