# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\Program Files\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\Program Files\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Users\DELL\CLionProjects\OJ\week12\D_DefensiveTower

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Users\DELL\CLionProjects\OJ\week12\D_DefensiveTower\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/D_DefensiveTower.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/D_DefensiveTower.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/D_DefensiveTower.dir/flags.make

CMakeFiles/D_DefensiveTower.dir/main.cpp.obj: CMakeFiles/D_DefensiveTower.dir/flags.make
CMakeFiles/D_DefensiveTower.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Users\DELL\CLionProjects\OJ\week12\D_DefensiveTower\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/D_DefensiveTower.dir/main.cpp.obj"
	E:\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\D_DefensiveTower.dir\main.cpp.obj -c D:\Users\DELL\CLionProjects\OJ\week12\D_DefensiveTower\main.cpp

CMakeFiles/D_DefensiveTower.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/D_DefensiveTower.dir/main.cpp.i"
	E:\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Users\DELL\CLionProjects\OJ\week12\D_DefensiveTower\main.cpp > CMakeFiles\D_DefensiveTower.dir\main.cpp.i

CMakeFiles/D_DefensiveTower.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/D_DefensiveTower.dir/main.cpp.s"
	E:\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Users\DELL\CLionProjects\OJ\week12\D_DefensiveTower\main.cpp -o CMakeFiles\D_DefensiveTower.dir\main.cpp.s

# Object files for target D_DefensiveTower
D_DefensiveTower_OBJECTS = \
"CMakeFiles/D_DefensiveTower.dir/main.cpp.obj"

# External object files for target D_DefensiveTower
D_DefensiveTower_EXTERNAL_OBJECTS =

D_DefensiveTower.exe: CMakeFiles/D_DefensiveTower.dir/main.cpp.obj
D_DefensiveTower.exe: CMakeFiles/D_DefensiveTower.dir/build.make
D_DefensiveTower.exe: CMakeFiles/D_DefensiveTower.dir/linklibs.rsp
D_DefensiveTower.exe: CMakeFiles/D_DefensiveTower.dir/objects1.rsp
D_DefensiveTower.exe: CMakeFiles/D_DefensiveTower.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Users\DELL\CLionProjects\OJ\week12\D_DefensiveTower\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable D_DefensiveTower.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\D_DefensiveTower.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/D_DefensiveTower.dir/build: D_DefensiveTower.exe

.PHONY : CMakeFiles/D_DefensiveTower.dir/build

CMakeFiles/D_DefensiveTower.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\D_DefensiveTower.dir\cmake_clean.cmake
.PHONY : CMakeFiles/D_DefensiveTower.dir/clean

CMakeFiles/D_DefensiveTower.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Users\DELL\CLionProjects\OJ\week12\D_DefensiveTower D:\Users\DELL\CLionProjects\OJ\week12\D_DefensiveTower D:\Users\DELL\CLionProjects\OJ\week12\D_DefensiveTower\cmake-build-debug D:\Users\DELL\CLionProjects\OJ\week12\D_DefensiveTower\cmake-build-debug D:\Users\DELL\CLionProjects\OJ\week12\D_DefensiveTower\cmake-build-debug\CMakeFiles\D_DefensiveTower.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/D_DefensiveTower.dir/depend
