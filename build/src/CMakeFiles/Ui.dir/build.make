# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/roccoferrante/Dropbox/Coding/C++/SmashGnCreator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/roccoferrante/Dropbox/Coding/C++/SmashGnCreator/build

# Include any dependencies generated for this target.
include src/CMakeFiles/Ui.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Ui.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Ui.dir/flags.make

src/CMakeFiles/Ui.dir/fltkDrawTableInfo.cpp.o: src/CMakeFiles/Ui.dir/flags.make
src/CMakeFiles/Ui.dir/fltkDrawTableInfo.cpp.o: ../src/fltkDrawTableInfo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/roccoferrante/Dropbox/Coding/C++/SmashGnCreator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/Ui.dir/fltkDrawTableInfo.cpp.o"
	cd /Users/roccoferrante/Dropbox/Coding/C++/SmashGnCreator/build/src && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ui.dir/fltkDrawTableInfo.cpp.o -c /Users/roccoferrante/Dropbox/Coding/C++/SmashGnCreator/src/fltkDrawTableInfo.cpp

src/CMakeFiles/Ui.dir/fltkDrawTableInfo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ui.dir/fltkDrawTableInfo.cpp.i"
	cd /Users/roccoferrante/Dropbox/Coding/C++/SmashGnCreator/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/roccoferrante/Dropbox/Coding/C++/SmashGnCreator/src/fltkDrawTableInfo.cpp > CMakeFiles/Ui.dir/fltkDrawTableInfo.cpp.i

src/CMakeFiles/Ui.dir/fltkDrawTableInfo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ui.dir/fltkDrawTableInfo.cpp.s"
	cd /Users/roccoferrante/Dropbox/Coding/C++/SmashGnCreator/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/roccoferrante/Dropbox/Coding/C++/SmashGnCreator/src/fltkDrawTableInfo.cpp -o CMakeFiles/Ui.dir/fltkDrawTableInfo.cpp.s

# Object files for target Ui
Ui_OBJECTS = \
"CMakeFiles/Ui.dir/fltkDrawTableInfo.cpp.o"

# External object files for target Ui
Ui_EXTERNAL_OBJECTS =

src/libUi.a: src/CMakeFiles/Ui.dir/fltkDrawTableInfo.cpp.o
src/libUi.a: src/CMakeFiles/Ui.dir/build.make
src/libUi.a: src/CMakeFiles/Ui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/roccoferrante/Dropbox/Coding/C++/SmashGnCreator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libUi.a"
	cd /Users/roccoferrante/Dropbox/Coding/C++/SmashGnCreator/build/src && $(CMAKE_COMMAND) -P CMakeFiles/Ui.dir/cmake_clean_target.cmake
	cd /Users/roccoferrante/Dropbox/Coding/C++/SmashGnCreator/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Ui.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/Ui.dir/build: src/libUi.a

.PHONY : src/CMakeFiles/Ui.dir/build

src/CMakeFiles/Ui.dir/clean:
	cd /Users/roccoferrante/Dropbox/Coding/C++/SmashGnCreator/build/src && $(CMAKE_COMMAND) -P CMakeFiles/Ui.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/Ui.dir/clean

src/CMakeFiles/Ui.dir/depend:
	cd /Users/roccoferrante/Dropbox/Coding/C++/SmashGnCreator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/roccoferrante/Dropbox/Coding/C++/SmashGnCreator /Users/roccoferrante/Dropbox/Coding/C++/SmashGnCreator/src /Users/roccoferrante/Dropbox/Coding/C++/SmashGnCreator/build /Users/roccoferrante/Dropbox/Coding/C++/SmashGnCreator/build/src /Users/roccoferrante/Dropbox/Coding/C++/SmashGnCreator/build/src/CMakeFiles/Ui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/Ui.dir/depend
