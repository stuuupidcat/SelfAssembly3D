# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\Software\CMake\bin\cmake.exe

# The command to remove a file.
RM = D:\Software\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Workspace\workspace_c++\selfassembly

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Workspace\workspace_c++\selfassembly\build

# Include any dependencies generated for this target.
include CMakeFiles/SelfAssembly.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SelfAssembly.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SelfAssembly.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SelfAssembly.dir/flags.make

CMakeFiles/SelfAssembly.dir/main.cpp.obj: CMakeFiles/SelfAssembly.dir/flags.make
CMakeFiles/SelfAssembly.dir/main.cpp.obj: D:/Workspace/workspace_c++/selfassembly/main.cpp
CMakeFiles/SelfAssembly.dir/main.cpp.obj: CMakeFiles/SelfAssembly.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Workspace\workspace_c++\selfassembly\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SelfAssembly.dir/main.cpp.obj"
	D:\Software\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SelfAssembly.dir/main.cpp.obj -MF CMakeFiles\SelfAssembly.dir\main.cpp.obj.d -o CMakeFiles\SelfAssembly.dir\main.cpp.obj -c D:\Workspace\workspace_c++\selfassembly\main.cpp

CMakeFiles/SelfAssembly.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SelfAssembly.dir/main.cpp.i"
	D:\Software\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Workspace\workspace_c++\selfassembly\main.cpp > CMakeFiles\SelfAssembly.dir\main.cpp.i

CMakeFiles/SelfAssembly.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SelfAssembly.dir/main.cpp.s"
	D:\Software\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Workspace\workspace_c++\selfassembly\main.cpp -o CMakeFiles\SelfAssembly.dir\main.cpp.s

CMakeFiles/SelfAssembly.dir/src/grid.cpp.obj: CMakeFiles/SelfAssembly.dir/flags.make
CMakeFiles/SelfAssembly.dir/src/grid.cpp.obj: D:/Workspace/workspace_c++/selfassembly/src/grid.cpp
CMakeFiles/SelfAssembly.dir/src/grid.cpp.obj: CMakeFiles/SelfAssembly.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Workspace\workspace_c++\selfassembly\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SelfAssembly.dir/src/grid.cpp.obj"
	D:\Software\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SelfAssembly.dir/src/grid.cpp.obj -MF CMakeFiles\SelfAssembly.dir\src\grid.cpp.obj.d -o CMakeFiles\SelfAssembly.dir\src\grid.cpp.obj -c D:\Workspace\workspace_c++\selfassembly\src\grid.cpp

CMakeFiles/SelfAssembly.dir/src/grid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SelfAssembly.dir/src/grid.cpp.i"
	D:\Software\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Workspace\workspace_c++\selfassembly\src\grid.cpp > CMakeFiles\SelfAssembly.dir\src\grid.cpp.i

CMakeFiles/SelfAssembly.dir/src/grid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SelfAssembly.dir/src/grid.cpp.s"
	D:\Software\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Workspace\workspace_c++\selfassembly\src\grid.cpp -o CMakeFiles\SelfAssembly.dir\src\grid.cpp.s

CMakeFiles/SelfAssembly.dir/src/agent.cpp.obj: CMakeFiles/SelfAssembly.dir/flags.make
CMakeFiles/SelfAssembly.dir/src/agent.cpp.obj: D:/Workspace/workspace_c++/selfassembly/src/agent.cpp
CMakeFiles/SelfAssembly.dir/src/agent.cpp.obj: CMakeFiles/SelfAssembly.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Workspace\workspace_c++\selfassembly\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SelfAssembly.dir/src/agent.cpp.obj"
	D:\Software\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SelfAssembly.dir/src/agent.cpp.obj -MF CMakeFiles\SelfAssembly.dir\src\agent.cpp.obj.d -o CMakeFiles\SelfAssembly.dir\src\agent.cpp.obj -c D:\Workspace\workspace_c++\selfassembly\src\agent.cpp

CMakeFiles/SelfAssembly.dir/src/agent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SelfAssembly.dir/src/agent.cpp.i"
	D:\Software\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Workspace\workspace_c++\selfassembly\src\agent.cpp > CMakeFiles\SelfAssembly.dir\src\agent.cpp.i

CMakeFiles/SelfAssembly.dir/src/agent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SelfAssembly.dir/src/agent.cpp.s"
	D:\Software\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Workspace\workspace_c++\selfassembly\src\agent.cpp -o CMakeFiles\SelfAssembly.dir\src\agent.cpp.s

CMakeFiles/SelfAssembly.dir/src/coordinator.cpp.obj: CMakeFiles/SelfAssembly.dir/flags.make
CMakeFiles/SelfAssembly.dir/src/coordinator.cpp.obj: D:/Workspace/workspace_c++/selfassembly/src/coordinator.cpp
CMakeFiles/SelfAssembly.dir/src/coordinator.cpp.obj: CMakeFiles/SelfAssembly.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Workspace\workspace_c++\selfassembly\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SelfAssembly.dir/src/coordinator.cpp.obj"
	D:\Software\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SelfAssembly.dir/src/coordinator.cpp.obj -MF CMakeFiles\SelfAssembly.dir\src\coordinator.cpp.obj.d -o CMakeFiles\SelfAssembly.dir\src\coordinator.cpp.obj -c D:\Workspace\workspace_c++\selfassembly\src\coordinator.cpp

CMakeFiles/SelfAssembly.dir/src/coordinator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SelfAssembly.dir/src/coordinator.cpp.i"
	D:\Software\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Workspace\workspace_c++\selfassembly\src\coordinator.cpp > CMakeFiles\SelfAssembly.dir\src\coordinator.cpp.i

CMakeFiles/SelfAssembly.dir/src/coordinator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SelfAssembly.dir/src/coordinator.cpp.s"
	D:\Software\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Workspace\workspace_c++\selfassembly\src\coordinator.cpp -o CMakeFiles\SelfAssembly.dir\src\coordinator.cpp.s

CMakeFiles/SelfAssembly.dir/src/lightfield.cpp.obj: CMakeFiles/SelfAssembly.dir/flags.make
CMakeFiles/SelfAssembly.dir/src/lightfield.cpp.obj: D:/Workspace/workspace_c++/selfassembly/src/lightfield.cpp
CMakeFiles/SelfAssembly.dir/src/lightfield.cpp.obj: CMakeFiles/SelfAssembly.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Workspace\workspace_c++\selfassembly\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SelfAssembly.dir/src/lightfield.cpp.obj"
	D:\Software\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SelfAssembly.dir/src/lightfield.cpp.obj -MF CMakeFiles\SelfAssembly.dir\src\lightfield.cpp.obj.d -o CMakeFiles\SelfAssembly.dir\src\lightfield.cpp.obj -c D:\Workspace\workspace_c++\selfassembly\src\lightfield.cpp

CMakeFiles/SelfAssembly.dir/src/lightfield.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SelfAssembly.dir/src/lightfield.cpp.i"
	D:\Software\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Workspace\workspace_c++\selfassembly\src\lightfield.cpp > CMakeFiles\SelfAssembly.dir\src\lightfield.cpp.i

CMakeFiles/SelfAssembly.dir/src/lightfield.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SelfAssembly.dir/src/lightfield.cpp.s"
	D:\Software\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Workspace\workspace_c++\selfassembly\src\lightfield.cpp -o CMakeFiles\SelfAssembly.dir\src\lightfield.cpp.s

CMakeFiles/SelfAssembly.dir/src/position.cpp.obj: CMakeFiles/SelfAssembly.dir/flags.make
CMakeFiles/SelfAssembly.dir/src/position.cpp.obj: D:/Workspace/workspace_c++/selfassembly/src/position.cpp
CMakeFiles/SelfAssembly.dir/src/position.cpp.obj: CMakeFiles/SelfAssembly.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Workspace\workspace_c++\selfassembly\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SelfAssembly.dir/src/position.cpp.obj"
	D:\Software\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SelfAssembly.dir/src/position.cpp.obj -MF CMakeFiles\SelfAssembly.dir\src\position.cpp.obj.d -o CMakeFiles\SelfAssembly.dir\src\position.cpp.obj -c D:\Workspace\workspace_c++\selfassembly\src\position.cpp

CMakeFiles/SelfAssembly.dir/src/position.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SelfAssembly.dir/src/position.cpp.i"
	D:\Software\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Workspace\workspace_c++\selfassembly\src\position.cpp > CMakeFiles\SelfAssembly.dir\src\position.cpp.i

CMakeFiles/SelfAssembly.dir/src/position.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SelfAssembly.dir/src/position.cpp.s"
	D:\Software\Mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Workspace\workspace_c++\selfassembly\src\position.cpp -o CMakeFiles\SelfAssembly.dir\src\position.cpp.s

# Object files for target SelfAssembly
SelfAssembly_OBJECTS = \
"CMakeFiles/SelfAssembly.dir/main.cpp.obj" \
"CMakeFiles/SelfAssembly.dir/src/grid.cpp.obj" \
"CMakeFiles/SelfAssembly.dir/src/agent.cpp.obj" \
"CMakeFiles/SelfAssembly.dir/src/coordinator.cpp.obj" \
"CMakeFiles/SelfAssembly.dir/src/lightfield.cpp.obj" \
"CMakeFiles/SelfAssembly.dir/src/position.cpp.obj"

# External object files for target SelfAssembly
SelfAssembly_EXTERNAL_OBJECTS =

SelfAssembly.exe: CMakeFiles/SelfAssembly.dir/main.cpp.obj
SelfAssembly.exe: CMakeFiles/SelfAssembly.dir/src/grid.cpp.obj
SelfAssembly.exe: CMakeFiles/SelfAssembly.dir/src/agent.cpp.obj
SelfAssembly.exe: CMakeFiles/SelfAssembly.dir/src/coordinator.cpp.obj
SelfAssembly.exe: CMakeFiles/SelfAssembly.dir/src/lightfield.cpp.obj
SelfAssembly.exe: CMakeFiles/SelfAssembly.dir/src/position.cpp.obj
SelfAssembly.exe: CMakeFiles/SelfAssembly.dir/build.make
SelfAssembly.exe: CMakeFiles/SelfAssembly.dir/linklibs.rsp
SelfAssembly.exe: CMakeFiles/SelfAssembly.dir/objects1.rsp
SelfAssembly.exe: CMakeFiles/SelfAssembly.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Workspace\workspace_c++\selfassembly\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable SelfAssembly.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SelfAssembly.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SelfAssembly.dir/build: SelfAssembly.exe
.PHONY : CMakeFiles/SelfAssembly.dir/build

CMakeFiles/SelfAssembly.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SelfAssembly.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SelfAssembly.dir/clean

CMakeFiles/SelfAssembly.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Workspace\workspace_c++\selfassembly D:\Workspace\workspace_c++\selfassembly D:\Workspace\workspace_c++\selfassembly\build D:\Workspace\workspace_c++\selfassembly\build D:\Workspace\workspace_c++\selfassembly\build\CMakeFiles\SelfAssembly.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SelfAssembly.dir/depend
