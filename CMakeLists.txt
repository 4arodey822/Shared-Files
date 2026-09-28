cmake_minimum_required(VERSION 3.14)
project( CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-O3)

add_executable(solution
	main.cpp
	Norms.cpp
	PrintMatrix.cpp
	MatrixInitializer.cpp
	Solve.cpp
	f.cpp
	)
