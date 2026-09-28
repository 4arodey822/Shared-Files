#include <cmath>
#include <iostream>
#include <iomanip>
#include "PrintMatrix.h"

void printMatrix(const double* A, const int rows, const int cols, const int m)
{
	int drows = std::min(rows, m);
	int dcols = std::min(cols, m);

	std::cout << std::scientific;

	for (int i = 0; i < drows; i++)
	{
		for (int j = 0; j < dcols; j++)
		{
			std::cout << " ";
			std::cout << std::setw(10) << std::setprecision(3) << A[i * cols + j];
		}
		std::cout << '\n';
	}

	std::cout << std::defaultfloat;
}