# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lbagg/Desktop/WebServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lbagg/Desktop/WebServer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/WebServer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/WebServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WebServer.dir/flags.make

CMakeFiles/WebServer.dir/main.cpp.o: CMakeFiles/WebServer.dir/flags.make
CMakeFiles/WebServer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lbagg/Desktop/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WebServer.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WebServer.dir/main.cpp.o -c /Users/lbagg/Desktop/WebServer/main.cpp

CMakeFiles/WebServer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lbagg/Desktop/WebServer/main.cpp > CMakeFiles/WebServer.dir/main.cpp.i

CMakeFiles/WebServer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lbagg/Desktop/WebServer/main.cpp -o CMakeFiles/WebServer.dir/main.cpp.s

CMakeFiles/WebServer.dir/CGI/CGI.cpp.o: CMakeFiles/WebServer.dir/flags.make
CMakeFiles/WebServer.dir/CGI/CGI.cpp.o: ../CGI/CGI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lbagg/Desktop/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/WebServer.dir/CGI/CGI.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WebServer.dir/CGI/CGI.cpp.o -c /Users/lbagg/Desktop/WebServer/CGI/CGI.cpp

CMakeFiles/WebServer.dir/CGI/CGI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/CGI/CGI.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lbagg/Desktop/WebServer/CGI/CGI.cpp > CMakeFiles/WebServer.dir/CGI/CGI.cpp.i

CMakeFiles/WebServer.dir/CGI/CGI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/CGI/CGI.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lbagg/Desktop/WebServer/CGI/CGI.cpp -o CMakeFiles/WebServer.dir/CGI/CGI.cpp.s

CMakeFiles/WebServer.dir/CGI/mainCGI.cpp.o: CMakeFiles/WebServer.dir/flags.make
CMakeFiles/WebServer.dir/CGI/mainCGI.cpp.o: ../CGI/mainCGI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lbagg/Desktop/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/WebServer.dir/CGI/mainCGI.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WebServer.dir/CGI/mainCGI.cpp.o -c /Users/lbagg/Desktop/WebServer/CGI/mainCGI.cpp

CMakeFiles/WebServer.dir/CGI/mainCGI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/CGI/mainCGI.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lbagg/Desktop/WebServer/CGI/mainCGI.cpp > CMakeFiles/WebServer.dir/CGI/mainCGI.cpp.i

CMakeFiles/WebServer.dir/CGI/mainCGI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/CGI/mainCGI.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lbagg/Desktop/WebServer/CGI/mainCGI.cpp -o CMakeFiles/WebServer.dir/CGI/mainCGI.cpp.s

CMakeFiles/WebServer.dir/ConfigParser/ConfigParser.cpp.o: CMakeFiles/WebServer.dir/flags.make
CMakeFiles/WebServer.dir/ConfigParser/ConfigParser.cpp.o: ../ConfigParser/ConfigParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lbagg/Desktop/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/WebServer.dir/ConfigParser/ConfigParser.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WebServer.dir/ConfigParser/ConfigParser.cpp.o -c /Users/lbagg/Desktop/WebServer/ConfigParser/ConfigParser.cpp

CMakeFiles/WebServer.dir/ConfigParser/ConfigParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/ConfigParser/ConfigParser.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lbagg/Desktop/WebServer/ConfigParser/ConfigParser.cpp > CMakeFiles/WebServer.dir/ConfigParser/ConfigParser.cpp.i

CMakeFiles/WebServer.dir/ConfigParser/ConfigParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/ConfigParser/ConfigParser.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lbagg/Desktop/WebServer/ConfigParser/ConfigParser.cpp -o CMakeFiles/WebServer.dir/ConfigParser/ConfigParser.cpp.s

CMakeFiles/WebServer.dir/Server.cpp.o: CMakeFiles/WebServer.dir/flags.make
CMakeFiles/WebServer.dir/Server.cpp.o: ../Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lbagg/Desktop/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/WebServer.dir/Server.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WebServer.dir/Server.cpp.o -c /Users/lbagg/Desktop/WebServer/Server.cpp

CMakeFiles/WebServer.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/Server.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lbagg/Desktop/WebServer/Server.cpp > CMakeFiles/WebServer.dir/Server.cpp.i

CMakeFiles/WebServer.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/Server.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lbagg/Desktop/WebServer/Server.cpp -o CMakeFiles/WebServer.dir/Server.cpp.s

CMakeFiles/WebServer.dir/Request/Request.cpp.o: CMakeFiles/WebServer.dir/flags.make
CMakeFiles/WebServer.dir/Request/Request.cpp.o: ../Request/Request.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lbagg/Desktop/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/WebServer.dir/Request/Request.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WebServer.dir/Request/Request.cpp.o -c /Users/lbagg/Desktop/WebServer/Request/Request.cpp

CMakeFiles/WebServer.dir/Request/Request.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/Request/Request.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lbagg/Desktop/WebServer/Request/Request.cpp > CMakeFiles/WebServer.dir/Request/Request.cpp.i

CMakeFiles/WebServer.dir/Request/Request.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/Request/Request.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lbagg/Desktop/WebServer/Request/Request.cpp -o CMakeFiles/WebServer.dir/Request/Request.cpp.s

CMakeFiles/WebServer.dir/Client/Client.cpp.o: CMakeFiles/WebServer.dir/flags.make
CMakeFiles/WebServer.dir/Client/Client.cpp.o: ../Client/Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lbagg/Desktop/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/WebServer.dir/Client/Client.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WebServer.dir/Client/Client.cpp.o -c /Users/lbagg/Desktop/WebServer/Client/Client.cpp

CMakeFiles/WebServer.dir/Client/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/Client/Client.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lbagg/Desktop/WebServer/Client/Client.cpp > CMakeFiles/WebServer.dir/Client/Client.cpp.i

CMakeFiles/WebServer.dir/Client/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/Client/Client.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lbagg/Desktop/WebServer/Client/Client.cpp -o CMakeFiles/WebServer.dir/Client/Client.cpp.s

CMakeFiles/WebServer.dir/utils.cpp.o: CMakeFiles/WebServer.dir/flags.make
CMakeFiles/WebServer.dir/utils.cpp.o: ../utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lbagg/Desktop/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/WebServer.dir/utils.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WebServer.dir/utils.cpp.o -c /Users/lbagg/Desktop/WebServer/utils.cpp

CMakeFiles/WebServer.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/utils.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lbagg/Desktop/WebServer/utils.cpp > CMakeFiles/WebServer.dir/utils.cpp.i

CMakeFiles/WebServer.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/utils.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lbagg/Desktop/WebServer/utils.cpp -o CMakeFiles/WebServer.dir/utils.cpp.s

CMakeFiles/WebServer.dir/MIMEtypes.cpp.o: CMakeFiles/WebServer.dir/flags.make
CMakeFiles/WebServer.dir/MIMEtypes.cpp.o: ../MIMEtypes.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lbagg/Desktop/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/WebServer.dir/MIMEtypes.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WebServer.dir/MIMEtypes.cpp.o -c /Users/lbagg/Desktop/WebServer/MIMEtypes.cpp

CMakeFiles/WebServer.dir/MIMEtypes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/MIMEtypes.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lbagg/Desktop/WebServer/MIMEtypes.cpp > CMakeFiles/WebServer.dir/MIMEtypes.cpp.i

CMakeFiles/WebServer.dir/MIMEtypes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/MIMEtypes.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lbagg/Desktop/WebServer/MIMEtypes.cpp -o CMakeFiles/WebServer.dir/MIMEtypes.cpp.s

CMakeFiles/WebServer.dir/Response.cpp.o: CMakeFiles/WebServer.dir/flags.make
CMakeFiles/WebServer.dir/Response.cpp.o: ../Response.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lbagg/Desktop/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/WebServer.dir/Response.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WebServer.dir/Response.cpp.o -c /Users/lbagg/Desktop/WebServer/Response.cpp

CMakeFiles/WebServer.dir/Response.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/Response.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lbagg/Desktop/WebServer/Response.cpp > CMakeFiles/WebServer.dir/Response.cpp.i

CMakeFiles/WebServer.dir/Response.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/Response.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lbagg/Desktop/WebServer/Response.cpp -o CMakeFiles/WebServer.dir/Response.cpp.s

CMakeFiles/WebServer.dir/errors.cpp.o: CMakeFiles/WebServer.dir/flags.make
CMakeFiles/WebServer.dir/errors.cpp.o: ../errors.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lbagg/Desktop/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/WebServer.dir/errors.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WebServer.dir/errors.cpp.o -c /Users/lbagg/Desktop/WebServer/errors.cpp

CMakeFiles/WebServer.dir/errors.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/errors.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lbagg/Desktop/WebServer/errors.cpp > CMakeFiles/WebServer.dir/errors.cpp.i

CMakeFiles/WebServer.dir/errors.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/errors.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lbagg/Desktop/WebServer/errors.cpp -o CMakeFiles/WebServer.dir/errors.cpp.s

CMakeFiles/WebServer.dir/CGI/RequestConfigMatch.cpp.o: CMakeFiles/WebServer.dir/flags.make
CMakeFiles/WebServer.dir/CGI/RequestConfigMatch.cpp.o: ../CGI/RequestConfigMatch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lbagg/Desktop/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/WebServer.dir/CGI/RequestConfigMatch.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/WebServer.dir/CGI/RequestConfigMatch.cpp.o -c /Users/lbagg/Desktop/WebServer/CGI/RequestConfigMatch.cpp

CMakeFiles/WebServer.dir/CGI/RequestConfigMatch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WebServer.dir/CGI/RequestConfigMatch.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lbagg/Desktop/WebServer/CGI/RequestConfigMatch.cpp > CMakeFiles/WebServer.dir/CGI/RequestConfigMatch.cpp.i

CMakeFiles/WebServer.dir/CGI/RequestConfigMatch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WebServer.dir/CGI/RequestConfigMatch.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lbagg/Desktop/WebServer/CGI/RequestConfigMatch.cpp -o CMakeFiles/WebServer.dir/CGI/RequestConfigMatch.cpp.s

# Object files for target WebServer
WebServer_OBJECTS = \
"CMakeFiles/WebServer.dir/main.cpp.o" \
"CMakeFiles/WebServer.dir/CGI/CGI.cpp.o" \
"CMakeFiles/WebServer.dir/CGI/mainCGI.cpp.o" \
"CMakeFiles/WebServer.dir/ConfigParser/ConfigParser.cpp.o" \
"CMakeFiles/WebServer.dir/Server.cpp.o" \
"CMakeFiles/WebServer.dir/Request/Request.cpp.o" \
"CMakeFiles/WebServer.dir/Client/Client.cpp.o" \
"CMakeFiles/WebServer.dir/utils.cpp.o" \
"CMakeFiles/WebServer.dir/MIMEtypes.cpp.o" \
"CMakeFiles/WebServer.dir/Response.cpp.o" \
"CMakeFiles/WebServer.dir/errors.cpp.o" \
"CMakeFiles/WebServer.dir/CGI/RequestConfigMatch.cpp.o"

# External object files for target WebServer
WebServer_EXTERNAL_OBJECTS =

WebServer: CMakeFiles/WebServer.dir/main.cpp.o
WebServer: CMakeFiles/WebServer.dir/CGI/CGI.cpp.o
WebServer: CMakeFiles/WebServer.dir/CGI/mainCGI.cpp.o
WebServer: CMakeFiles/WebServer.dir/ConfigParser/ConfigParser.cpp.o
WebServer: CMakeFiles/WebServer.dir/Server.cpp.o
WebServer: CMakeFiles/WebServer.dir/Request/Request.cpp.o
WebServer: CMakeFiles/WebServer.dir/Client/Client.cpp.o
WebServer: CMakeFiles/WebServer.dir/utils.cpp.o
WebServer: CMakeFiles/WebServer.dir/MIMEtypes.cpp.o
WebServer: CMakeFiles/WebServer.dir/Response.cpp.o
WebServer: CMakeFiles/WebServer.dir/errors.cpp.o
WebServer: CMakeFiles/WebServer.dir/CGI/RequestConfigMatch.cpp.o
WebServer: CMakeFiles/WebServer.dir/build.make
WebServer: CMakeFiles/WebServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lbagg/Desktop/WebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable WebServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WebServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WebServer.dir/build: WebServer

.PHONY : CMakeFiles/WebServer.dir/build

CMakeFiles/WebServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/WebServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/WebServer.dir/clean

CMakeFiles/WebServer.dir/depend:
	cd /Users/lbagg/Desktop/WebServer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lbagg/Desktop/WebServer /Users/lbagg/Desktop/WebServer /Users/lbagg/Desktop/WebServer/cmake-build-debug /Users/lbagg/Desktop/WebServer/cmake-build-debug /Users/lbagg/Desktop/WebServer/cmake-build-debug/CMakeFiles/WebServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/WebServer.dir/depend

