cmake_minimum_required(VERSION 4.0)
project(intervalian)

set(CMAKE_CXX_STANDARD 20)

add_executable(intervalian src/main.cpp
        src/ast/AstNode.cpp
        src/ast/AstNode.h
        src/ast/interval/IntervalNode.cpp
        src/ast/interval/IntervalNode.h)
