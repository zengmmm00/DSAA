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
CMAKE_SOURCE_DIR = D:\Users\DELL\CLionProjects\OJ\week12\B_TheSwordofDamocles

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Users\DELL\CLionProjects\OJ\week12\B_TheSwordofDamocles\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/B_TheSwordofDamocles.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/B_TheSwordofDamocles.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/B_TheSwordofDamocles.dir/flags.make

CMakeFiles/B_TheSwordofDamocles.dir/main.cpp.obj: CMakeFiles/B_TheSwordofDamocles.dir/flags.make
CMakeFiles/B_TheSwordofDamocles.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Users\DELL\CLionProjects\OJ\week12\B_TheSwordofDamocles\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/B_TheSwordofDamocles.dir/main.cpp.obj"
	E:\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\B_TheSwordofDamocles.dir\main.cpp.obj -c D:\Users\DELL\CLionProjects\OJ\week12\B_TheSwordofDamocles\main.cpp

CMakeFiles/B_TheSwordofDamocles.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/B_TheSwordofDamocles.dir/main.cpp.i"
	E:\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Users\DELL\CLionProjects\OJ\week12\B_TheSwordofDamocles\main.cpp > CMakeFiles\B_TheSwordofDamocles.dir\main.cpp.i

CMakeFiles/B_TheSwordofDamocles.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/B_TheSwordofDamocles.dir/main.cpp.s"
	E:\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Users\DELL\CLionProjects\OJ\week12\B_TheSwordofDamocles\main.cpp -o CMakeFiles\B_TheSwordofDamocles.dir\main.cpp.s

# Object files for target B_TheSwordofDamocles
B_TheSwordofDamocles_OBJECTS = \
"CMakeFiles/B_TheSwordofDamocles.dir/main.cpp.obj"

# External object files for target B_TheSwordofDamocles
B_TheSwordofDamocles_EXTERNAL_OBJECTS =

B_TheSwordofDamocles.exe: CMakeFiles/B_TheSwordofDamocles.dir/main.cpp.obj
B_TheSwordofDamocles.exe: CMakeFiles/B_TheSwordofDamocles.dir/build.make
B_TheSwordofDamocles.exe: CMakeFiles/B_TheSwordofDamocles.dir/linklibs.rsp
B_TheSwordofDamocles.exe: CMakeFiles/B_TheSwordofDamocles.dir/objects1.rsp
B_TheSwordofDamocles.exe: CMakeFiles/B_TheSwordofDamocles.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Users\DELL\CLionProjects\OJ\week12\B_TheSwordofDamocles\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable B_TheSwordofDamocles.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\B_TheSwordofDamocles.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/B_TheSwordofDamocles.dir/build: B_TheSwordofDamocles.exe

.PHONY : CMakeFiles/B_TheSwordofDamocles.dir/build

CMakeFiles/B_TheSwordofDamocles.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\B_TheSwordofDamocles.dir\cmake_clean.cmake
.PHONY : CMakeFiles/B_TheSwordofDamocles.dir/clean

CMakeFiles/B_TheSwordofDamocles.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Users\DELL\CLionProjects\OJ\week12\B_TheSwordofDamocles D:\Users\DELL\CLionProjects\OJ\week12\B_TheSwordofDamocles D:\Users\DELL\CLionProjects\OJ\week12\B_TheSwordofDamocles\cmake-build-debug D:\Users\DELL\CLionProjects\OJ\week12\B_TheSwordofDamocles\cmake-build-debug D:\Users\DELL\CLionProjects\OJ\week12\B_TheSwordofDamocles\cmake-build-debug\CMakeFiles\B_TheSwordofDamocles.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/B_TheSwordofDamocles.dir/depend

