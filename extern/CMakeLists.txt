# Define the output library name. Use this name when referencing the library
# in the app and test CMakeLists
set(LIBRARY_FILENAME i2c)

# Include the header file(s) for the library
set (headers ${CMAKE_SOURCE_DIR}/extern/pfleury/i2cmaster.h)

# Create a library for the non-executable library
add_library(${LIBRARY_FILENAME} pfleury/twimaster.c)

# Make sure the compiler can include files for the library in other parts of the project
target_include_directories (${LIBRARY_FILENAME} PUBLIC pfleury)
