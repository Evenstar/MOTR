# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/2.8.12.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/2.8.12.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/local/Cellar/cmake/2.8.12.2/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chengtai/Documents/2014/MOTR/modules/beta/beta

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chengtai/Documents/2014/MOTR/modules/beta/beta

# Include any dependencies generated for this target.
include CMakeFiles/EXE.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/EXE.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EXE.dir/flags.make

CMakeFiles/EXE.dir/main.cpp.o: CMakeFiles/EXE.dir/flags.make
CMakeFiles/EXE.dir/main.cpp.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/chengtai/Documents/2014/MOTR/modules/beta/beta/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/EXE.dir/main.cpp.o"
	/usr/local/bin/g++-4.8   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/EXE.dir/main.cpp.o -c /Users/chengtai/Documents/2014/MOTR/modules/beta/beta/main.cpp

CMakeFiles/EXE.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EXE.dir/main.cpp.i"
	/usr/local/bin/g++-4.8  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/chengtai/Documents/2014/MOTR/modules/beta/beta/main.cpp > CMakeFiles/EXE.dir/main.cpp.i

CMakeFiles/EXE.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EXE.dir/main.cpp.s"
	/usr/local/bin/g++-4.8  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/chengtai/Documents/2014/MOTR/modules/beta/beta/main.cpp -o CMakeFiles/EXE.dir/main.cpp.s

CMakeFiles/EXE.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/EXE.dir/main.cpp.o.requires

CMakeFiles/EXE.dir/main.cpp.o.provides: CMakeFiles/EXE.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/EXE.dir/build.make CMakeFiles/EXE.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/EXE.dir/main.cpp.o.provides

CMakeFiles/EXE.dir/main.cpp.o.provides.build: CMakeFiles/EXE.dir/main.cpp.o

# Object files for target EXE
EXE_OBJECTS = \
"CMakeFiles/EXE.dir/main.cpp.o"

# External object files for target EXE
EXE_EXTERNAL_OBJECTS =

EXE: CMakeFiles/EXE.dir/main.cpp.o
EXE: CMakeFiles/EXE.dir/build.make
EXE: CMakeFiles/EXE.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable EXE"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EXE.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EXE.dir/build: EXE
.PHONY : CMakeFiles/EXE.dir/build

CMakeFiles/EXE.dir/requires: CMakeFiles/EXE.dir/main.cpp.o.requires
.PHONY : CMakeFiles/EXE.dir/requires

CMakeFiles/EXE.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/EXE.dir/cmake_clean.cmake
.PHONY : CMakeFiles/EXE.dir/clean

CMakeFiles/EXE.dir/depend:
	cd /Users/chengtai/Documents/2014/MOTR/modules/beta/beta && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chengtai/Documents/2014/MOTR/modules/beta/beta /Users/chengtai/Documents/2014/MOTR/modules/beta/beta /Users/chengtai/Documents/2014/MOTR/modules/beta/beta /Users/chengtai/Documents/2014/MOTR/modules/beta/beta /Users/chengtai/Documents/2014/MOTR/modules/beta/beta/CMakeFiles/EXE.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EXE.dir/depend

