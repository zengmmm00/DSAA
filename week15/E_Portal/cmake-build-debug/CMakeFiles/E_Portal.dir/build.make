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
CMAKE_SOURCE_DIR = D:\Users\DELL\CLionProjects\OJ\week15\E_Portal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Users\DELL\CLionProjects\OJ\week15\E_Portal\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/E_Portal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/E_Portal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/E_Portal.dir/flags.make

CMakeFiles/E_Portal.dir/main.cpp.obj: CMakeFiles/E_Portal.dir/flags.make
CMakeFiles/E_Portal.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Users\DELL\CLionProjects\OJ\week15\E_Portal\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/E_Portal.dir/main.cpp.obj"
	E:\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\E_Portal.dir\main.cpp.obj -c D:\Users\DELL\CLionProjects\OJ\week15\E_Portal\main.cpp

CMakeFiles/E_Portal.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/E_Portal.dir/main.cpp.i"
	E:\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Users\DELL\CLionProjects\OJ\week15\E_Portal\main.cpp > CMakeFiles\E_Portal.dir\main.cpp.i

CMakeFiles/E_Portal.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/E_Portal.dir/main.cpp.s"
	E:\x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Users\DELL\CLionProjects\OJ\week15\E_Portal\main.cpp -o CMakeFiles\E_Portal.dir\main.cpp.s

# Object files for target E_Portal
E_Portal_OBJECTS = \
"CMakeFiles/E_Portal.dir/main.cpp.obj"

# External object files for target E_Portal
E_Portal_EXTERNAL_OBJECTS =

E_Portal.exe: CMakeFiles/E_Portal.dir/main.cpp.obj
E_Portal.exe: CMakeFiles/E_Portal.dir/build.make
E_Portal.exe: CMakeFiles/E_Portal.dir/linklibs.rsp
E_Portal.exe: CMakeFiles/E_Portal.dir/objects1.rsp
E_Portal.exe: CMakeFiles/E_Portal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Users\DELL\CLionProjects\OJ\week15\E_Portal\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable E_Portal.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\E_Portal.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/E_Portal.dir/build: E_Portal.exe

.PHONY : CMakeFiles/E_Portal.dir/build

CMakeFiles/E_Portal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\E_Portal.dir\cmake_clean.cmake
.PHONY : CMakeFiles/E_Portal.dir/clean

CMakeFiles/E_Portal.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Users\DELL\CLionProjects\OJ\week15\E_Portal D:\Users\DELL\CLionProjects\OJ\week15\E_Portal D:\Users\DELL\CLionProjects\OJ\week15\E_Portal\cmake-build-debug D:\Users\DELL\CLionProjects\OJ\week15\E_Portal\cmake-build-debug D:\Users\DELL\CLionProjects\OJ\week15\E_Portal\cmake-build-debug\CMakeFiles\E_Portal.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/E_Portal.dir/depend

