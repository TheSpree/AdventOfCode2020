# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "G:\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "G:\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\olivi\Documents\ING2\CPP\advent_learn

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\olivi\Documents\ING2\CPP\advent_learn\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/advent_learn.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/advent_learn.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/advent_learn.dir/flags.make

CMakeFiles/advent_learn.dir/main.cpp.obj: CMakeFiles/advent_learn.dir/flags.make
CMakeFiles/advent_learn.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\olivi\Documents\ING2\CPP\advent_learn\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/advent_learn.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\advent_learn.dir\main.cpp.obj -c C:\Users\olivi\Documents\ING2\CPP\advent_learn\main.cpp

CMakeFiles/advent_learn.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/advent_learn.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\olivi\Documents\ING2\CPP\advent_learn\main.cpp > CMakeFiles\advent_learn.dir\main.cpp.i

CMakeFiles/advent_learn.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/advent_learn.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\olivi\Documents\ING2\CPP\advent_learn\main.cpp -o CMakeFiles\advent_learn.dir\main.cpp.s

CMakeFiles/advent_learn.dir/day11.cpp.obj: CMakeFiles/advent_learn.dir/flags.make
CMakeFiles/advent_learn.dir/day11.cpp.obj: ../day11.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\olivi\Documents\ING2\CPP\advent_learn\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/advent_learn.dir/day11.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\advent_learn.dir\day11.cpp.obj -c C:\Users\olivi\Documents\ING2\CPP\advent_learn\day11.cpp

CMakeFiles/advent_learn.dir/day11.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/advent_learn.dir/day11.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\olivi\Documents\ING2\CPP\advent_learn\day11.cpp > CMakeFiles\advent_learn.dir\day11.cpp.i

CMakeFiles/advent_learn.dir/day11.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/advent_learn.dir/day11.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\olivi\Documents\ING2\CPP\advent_learn\day11.cpp -o CMakeFiles\advent_learn.dir\day11.cpp.s

# Object files for target advent_learn
advent_learn_OBJECTS = \
"CMakeFiles/advent_learn.dir/main.cpp.obj" \
"CMakeFiles/advent_learn.dir/day11.cpp.obj"

# External object files for target advent_learn
advent_learn_EXTERNAL_OBJECTS =

advent_learn.exe: CMakeFiles/advent_learn.dir/main.cpp.obj
advent_learn.exe: CMakeFiles/advent_learn.dir/day11.cpp.obj
advent_learn.exe: CMakeFiles/advent_learn.dir/build.make
advent_learn.exe: CMakeFiles/advent_learn.dir/linklibs.rsp
advent_learn.exe: CMakeFiles/advent_learn.dir/objects1.rsp
advent_learn.exe: CMakeFiles/advent_learn.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\olivi\Documents\ING2\CPP\advent_learn\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable advent_learn.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\advent_learn.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/advent_learn.dir/build: advent_learn.exe

.PHONY : CMakeFiles/advent_learn.dir/build

CMakeFiles/advent_learn.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\advent_learn.dir\cmake_clean.cmake
.PHONY : CMakeFiles/advent_learn.dir/clean

CMakeFiles/advent_learn.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\olivi\Documents\ING2\CPP\advent_learn C:\Users\olivi\Documents\ING2\CPP\advent_learn C:\Users\olivi\Documents\ING2\CPP\advent_learn\cmake-build-debug C:\Users\olivi\Documents\ING2\CPP\advent_learn\cmake-build-debug C:\Users\olivi\Documents\ING2\CPP\advent_learn\cmake-build-debug\CMakeFiles\advent_learn.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/advent_learn.dir/depend

