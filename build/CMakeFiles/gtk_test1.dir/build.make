# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zadock/projects/Gtk_test1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zadock/projects/Gtk_test1/build

# Include any dependencies generated for this target.
include CMakeFiles/gtk_test1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gtk_test1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gtk_test1.dir/flags.make

CMakeFiles/gtk_test1.dir/main.cpp.o: CMakeFiles/gtk_test1.dir/flags.make
CMakeFiles/gtk_test1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zadock/projects/Gtk_test1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gtk_test1.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtk_test1.dir/main.cpp.o -c /home/zadock/projects/Gtk_test1/main.cpp

CMakeFiles/gtk_test1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtk_test1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zadock/projects/Gtk_test1/main.cpp > CMakeFiles/gtk_test1.dir/main.cpp.i

CMakeFiles/gtk_test1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtk_test1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zadock/projects/Gtk_test1/main.cpp -o CMakeFiles/gtk_test1.dir/main.cpp.s

# Object files for target gtk_test1
gtk_test1_OBJECTS = \
"CMakeFiles/gtk_test1.dir/main.cpp.o"

# External object files for target gtk_test1
gtk_test1_EXTERNAL_OBJECTS =

gtk_test1: CMakeFiles/gtk_test1.dir/main.cpp.o
gtk_test1: CMakeFiles/gtk_test1.dir/build.make
gtk_test1: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
gtk_test1: /usr/lib/x86_64-linux-gnu/libsfml-audio.so.2.5.1
gtk_test1: /usr/lib/x86_64-linux-gnu/libsfml-network.so.2.5.1
gtk_test1: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
gtk_test1: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
gtk_test1: CMakeFiles/gtk_test1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zadock/projects/Gtk_test1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gtk_test1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtk_test1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gtk_test1.dir/build: gtk_test1

.PHONY : CMakeFiles/gtk_test1.dir/build

CMakeFiles/gtk_test1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gtk_test1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gtk_test1.dir/clean

CMakeFiles/gtk_test1.dir/depend:
	cd /home/zadock/projects/Gtk_test1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zadock/projects/Gtk_test1 /home/zadock/projects/Gtk_test1 /home/zadock/projects/Gtk_test1/build /home/zadock/projects/Gtk_test1/build /home/zadock/projects/Gtk_test1/build/CMakeFiles/gtk_test1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gtk_test1.dir/depend
