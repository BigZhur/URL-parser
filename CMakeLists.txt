cmake_minimum_required(VERSION 2.8)

add_executable(URLParser Parser.cpp)

set(SOURCE_LIB parser.cpp)
set(SOURCE_EXE testparserurl.cpp)
add_Library(parser STATIC ${SOURCE_LIB})

add_executable(testparserurl ${SOURCE_EXE})
target_link_libraries(testparserurl gtest gmock pthread)
