# This file illustrates how one or more files with .cpp and .hpp-files can be combined 
# in the same library file. Remember to place the accompanying header file in "include/project".

# Define the output library name. Use this name when referencing the library
# in the app and test CMakeLists
set(LIBRARY_FILENAME display)

# Include the header file(s) for the library
set (headers ${CMAKE_SOURCE_DIR}/include/kabeltester/display.h 
             ${CMAKE_SOURCE_DIR}/display/display_commands.h)

# Create a library for the non-executable library
add_library(${LIBRARY_FILENAME} display.c ${headers})
target_link_libraries(${LIBRARY_FILENAME} PRIVATE i2c)

# Make sure the compiler can include files for the library in other parts of the project
target_include_directories (${LIBRARY_FILENAME} PUBLIC ../include)