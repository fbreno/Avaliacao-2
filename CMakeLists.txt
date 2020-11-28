CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
PROJECT(Avaliacao)

SET(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -pedantic")

INCLUDE_DIRECTORIES(include/)

ADD_EXECUTABLE(prog src/main.cpp src/LinkedList.hpp src/stack.hpp src/queue.hpp)