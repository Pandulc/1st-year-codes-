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
CMAKE_SOURCE_DIR = "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Info II\Ejercicios 2do Semestre\Practico"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Info II\Ejercicios 2do Semestre\Practico\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Ejercicio_1p.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Ejercicio_1p.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ejercicio_1p.dir/flags.make

CMakeFiles/Ejercicio_1p.dir/Punteros/Ejercicio_1p.cpp.obj: CMakeFiles/Ejercicio_1p.dir/flags.make
CMakeFiles/Ejercicio_1p.dir/Punteros/Ejercicio_1p.cpp.obj: ../Punteros/Ejercicio_1p.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Info II\Ejercicios 2do Semestre\Practico\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Ejercicio_1p.dir/Punteros/Ejercicio_1p.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Ejercicio_1p.dir\Punteros\Ejercicio_1p.cpp.obj -c "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Info II\Ejercicios 2do Semestre\Practico\Punteros\Ejercicio_1p.cpp"

CMakeFiles/Ejercicio_1p.dir/Punteros/Ejercicio_1p.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ejercicio_1p.dir/Punteros/Ejercicio_1p.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Info II\Ejercicios 2do Semestre\Practico\Punteros\Ejercicio_1p.cpp" > CMakeFiles\Ejercicio_1p.dir\Punteros\Ejercicio_1p.cpp.i

CMakeFiles/Ejercicio_1p.dir/Punteros/Ejercicio_1p.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ejercicio_1p.dir/Punteros/Ejercicio_1p.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Info II\Ejercicios 2do Semestre\Practico\Punteros\Ejercicio_1p.cpp" -o CMakeFiles\Ejercicio_1p.dir\Punteros\Ejercicio_1p.cpp.s

# Object files for target Ejercicio_1p
Ejercicio_1p_OBJECTS = \
"CMakeFiles/Ejercicio_1p.dir/Punteros/Ejercicio_1p.cpp.obj"

# External object files for target Ejercicio_1p
Ejercicio_1p_EXTERNAL_OBJECTS =

Ejercicio_1p.exe: CMakeFiles/Ejercicio_1p.dir/Punteros/Ejercicio_1p.cpp.obj
Ejercicio_1p.exe: CMakeFiles/Ejercicio_1p.dir/build.make
Ejercicio_1p.exe: CMakeFiles/Ejercicio_1p.dir/linklibs.rsp
Ejercicio_1p.exe: CMakeFiles/Ejercicio_1p.dir/objects1.rsp
Ejercicio_1p.exe: CMakeFiles/Ejercicio_1p.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Info II\Ejercicios 2do Semestre\Practico\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Ejercicio_1p.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Ejercicio_1p.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ejercicio_1p.dir/build: Ejercicio_1p.exe
.PHONY : CMakeFiles/Ejercicio_1p.dir/build

CMakeFiles/Ejercicio_1p.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Ejercicio_1p.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Ejercicio_1p.dir/clean

CMakeFiles/Ejercicio_1p.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Info II\Ejercicios 2do Semestre\Practico" "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Info II\Ejercicios 2do Semestre\Practico" "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Info II\Ejercicios 2do Semestre\Practico\cmake-build-debug" "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Info II\Ejercicios 2do Semestre\Practico\cmake-build-debug" "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Info II\Ejercicios 2do Semestre\Practico\cmake-build-debug\CMakeFiles\Ejercicio_1p.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Ejercicio_1p.dir/depend

