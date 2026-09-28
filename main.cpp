#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <string>
#include <chrono>
#include "Norms.h"
#include "PrintMatrix.h"
#include "MatrixInitializer.h"
#include "f.h"
#include "Solve.h"

int main(int argc, char* argv[])
{
	int k, n, m;

	if (argc < 4)
	{
		std::cout << "There are not enough arguments" << '\n';
		return 1;
	}

	try
	{
		n = std::stoi(argv[1]);
		m = std::stoi(argv[2]);
		k = std::stoi(argv[3]);
	}
	catch (...)
	{
		std::cout << "Invalid parameter format" << '\n';
		return 1;
	}

	if ((n <= 0) || (m <= 0) || (k < 0) || (k > 4))
	{
		std::cout << "Invalid parameter format" << '\n';
		return 1;
	}

	std::string filename = "";

	if (k == 0)
	{
		if (argc < 5)
		{
			std::cout << "There are not enough arguments" << '\n';
			return 1;
		}
		filename = argv[4];
	}
	else
	{
		if (argc >= 5)
		{
			std::cout << "An excess amount of arguments" << '\n';
			return 1;
		}
	}

        double* A = new double[n*n];
	double* b = new double[n];
	double* x = new double[n];
        int* Shift = new int[n];
	int q;

	q = Init(A, b, k, n, m, filename);
	if (q == 0)
	{
		std::cout << "Matrix: " << '\n';
		printMatrix(A, n, n, m);


		auto start_time = std::chrono::high_resolution_clock::now();
		q = Solve(A, n, b, x, Shift);
		auto end_time = std::chrono::high_resolution_clock::now();

		if (q != 1)
		{
			std::chrono::duration<double> duration = end_time - start_time;
			std::cout << std::defaultfloat;
			std::cout << "System solution time: " << (duration.count()) * 100.0 << " hundredths of a second" << '\n';

			std::cout << "Solution: " << '\n';
			printMatrix(x, n, 1, m);

                        Init(A, b, k, n, m, filename);
                        std::cout << "Norm of residual: " << std::scientific << std::setprecision(3) << CalcNormNev(A, b, x, n) << '\n';

                        std::cout << "Solution error margin: " << CalcErNorm(x, n) << '\n';
		}
	}

        delete[] Shift;
	delete[] A;
	delete[] b;
	delete[] x;
	return 0;
}
