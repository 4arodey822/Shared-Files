#include <cmath>
#include "Norms.h"

double CalcNormNev(const double* A, const double* b, const double* x, const int n)
{
	double norm_r = 0;
	double norm_b = 0;

	for (int i = 0; i < n; i++)
	{
		double Ax_i = 0;

		for (int j = 0; j < n; j++)
		{
			Ax_i += A[i * n + j] * x[j];
		}

		double r_i = Ax_i - b[i];
		norm_r += r_i * r_i;

		norm_b += b[i] * b[i];
	}

	norm_r = std::sqrt(norm_r);
	norm_b = std::sqrt(norm_b);

	if (norm_b > 0)
	{
		return norm_r / norm_b;
	}
	return norm_r;
}

double CalcErNorm(const double* x, const int n)
{
	double norm_er = 0;

	for (int i = 0; i < n; i++)
	{
		double a = (i % 2 == 0) ? 1 : 0;
		
		norm_er += (x[i] - a) * (x[i] - a);
	}

	return std::sqrt(norm_er);
}