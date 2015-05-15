cmake_minimum_required(VERSION 2.6)

SET(GCC_COVERAGE_COMPILE_FLAGS "-std=c++14")

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread lib
add_executable(runTests tests.cpp MatchTreeNode.cpp MatchTree.cpp MatchTreeNode.hpp MatchTree.hpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)


SET(SOURCE
  main.cpp
  MatchTreeNode.cpp
  MatchTree.cpp

)

SET(HEADERS
  MatchTreeNode.hpp
  MatchTree.hpp
)
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
add_executable(VertiWords ${SOURCE} ${HEADERS})
