#include <iostream>
#include "f.h"

double f(const int k, const int n, const int i, const int j)
{
	if ((k <= 0) || (k > 4) || (n <= 0))
	{
		std::cout << "The parameters k, n, m are entered incorrectly." << '\n';
	}

	if (k == 1)
	{
		return n - std::max(double(i + 1), double(j + 1)) + 1;
	}

	if (k == 2)
	{
		return std::max(double(i + 1), double(j + 1));
	}

	if (k == 3)
	{
		return std::abs(double(i - j));
	}

	if (k == 4)
	{
		return 1.0 / (double(i + j + 1));
	}
	return -1;
}
