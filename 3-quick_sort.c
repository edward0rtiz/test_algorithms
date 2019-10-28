#include "sort.h"

void swap_bubble(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *array, size_t size, int low, int high)
{
	int *pivot, high1, low1;

	pivot = array + high;
	for (high1 = low1 = low; low1 < high; low1++)
	{
		if(array[low1] < *pivot)
		{
			if (high1 < low1)
			{
				swap_bubble(array + low1, array + high1);
				print_array(array, size);
			}
			high1++;
		}
	}

	if(array[high1] > *pivot)
	{
		swap_bubble(array + high1, pivot);
		print_array(array, size);
	}
	return (high1);
}

void partition_sort(int *array, size_t size, int low, int high)
{
	int part;

	if (high - low > 0)
	{
		part = partition(array, size, low, high);
		partition_sort(array, size, low, part - 1);
		partition_sort(array, size, part + 1, high);
	}
}

void quick_sort(int *array, size_t size)
{
	partition_sort(array, size, 0, size - 1);
}