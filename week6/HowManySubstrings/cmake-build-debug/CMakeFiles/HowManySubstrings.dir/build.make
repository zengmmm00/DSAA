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
CMAKE_SOURCE_DIR = D:\Users\DELL\CLionProjects\OJ\week6\HowManySubstrings

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Users\DELL\CLionProjects\OJ\week6\HowManySubstrings\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HowManySubstrings.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HowManySubstrings.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HowManySubstrings.dir/flags.make

CMakeFiles/HowManySubstrings.dir/main.cpp.obj: CMakeFiles/HowManySubstrings.dir/flags.make
CMakeFiles/HowManySubstrings.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Users\DELL\CLionProjects\OJ\week6\HowManySubstrings\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HowManySubstrings.dir/main.cpp.obj"
	E:\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\HowManySubstrings.dir\main.cpp.obj -c D:\Users\DELL\CLionProjects\OJ\week6\HowManySubstrings\main.cpp

CMakeFiles/HowManySubstrings.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HowManySubstrings.dir/main.cpp.i"
	E:\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Users\DELL\CLionProjects\OJ\week6\HowManySubstrings\main.cpp > CMakeFiles\HowManySubstrings.dir\main.cpp.i

CMakeFiles/HowManySubstrings.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HowManySubstrings.dir/main.cpp.s"
	E:\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Users\DELL\CLionProjects\OJ\week6\HowManySubstrings\main.cpp -o CMakeFiles\HowManySubstrings.dir\main.cpp.s

# Object files for target HowManySubstrings
HowManySubstrings_OBJECTS = \
"CMakeFiles/HowManySubstrings.dir/main.cpp.obj"

# External object files for target HowManySubstrings
HowManySubstrings_EXTERNAL_OBJECTS =

HowManySubstrings.exe: CMakeFiles/HowManySubstrings.dir/main.cpp.obj
HowManySubstrings.exe: CMakeFiles/HowManySubstrings.dir/build.make
HowManySubstrings.exe: CMakeFiles/HowManySubstrings.dir/linklibs.rsp
HowManySubstrings.exe: CMakeFiles/HowManySubstrings.dir/objects1.rsp
HowManySubstrings.exe: CMakeFiles/HowManySubstrings.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Users\DELL\CLionProjects\OJ\week6\HowManySubstrings\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HowManySubstrings.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\HowManySubstrings.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HowManySubstrings.dir/build: HowManySubstrings.exe

.PHONY : CMakeFiles/HowManySubstrings.dir/build

CMakeFiles/HowManySubstrings.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\HowManySubstrings.dir\cmake_clean.cmake
.PHONY : CMakeFiles/HowManySubstrings.dir/clean

CMakeFiles/HowManySubstrings.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Users\DELL\CLionProjects\OJ\week6\HowManySubstrings D:\Users\DELL\CLionProjects\OJ\week6\HowManySubstrings D:\Users\DELL\CLionProjects\OJ\week6\HowManySubstrings\cmake-build-debug D:\Users\DELL\CLionProjects\OJ\week6\HowManySubstrings\cmake-build-debug D:\Users\DELL\CLionProjects\OJ\week6\HowManySubstrings\cmake-build-debug\CMakeFiles\HowManySubstrings.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HowManySubstrings.dir/depend

