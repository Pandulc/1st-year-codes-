# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Informatica II\Ejercicios 2do Semestre\Practico"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Informatica II\Ejercicios 2do Semestre\Practico\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Ejercicio_5p.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Ejercicio_5p.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ejercicio_5p.dir/flags.make

CMakeFiles/Ejercicio_5p.dir/Punteros/Ejercicio_5p.cpp.obj: CMakeFiles/Ejercicio_5p.dir/flags.make
CMakeFiles/Ejercicio_5p.dir/Punteros/Ejercicio_5p.cpp.obj: ../Punteros/Ejercicio_5p.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Informatica II\Ejercicios 2do Semestre\Practico\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Ejercicio_5p.dir/Punteros/Ejercicio_5p.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Ejercicio_5p.dir\Punteros\Ejercicio_5p.cpp.obj -c "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Informatica II\Ejercicios 2do Semestre\Practico\Punteros\Ejercicio_5p.cpp"

CMakeFiles/Ejercicio_5p.dir/Punteros/Ejercicio_5p.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ejercicio_5p.dir/Punteros/Ejercicio_5p.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Informatica II\Ejercicios 2do Semestre\Practico\Punteros\Ejercicio_5p.cpp" > CMakeFiles\Ejercicio_5p.dir\Punteros\Ejercicio_5p.cpp.i

CMakeFiles/Ejercicio_5p.dir/Punteros/Ejercicio_5p.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ejercicio_5p.dir/Punteros/Ejercicio_5p.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Informatica II\Ejercicios 2do Semestre\Practico\Punteros\Ejercicio_5p.cpp" -o CMakeFiles\Ejercicio_5p.dir\Punteros\Ejercicio_5p.cpp.s

# Object files for target Ejercicio_5p
Ejercicio_5p_OBJECTS = \
"CMakeFiles/Ejercicio_5p.dir/Punteros/Ejercicio_5p.cpp.obj"

# External object files for target Ejercicio_5p
Ejercicio_5p_EXTERNAL_OBJECTS =

Ejercicio_5p.exe: CMakeFiles/Ejercicio_5p.dir/Punteros/Ejercicio_5p.cpp.obj
Ejercicio_5p.exe: CMakeFiles/Ejercicio_5p.dir/build.make
Ejercicio_5p.exe: CMakeFiles/Ejercicio_5p.dir/linklibs.rsp
Ejercicio_5p.exe: CMakeFiles/Ejercicio_5p.dir/objects1.rsp
Ejercicio_5p.exe: CMakeFiles/Ejercicio_5p.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Informatica II\Ejercicios 2do Semestre\Practico\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Ejercicio_5p.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Ejercicio_5p.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ejercicio_5p.dir/build: Ejercicio_5p.exe
.PHONY : CMakeFiles/Ejercicio_5p.dir/build

CMakeFiles/Ejercicio_5p.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Ejercicio_5p.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Ejercicio_5p.dir/clean

CMakeFiles/Ejercicio_5p.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Informatica II\Ejercicios 2do Semestre\Practico" "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Informatica II\Ejercicios 2do Semestre\Practico" "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Informatica II\Ejercicios 2do Semestre\Practico\cmake-build-debug" "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Informatica II\Ejercicios 2do Semestre\Practico\cmake-build-debug" "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Informatica II\Ejercicios 2do Semestre\Practico\cmake-build-debug\CMakeFiles\Ejercicio_5p.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Ejercicio_5p.dir/depend

