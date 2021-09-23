project(test)
add_definitions(-std=c++11)
set(SRC_LIST main.cpp tree_node.cpp)
add_executable(test ${SRC_LIST})
