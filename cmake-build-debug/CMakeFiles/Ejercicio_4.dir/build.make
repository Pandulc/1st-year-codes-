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
include CMakeFiles/Ejercicio_4.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Ejercicio_4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ejercicio_4.dir/flags.make

CMakeFiles/Ejercicio_4.dir/Archivos/Ejercicio_4.cpp.obj: CMakeFiles/Ejercicio_4.dir/flags.make
CMakeFiles/Ejercicio_4.dir/Archivos/Ejercicio_4.cpp.obj: ../Archivos/Ejercicio_4.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Info II\Ejercicios 2do Semestre\Practico\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Ejercicio_4.dir/Archivos/Ejercicio_4.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Ejercicio_4.dir\Archivos\Ejercicio_4.cpp.obj -c "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Info II\Ejercicios 2do Semestre\Practico\Archivos\Ejercicio_4.cpp"

CMakeFiles/Ejercicio_4.dir/Archivos/Ejercicio_4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ejercicio_4.dir/Archivos/Ejercicio_4.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Info II\Ejercicios 2do Semestre\Practico\Archivos\Ejercicio_4.cpp" > CMakeFiles\Ejercicio_4.dir\Archivos\Ejercicio_4.cpp.i

CMakeFiles/Ejercicio_4.dir/Archivos/Ejercicio_4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ejercicio_4.dir/Archivos/Ejercicio_4.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Info II\Ejercicios 2do Semestre\Practico\Archivos\Ejercicio_4.cpp" -o CMakeFiles\Ejercicio_4.dir\Archivos\Ejercicio_4.cpp.s

# Object files for target Ejercicio_4
Ejercicio_4_OBJECTS = \
"CMakeFiles/Ejercicio_4.dir/Archivos/Ejercicio_4.cpp.obj"

# External object files for target Ejercicio_4
Ejercicio_4_EXTERNAL_OBJECTS =

Ejercicio_4.exe: CMakeFiles/Ejercicio_4.dir/Archivos/Ejercicio_4.cpp.obj
Ejercicio_4.exe: CMakeFiles/Ejercicio_4.dir/build.make
Ejercicio_4.exe: CMakeFiles/Ejercicio_4.dir/linklibs.rsp
Ejercicio_4.exe: CMakeFiles/Ejercicio_4.dir/objects1.rsp
Ejercicio_4.exe: CMakeFiles/Ejercicio_4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Info II\Ejercicios 2do Semestre\Practico\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Ejercicio_4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Ejercicio_4.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ejercicio_4.dir/build: Ejercicio_4.exe
.PHONY : CMakeFiles/Ejercicio_4.dir/build

CMakeFiles/Ejercicio_4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Ejercicio_4.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Ejercicio_4.dir/clean

CMakeFiles/Ejercicio_4.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Info II\Ejercicios 2do Semestre\Practico" "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Info II\Ejercicios 2do Semestre\Practico" "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Info II\Ejercicios 2do Semestre\Practico\cmake-build-debug" "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Info II\Ejercicios 2do Semestre\Practico\cmake-build-debug" "C:\Users\usuario\Desktop\Gabi\Facultad\1er anio\Segundo Semestre\Info II\Ejercicios 2do Semestre\Practico\cmake-build-debug\CMakeFiles\Ejercicio_4.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Ejercicio_4.dir/depend

