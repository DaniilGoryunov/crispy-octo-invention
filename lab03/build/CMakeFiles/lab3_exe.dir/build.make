# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.26.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.26.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/admin/Desktop/МАИ/второй/ооп/oop_labs/lab03

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/admin/Desktop/МАИ/второй/ооп/oop_labs/lab03/build

# Include any dependencies generated for this target.
include CMakeFiles/lab3_exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab3_exe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab3_exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab3_exe.dir/flags.make

CMakeFiles/lab3_exe.dir/main.cpp.o: CMakeFiles/lab3_exe.dir/flags.make
CMakeFiles/lab3_exe.dir/main.cpp.o: /Users/admin/Desktop/МАИ/второй/ооп/oop_labs/lab03/main.cpp
CMakeFiles/lab3_exe.dir/main.cpp.o: CMakeFiles/lab3_exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/admin/Desktop/МАИ/второй/ооп/oop_labs/lab03/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab3_exe.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab3_exe.dir/main.cpp.o -MF CMakeFiles/lab3_exe.dir/main.cpp.o.d -o CMakeFiles/lab3_exe.dir/main.cpp.o -c /Users/admin/Desktop/МАИ/второй/ооп/oop_labs/lab03/main.cpp

CMakeFiles/lab3_exe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab3_exe.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/admin/Desktop/МАИ/второй/ооп/oop_labs/lab03/main.cpp > CMakeFiles/lab3_exe.dir/main.cpp.i

CMakeFiles/lab3_exe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab3_exe.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/admin/Desktop/МАИ/второй/ооп/oop_labs/lab03/main.cpp -o CMakeFiles/lab3_exe.dir/main.cpp.s

# Object files for target lab3_exe
lab3_exe_OBJECTS = \
"CMakeFiles/lab3_exe.dir/main.cpp.o"

# External object files for target lab3_exe
lab3_exe_EXTERNAL_OBJECTS =

lab3_exe: CMakeFiles/lab3_exe.dir/main.cpp.o
lab3_exe: CMakeFiles/lab3_exe.dir/build.make
lab3_exe: liblab3_lib.a
lab3_exe: CMakeFiles/lab3_exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/admin/Desktop/МАИ/второй/ооп/oop_labs/lab03/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab3_exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab3_exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab3_exe.dir/build: lab3_exe
.PHONY : CMakeFiles/lab3_exe.dir/build

CMakeFiles/lab3_exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab3_exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab3_exe.dir/clean

CMakeFiles/lab3_exe.dir/depend:
	cd /Users/admin/Desktop/МАИ/второй/ооп/oop_labs/lab03/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/admin/Desktop/МАИ/второй/ооп/oop_labs/lab03 /Users/admin/Desktop/МАИ/второй/ооп/oop_labs/lab03 /Users/admin/Desktop/МАИ/второй/ооп/oop_labs/lab03/build /Users/admin/Desktop/МАИ/второй/ооп/oop_labs/lab03/build /Users/admin/Desktop/МАИ/второй/ооп/oop_labs/lab03/build/CMakeFiles/lab3_exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab3_exe.dir/depend

