# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /media/benoit/DATA/Benoit/EPFL/tekari

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/benoit/DATA/Benoit/EPFL/tekari/build_debug

# Include any dependencies generated for this target.
include ext_build/triangle/CMakeFiles/triangle.dir/depend.make

# Include the progress variables for this target.
include ext_build/triangle/CMakeFiles/triangle.dir/progress.make

# Include the compile flags for this target's objects.
include ext_build/triangle/CMakeFiles/triangle.dir/flags.make

ext_build/triangle/CMakeFiles/triangle.dir/triangle.c.o: ext_build/triangle/CMakeFiles/triangle.dir/flags.make
ext_build/triangle/CMakeFiles/triangle.dir/triangle.c.o: ../ext/triangle/triangle.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/benoit/DATA/Benoit/EPFL/tekari/build_debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object ext_build/triangle/CMakeFiles/triangle.dir/triangle.c.o"
	cd /media/benoit/DATA/Benoit/EPFL/tekari/build_debug/ext_build/triangle && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/triangle.dir/triangle.c.o   -c /media/benoit/DATA/Benoit/EPFL/tekari/ext/triangle/triangle.c

ext_build/triangle/CMakeFiles/triangle.dir/triangle.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/triangle.dir/triangle.c.i"
	cd /media/benoit/DATA/Benoit/EPFL/tekari/build_debug/ext_build/triangle && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/benoit/DATA/Benoit/EPFL/tekari/ext/triangle/triangle.c > CMakeFiles/triangle.dir/triangle.c.i

ext_build/triangle/CMakeFiles/triangle.dir/triangle.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/triangle.dir/triangle.c.s"
	cd /media/benoit/DATA/Benoit/EPFL/tekari/build_debug/ext_build/triangle && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/benoit/DATA/Benoit/EPFL/tekari/ext/triangle/triangle.c -o CMakeFiles/triangle.dir/triangle.c.s

ext_build/triangle/CMakeFiles/triangle.dir/triangle.c.o.requires:

.PHONY : ext_build/triangle/CMakeFiles/triangle.dir/triangle.c.o.requires

ext_build/triangle/CMakeFiles/triangle.dir/triangle.c.o.provides: ext_build/triangle/CMakeFiles/triangle.dir/triangle.c.o.requires
	$(MAKE) -f ext_build/triangle/CMakeFiles/triangle.dir/build.make ext_build/triangle/CMakeFiles/triangle.dir/triangle.c.o.provides.build
.PHONY : ext_build/triangle/CMakeFiles/triangle.dir/triangle.c.o.provides

ext_build/triangle/CMakeFiles/triangle.dir/triangle.c.o.provides.build: ext_build/triangle/CMakeFiles/triangle.dir/triangle.c.o


# Object files for target triangle
triangle_OBJECTS = \
"CMakeFiles/triangle.dir/triangle.c.o"

# External object files for target triangle
triangle_EXTERNAL_OBJECTS =

ext_build/triangle/libtriangle.a: ext_build/triangle/CMakeFiles/triangle.dir/triangle.c.o
ext_build/triangle/libtriangle.a: ext_build/triangle/CMakeFiles/triangle.dir/build.make
ext_build/triangle/libtriangle.a: ext_build/triangle/CMakeFiles/triangle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/benoit/DATA/Benoit/EPFL/tekari/build_debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libtriangle.a"
	cd /media/benoit/DATA/Benoit/EPFL/tekari/build_debug/ext_build/triangle && $(CMAKE_COMMAND) -P CMakeFiles/triangle.dir/cmake_clean_target.cmake
	cd /media/benoit/DATA/Benoit/EPFL/tekari/build_debug/ext_build/triangle && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/triangle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ext_build/triangle/CMakeFiles/triangle.dir/build: ext_build/triangle/libtriangle.a

.PHONY : ext_build/triangle/CMakeFiles/triangle.dir/build

ext_build/triangle/CMakeFiles/triangle.dir/requires: ext_build/triangle/CMakeFiles/triangle.dir/triangle.c.o.requires

.PHONY : ext_build/triangle/CMakeFiles/triangle.dir/requires

ext_build/triangle/CMakeFiles/triangle.dir/clean:
	cd /media/benoit/DATA/Benoit/EPFL/tekari/build_debug/ext_build/triangle && $(CMAKE_COMMAND) -P CMakeFiles/triangle.dir/cmake_clean.cmake
.PHONY : ext_build/triangle/CMakeFiles/triangle.dir/clean

ext_build/triangle/CMakeFiles/triangle.dir/depend:
	cd /media/benoit/DATA/Benoit/EPFL/tekari/build_debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/benoit/DATA/Benoit/EPFL/tekari /media/benoit/DATA/Benoit/EPFL/tekari/ext/triangle /media/benoit/DATA/Benoit/EPFL/tekari/build_debug /media/benoit/DATA/Benoit/EPFL/tekari/build_debug/ext_build/triangle /media/benoit/DATA/Benoit/EPFL/tekari/build_debug/ext_build/triangle/CMakeFiles/triangle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ext_build/triangle/CMakeFiles/triangle.dir/depend

