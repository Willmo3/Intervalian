cmake_minimum_required(VERSION 4.0)
project(intervalian)

set(CMAKE_CXX_STANDARD 20)

add_executable(intervalian src/main.cpp
        src/ast/AstNode.h
        src/interval/Interval.cpp
        src/interval/Interval.h
        src/ast/binaryops/BinaryOpNode.cpp
        src/ast/binaryops/BinaryOpNode.h
        src/ast/unaryops/UnaryOpNode.cpp
        src/ast/unaryops/UnaryOpNode.h
        src/ast/atoms/IntervalNode.cpp
        src/ast/atoms/IntervalNode.h
        src/visitor/AstVisitor.h
        src/visitor/EvaluationVisitor.cpp
        src/visitor/EvaluationVisitor.h
        src/ast/AstNode.cpp
        src/ast/unaryops/PowNode.cpp
        src/ast/unaryops/PowNode.h
)
