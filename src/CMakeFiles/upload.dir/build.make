# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/andersn/Fritid/2004a_lcd_example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andersn/Fritid/2004a_lcd_example

# Utility rule file for upload.

# Include any custom commands dependencies for this target.
include src/CMakeFiles/upload.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/upload.dir/progress.make

src/CMakeFiles/upload:
	cd /Users/andersn/Fritid/2004a_lcd_example/src && avrdude -c avrisp2 -p atmega2560 -P /dev/cu.usbmodem1101 -U flash:w:2004a_ldc_example.hex -D

upload: src/CMakeFiles/upload
upload: src/CMakeFiles/upload.dir/build.make
.PHONY : upload

# Rule to build all files generated by this target.
src/CMakeFiles/upload.dir/build: upload
.PHONY : src/CMakeFiles/upload.dir/build

src/CMakeFiles/upload.dir/clean:
	cd /Users/andersn/Fritid/2004a_lcd_example/src && $(CMAKE_COMMAND) -P CMakeFiles/upload.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/upload.dir/clean

src/CMakeFiles/upload.dir/depend:
	cd /Users/andersn/Fritid/2004a_lcd_example && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/andersn/Fritid/2004a_lcd_example /Users/andersn/Fritid/2004a_lcd_example/src /Users/andersn/Fritid/2004a_lcd_example /Users/andersn/Fritid/2004a_lcd_example/src /Users/andersn/Fritid/2004a_lcd_example/src/CMakeFiles/upload.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/upload.dir/depend

