cmake_minimum_required (VERSION 3.2) # If your CMake version is older, try modifying this line
project(SuffixTrees)

add_definitions(-std=c++1z -g)

########## Create libraries
add_library(SuffixTreeLib buildTree.cpp suffixTree.cpp)
add_library(LinearizeStringLib linearizeString.cpp buildTree.cpp suffixTree.cpp)
add_library(LCSTwoStringsLib LCSTwoStrings.cpp buildTree.cpp suffixTree.cpp)

########## Link GoogleTest
include_directories($ENV{GMOCK_HOME}/gtest/include)
link_directories($ENV{GMOCK_HOME}/gtest/mybuild)


########## Add unit tests. The custom command runs the unit tests every time we use make to compile
add_executable(LinearizeStringTests linearizeStringTests.cpp)
target_link_libraries(LinearizeStringTests gtest)
target_link_libraries(LinearizeStringTests pthread)
target_link_libraries(LinearizeStringTests LinearizeStringLib)
add_custom_command(TARGET LinearizeStringTests
                   POST_BUILD
                   COMMAND LinearizeStringTests
                   WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                   COMMENT "Running LinearizeStringTests" VERBATIM)
                   
add_executable(LCSTwoStringsTests LCSTwoStringsTests.cpp)
target_link_libraries(LCSTwoStringsTests gtest)
target_link_libraries(LCSTwoStringsTests pthread)
target_link_libraries(LCSTwoStringsTests LCSTwoStringsLib)
add_custom_command(TARGET LCSTwoStringsTests
                   POST_BUILD
                   COMMAND LCSTwoStringsTests
                   WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                   COMMENT "Running LCSTwoStringsLibTests" VERBATIM)

########## Create sanity checks. These should not be run on every compile, so we only build it and run manually
add_executable(SuffixTreeSanityCheck suffixTreeSanityCheck.cpp)
target_link_libraries(SuffixTreeSanityCheck gtest)
target_link_libraries(SuffixTreeSanityCheck pthread)
target_link_libraries(SuffixTreeSanityCheck SuffixTreeLib)

add_executable(LinearizeStringSanityCheck linearizeStringSanityCheck.cpp)
target_link_libraries(LinearizeStringSanityCheck gtest)
target_link_libraries(LinearizeStringSanityCheck pthread)
target_link_libraries(LinearizeStringSanityCheck LinearizeStringLib)

#add_executable(LCSTwoStringsSanityCheck LCSTwoStringsSanityCheck.cpp)
#target_link_libraries(LCSTwoStringsSanityCheck gtest)
#target_link_libraries(LCSTwoStringsSanityCheck pthread)
#target_link_libraries(LCSTwoStringsSanityCheck LCSTwoStringsLib)


