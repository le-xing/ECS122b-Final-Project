cmake_minimum_required (VERSION 3.2) # If your CMake version is older, try modifying this line
project(SuffixTrees)

add_definitions(-std=c++1z -g)

########## Create libraries
add_library(SuffixTreeLib buildTree.cpp suffixTree.cpp)

########## Link GoogleTest
include_directories($ENV{GMOCK_HOME}/gtest/include)
link_directories($ENV{GMOCK_HOME}/gtest/mybuild)

########## Create sanity checks. These should not be run on every compile, so we only build it and run manually
add_executable(SuffixTreeSanityCheck suffixTreeSanityCheck.cpp)
target_link_libraries(SuffixTreeSanityCheck gtest)
target_link_libraries(SuffixTreeSanityCheck pthread)
target_link_libraries(SuffixTreeSanityCheck SuffixTreeLib)

