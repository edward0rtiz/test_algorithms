#include "sort.h"

void swap_bubble(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min_idx;

	for (i = 0;  i < size - 1; i++)
	{
		min_idx = array + i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *min_idx)
				min_idx = (array + j);
		}
		if ((array + i) != min_idx)
		{
			swap_bubble(array + i, min_idx);
			print_array(array, size);
		}
	}
}
