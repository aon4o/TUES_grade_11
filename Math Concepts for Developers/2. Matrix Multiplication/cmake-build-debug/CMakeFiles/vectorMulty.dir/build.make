# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/alex/clion-2020.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/alex/clion-2020.2.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alex/Desktop/vectorMulty

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alex/Desktop/vectorMulty/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/vectorMulty.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/vectorMulty.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vectorMulty.dir/flags.make

CMakeFiles/vectorMulty.dir/main.cpp.o: CMakeFiles/vectorMulty.dir/flags.make
CMakeFiles/vectorMulty.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/Desktop/vectorMulty/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vectorMulty.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vectorMulty.dir/main.cpp.o -c /home/alex/Desktop/vectorMulty/main.cpp

CMakeFiles/vectorMulty.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vectorMulty.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/Desktop/vectorMulty/main.cpp > CMakeFiles/vectorMulty.dir/main.cpp.i

CMakeFiles/vectorMulty.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vectorMulty.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/Desktop/vectorMulty/main.cpp -o CMakeFiles/vectorMulty.dir/main.cpp.s

# Object files for target vectorMulty
vectorMulty_OBJECTS = \
"CMakeFiles/vectorMulty.dir/main.cpp.o"

# External object files for target vectorMulty
vectorMulty_EXTERNAL_OBJECTS =

vectorMulty: CMakeFiles/vectorMulty.dir/main.cpp.o
vectorMulty: CMakeFiles/vectorMulty.dir/build.make
vectorMulty: CMakeFiles/vectorMulty.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alex/Desktop/vectorMulty/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable vectorMulty"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vectorMulty.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vectorMulty.dir/build: vectorMulty

.PHONY : CMakeFiles/vectorMulty.dir/build

CMakeFiles/vectorMulty.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vectorMulty.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vectorMulty.dir/clean

CMakeFiles/vectorMulty.dir/depend:
	cd /home/alex/Desktop/vectorMulty/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/Desktop/vectorMulty /home/alex/Desktop/vectorMulty /home/alex/Desktop/vectorMulty/cmake-build-debug /home/alex/Desktop/vectorMulty/cmake-build-debug /home/alex/Desktop/vectorMulty/cmake-build-debug/CMakeFiles/vectorMulty.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vectorMulty.dir/depend
