# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = C:\Angaev\CppDistro\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\Angaev\CppDistro\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Angaev\Dijkstra

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Angaev\Dijkstra

# Include any dependencies generated for this target.
include 1/CMakeFiles/1.dir/depend.make

# Include the progress variables for this target.
include 1/CMakeFiles/1.dir/progress.make

# Include the compile flags for this target's objects.
include 1/CMakeFiles/1.dir/flags.make

1/CMakeFiles/1.dir/main.cpp.obj: 1/CMakeFiles/1.dir/flags.make
1/CMakeFiles/1.dir/main.cpp.obj: 1/CMakeFiles/1.dir/includes_CXX.rsp
1/CMakeFiles/1.dir/main.cpp.obj: 1/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Angaev\Dijkstra\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 1/CMakeFiles/1.dir/main.cpp.obj"
	cd /d C:\Angaev\Dijkstra\1 && C:\Angaev\CppDistro\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\1.dir\main.cpp.obj -c C:\Angaev\Dijkstra\1\main.cpp

1/CMakeFiles/1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1.dir/main.cpp.i"
	cd /d C:\Angaev\Dijkstra\1 && C:\Angaev\CppDistro\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Angaev\Dijkstra\1\main.cpp > CMakeFiles\1.dir\main.cpp.i

1/CMakeFiles/1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1.dir/main.cpp.s"
	cd /d C:\Angaev\Dijkstra\1 && C:\Angaev\CppDistro\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Angaev\Dijkstra\1\main.cpp -o CMakeFiles\1.dir\main.cpp.s

1/CMakeFiles/1.dir/main.cpp.obj.requires:

.PHONY : 1/CMakeFiles/1.dir/main.cpp.obj.requires

1/CMakeFiles/1.dir/main.cpp.obj.provides: 1/CMakeFiles/1.dir/main.cpp.obj.requires
	$(MAKE) -f 1\CMakeFiles\1.dir\build.make 1/CMakeFiles/1.dir/main.cpp.obj.provides.build
.PHONY : 1/CMakeFiles/1.dir/main.cpp.obj.provides

1/CMakeFiles/1.dir/main.cpp.obj.provides.build: 1/CMakeFiles/1.dir/main.cpp.obj


# Object files for target 1
1_OBJECTS = \
"CMakeFiles/1.dir/main.cpp.obj"

# External object files for target 1
1_EXTERNAL_OBJECTS =

1/1.exe: 1/CMakeFiles/1.dir/main.cpp.obj
1/1.exe: 1/CMakeFiles/1.dir/build.make
1/1.exe: C:/Angaev/CppDistro/MinGW/lib/libsfml-window-s.a
1/1.exe: C:/Angaev/CppDistro/MinGW/lib/libsfml-graphics-s.a
1/1.exe: C:/Angaev/CppDistro/MinGW/lib/libsfml-system-s.a
1/1.exe: C:/Angaev/CppDistro/MinGW/lib/libfreetype.a
1/1.exe: C:/Angaev/CppDistro/MinGW/lib/libjpeg.a
1/1.exe: 1/CMakeFiles/1.dir/linklibs.rsp
1/1.exe: 1/CMakeFiles/1.dir/objects1.rsp
1/1.exe: 1/CMakeFiles/1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Angaev\Dijkstra\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1.exe"
	cd /d C:\Angaev\Dijkstra\1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
1/CMakeFiles/1.dir/build: 1/1.exe

.PHONY : 1/CMakeFiles/1.dir/build

1/CMakeFiles/1.dir/requires: 1/CMakeFiles/1.dir/main.cpp.obj.requires

.PHONY : 1/CMakeFiles/1.dir/requires

1/CMakeFiles/1.dir/clean:
	cd /d C:\Angaev\Dijkstra\1 && $(CMAKE_COMMAND) -P CMakeFiles\1.dir\cmake_clean.cmake
.PHONY : 1/CMakeFiles/1.dir/clean

1/CMakeFiles/1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Angaev\Dijkstra C:\Angaev\Dijkstra\1 C:\Angaev\Dijkstra C:\Angaev\Dijkstra\1 C:\Angaev\Dijkstra\1\CMakeFiles\1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : 1/CMakeFiles/1.dir/depend

