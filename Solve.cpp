#include <iostream>
#include <cmath>
#include "Solve.h"

int Solve(double* A, const int n, double* b, double* x, int* Shift)
{
	int Index_1, Index_2;
	double Max;
	double c;
	for(int i = 0; i < n; i++)
	{
		Shift[i] = i;
	}
	for(int i = 0; i < n; i++)
	{
		Index_1 = i;  // finding maximum
		Index_2 = i;
		Max = fabs(A[i * n + i]); 
		for(int k = i; k < n; k++)
		{
			for(int s = i; s < n; s++)
			{
				if(Max < fabs(A[k * n + s]))
				{
					Max = fabs(A[k * n + s]);
					Index_1 = k;
					Index_2 = s;
				}
			}
		}

		for(int s = i; s < n; s++) // swapping
		{
			std::swap(A[i * n + s], A[Index_1 * n + s]);
		}
		std::swap(b[i], b[Index_1]);
		for(int k = 0; k < n; k++)
		{
			std::swap(A[k * n + i], A[k * n + Index_2]);
		}
		std::swap(Shift[i], Shift[Index_2]);

		if(fabs(A[i * n + i]) > 0) // "Gaussian" step
		{
			for(int k = 0; k < i; k++)
			{
				c = A[k * n + i]/A[i * n + i];
				A[k * n + i] = 0;
				for(int s = i + 1; s < n; s++)
				{
					A[k * n + s] -= A[i * n + s]*c;
				}
				b[k] -= b[i]*c;
			}
			for(int k = i + 1; k < n; k++)
			{
				c = A[k * n + i]/A[i * n + i];
				A[k * n + i] = 0;
				for(int s = i + 1; s < n; s++)
				{
					A[k * n + s] -= A[i * n + s]*c;
				}
				b[k] -= b[i]*c;
			}
			for(int s = i+1; s < n; s++)
			{
				A[i * n + s] = A[i * n + s]/A[i * n + i];
			}
			b[i] = b[i]/A[i * n + i];
			A[i * n + i] = 1;
		}
		else
		{
			std::cout << "The system is degenerate; there is no unique solution." << '\n';
			return 1;
		}
	}
	for(int i = 0; i < n; i++)
	{
		x[Shift[i]] = b[i];
	}
	return 0;
}
