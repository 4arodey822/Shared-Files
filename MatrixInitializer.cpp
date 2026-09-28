#include <iostream> 
#include <string>
#include <fstream>
#include "f.h"
#include "MatrixInitializer.h"

int Init(double* A, double* b, const int k, const int n, const int m, std::string filename)
{
	if ((k < 0) || (k > 4) || (n <= 0) || (m <= 0))
	{
		std::cout << "The parameters k, n, m are entered incorrectly." << '\n';
	}

	if (k == 0)
	{
		std::ifstream File(filename);

		if (!File.is_open())
		{
			std::cout << "File opening error" << '\n';
			return 1;
		}

		double number;
		int i = 0;

                while (i < n * n)
		{
			if (File >> number)
			{
                                A[i] = number;
                                i++;
                        }
			else
			{
				if (File.eof())
				{
					std::cout << "There is not enough data for the matrix." << '\n';
				}
				else
				{
					std::cout << "Invalid data format" << '\n';
				}
				return 1;
			}
		}
                File.close();
	}
	else
	{
		int i, j;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				A[i * n + j] = f(k,n,i,j);
			}
		}
	}

	int s,l;

	for (s = 0; s < n; s++)
	{
		b[s] = 0;
		for (l = 0; 2 * l < n; l++)
		{
			b[s] += A[s * n + 2 * l];
		}
	}

	return 0;
}
