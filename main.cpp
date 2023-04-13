#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <cstdlib>
#include <math.h>
#include "sorts.h"

int main()
{
	int size = 500000;
	int max_val = 50;
	char algorithm = 'm';
	char c;

	srand(time(nullptr));
	std::vector<int> a(size);
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % max_val;
	}

	//print_vector(a);

	std::vector<int> b;

	std::cout << "Starting the sort.\n";
	struct timeval tp;
	gettimeofday(&tp, NULL);
	long start_time = tp.tv_sec * 1000 + tp.tv_usec / 1000;

	if (algorithm == 's')
	{
		b = ssort(a);
	}
	else if (algorithm == 'm')
	{
		b = msort(a);
	}
	else if (algorithm == 'q')
	{
		b = qsort(a);
	}
	else if (algorithm == 't') // quicksort2
	{
		b = qsort2(a, 0, a.size() - 1);
	}

	gettimeofday(&tp, NULL);
	long current_time = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	long elapsed = current_time - start_time;

	//print_vector(b);

	std::cout << "\n----------------\nElapsed Time: ";
	std::cout << elapsed << "\n";

	return 0;
}