# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = C:\JetBrains\apps\CLion\ch-0\231.8770.66\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\JetBrains\apps\CLion\ch-0\231.8770.66\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\2156153\CLionProjects\xml-parser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\2156153\CLionProjects\xml-parser\cmake-build-debug

# Include any dependencies generated for this target.
include exec/CMakeFiles/demo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include exec/CMakeFiles/demo.dir/compiler_depend.make

# Include the progress variables for this target.
include exec/CMakeFiles/demo.dir/progress.make

# Include the compile flags for this target's objects.
include exec/CMakeFiles/demo.dir/flags.make

exec/CMakeFiles/demo.dir/main.c.obj: exec/CMakeFiles/demo.dir/flags.make
exec/CMakeFiles/demo.dir/main.c.obj: exec/CMakeFiles/demo.dir/includes_C.rsp
exec/CMakeFiles/demo.dir/main.c.obj: C:/Users/2156153/CLionProjects/xml-parser/exec/main.c
exec/CMakeFiles/demo.dir/main.c.obj: exec/CMakeFiles/demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\2156153\CLionProjects\xml-parser\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object exec/CMakeFiles/demo.dir/main.c.obj"
	cd /d C:\Users\2156153\CLionProjects\xml-parser\cmake-build-debug\exec && C:\JetBrains\apps\CLion\ch-0\231.8770.66\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT exec/CMakeFiles/demo.dir/main.c.obj -MF CMakeFiles\demo.dir\main.c.obj.d -o CMakeFiles\demo.dir\main.c.obj -c C:\Users\2156153\CLionProjects\xml-parser\exec\main.c

exec/CMakeFiles/demo.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/demo.dir/main.c.i"
	cd /d C:\Users\2156153\CLionProjects\xml-parser\cmake-build-debug\exec && C:\JetBrains\apps\CLion\ch-0\231.8770.66\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\2156153\CLionProjects\xml-parser\exec\main.c > CMakeFiles\demo.dir\main.c.i

exec/CMakeFiles/demo.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/demo.dir/main.c.s"
	cd /d C:\Users\2156153\CLionProjects\xml-parser\cmake-build-debug\exec && C:\JetBrains\apps\CLion\ch-0\231.8770.66\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\2156153\CLionProjects\xml-parser\exec\main.c -o CMakeFiles\demo.dir\main.c.s

# Object files for target demo
demo_OBJECTS = \
"CMakeFiles/demo.dir/main.c.obj"

# External object files for target demo
demo_EXTERNAL_OBJECTS =

exec/demo.exe: exec/CMakeFiles/demo.dir/main.c.obj
exec/demo.exe: exec/CMakeFiles/demo.dir/build.make
exec/demo.exe: lib/libxml.a
exec/demo.exe: exec/CMakeFiles/demo.dir/linkLibs.rsp
exec/demo.exe: exec/CMakeFiles/demo.dir/objects1
exec/demo.exe: exec/CMakeFiles/demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\2156153\CLionProjects\xml-parser\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable demo.exe"
	cd /d C:\Users\2156153\CLionProjects\xml-parser\cmake-build-debug\exec && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\demo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
exec/CMakeFiles/demo.dir/build: exec/demo.exe
.PHONY : exec/CMakeFiles/demo.dir/build

exec/CMakeFiles/demo.dir/clean:
	cd /d C:\Users\2156153\CLionProjects\xml-parser\cmake-build-debug\exec && $(CMAKE_COMMAND) -P CMakeFiles\demo.dir\cmake_clean.cmake
.PHONY : exec/CMakeFiles/demo.dir/clean

exec/CMakeFiles/demo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\2156153\CLionProjects\xml-parser C:\Users\2156153\CLionProjects\xml-parser\exec C:\Users\2156153\CLionProjects\xml-parser\cmake-build-debug C:\Users\2156153\CLionProjects\xml-parser\cmake-build-debug\exec C:\Users\2156153\CLionProjects\xml-parser\cmake-build-debug\exec\CMakeFiles\demo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : exec/CMakeFiles/demo.dir/depend

