cmake_minimum_required(VERSION 3.15)
project(Code)

set(CMAKE_CXX_STANDARD 14)

add_executable(Code main.cpp AdjacencyList.cpp AdjacencyList.h AdjacencyMatrix.cpp AdjacencyMatrix.h SearchAlgo.cpp SearchAlgo.h Node.cpp Node.h Search.cpp Search.h Graph.h Edges.cpp Edges.h Algorithm.h SortingAlgos.cpp SortingAlgos.h Sort.cpp Sort.h)