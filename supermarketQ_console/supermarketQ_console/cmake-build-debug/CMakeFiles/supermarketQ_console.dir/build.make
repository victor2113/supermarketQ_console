# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CLionProjects\supermarketQ_console

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CLionProjects\supermarketQ_console\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\supermarketQ_console.dir\depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles\supermarketQ_console.dir\compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles\supermarketQ_console.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\supermarketQ_console.dir\flags.make

CMakeFiles\supermarketQ_console.dir\main.c.obj: CMakeFiles\supermarketQ_console.dir\flags.make
CMakeFiles\supermarketQ_console.dir\main.c.obj: ..\main.c
CMakeFiles\supermarketQ_console.dir\main.c.obj: CMakeFiles\supermarketQ_console.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\supermarketQ_console\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/supermarketQ_console.dir/main.c.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\supermarketQ_console.dir\main.c.obj.d --working-dir=D:\CLionProjects\supermarketQ_console\cmake-build-debug --filter-prefix="����������: ��������� �����:  " -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /showIncludes /FoCMakeFiles\supermarketQ_console.dir\main.c.obj /FdCMakeFiles\supermarketQ_console.dir\ /FS -c D:\CLionProjects\supermarketQ_console\main.c
<<

CMakeFiles\supermarketQ_console.dir\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/supermarketQ_console.dir/main.c.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\supermarketQ_console.dir\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\CLionProjects\supermarketQ_console\main.c
<<

CMakeFiles\supermarketQ_console.dir\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/supermarketQ_console.dir/main.c.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\supermarketQ_console.dir\main.c.s /c D:\CLionProjects\supermarketQ_console\main.c
<<

CMakeFiles\supermarketQ_console.dir\supermarket_q.c.obj: CMakeFiles\supermarketQ_console.dir\flags.make
CMakeFiles\supermarketQ_console.dir\supermarket_q.c.obj: ..\supermarket_q.c
CMakeFiles\supermarketQ_console.dir\supermarket_q.c.obj: CMakeFiles\supermarketQ_console.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\supermarketQ_console\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/supermarketQ_console.dir/supermarket_q.c.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\supermarketQ_console.dir\supermarket_q.c.obj.d --working-dir=D:\CLionProjects\supermarketQ_console\cmake-build-debug --filter-prefix="����������: ��������� �����:  " -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /showIncludes /FoCMakeFiles\supermarketQ_console.dir\supermarket_q.c.obj /FdCMakeFiles\supermarketQ_console.dir\ /FS -c D:\CLionProjects\supermarketQ_console\supermarket_q.c
<<

CMakeFiles\supermarketQ_console.dir\supermarket_q.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/supermarketQ_console.dir/supermarket_q.c.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\supermarketQ_console.dir\supermarket_q.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\CLionProjects\supermarketQ_console\supermarket_q.c
<<

CMakeFiles\supermarketQ_console.dir\supermarket_q.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/supermarketQ_console.dir/supermarket_q.c.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\supermarketQ_console.dir\supermarket_q.c.s /c D:\CLionProjects\supermarketQ_console\supermarket_q.c
<<

# Object files for target supermarketQ_console
supermarketQ_console_OBJECTS = \
"CMakeFiles\supermarketQ_console.dir\main.c.obj" \
"CMakeFiles\supermarketQ_console.dir\supermarket_q.c.obj"

# External object files for target supermarketQ_console
supermarketQ_console_EXTERNAL_OBJECTS =

supermarketQ_console.exe: CMakeFiles\supermarketQ_console.dir\main.c.obj
supermarketQ_console.exe: CMakeFiles\supermarketQ_console.dir\supermarket_q.c.obj
supermarketQ_console.exe: CMakeFiles\supermarketQ_console.dir\build.make
supermarketQ_console.exe: CMakeFiles\supermarketQ_console.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CLionProjects\supermarketQ_console\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable supermarketQ_console.exe"
	"D:\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\supermarketQ_console.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\supermarketQ_console.dir\objects1.rsp @<<
 /out:supermarketQ_console.exe /implib:supermarketQ_console.lib /pdb:D:\CLionProjects\supermarketQ_console\cmake-build-debug\supermarketQ_console.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\supermarketQ_console.dir\build: supermarketQ_console.exe
.PHONY : CMakeFiles\supermarketQ_console.dir\build

CMakeFiles\supermarketQ_console.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\supermarketQ_console.dir\cmake_clean.cmake
.PHONY : CMakeFiles\supermarketQ_console.dir\clean

CMakeFiles\supermarketQ_console.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\CLionProjects\supermarketQ_console D:\CLionProjects\supermarketQ_console D:\CLionProjects\supermarketQ_console\cmake-build-debug D:\CLionProjects\supermarketQ_console\cmake-build-debug D:\CLionProjects\supermarketQ_console\cmake-build-debug\CMakeFiles\supermarketQ_console.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\supermarketQ_console.dir\depend
