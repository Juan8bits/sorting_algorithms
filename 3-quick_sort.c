#include "sort.h"

/**
 * swap - Swap two integers.
 * @n1: Pointer to number 1.
 * @n2: Pointer to number 2.
 */
void swap(int *n1, int *n2)
{
	*n1 = *n1 ^ *n2;
	*n2 = *n1 ^ *n2;
	*n1 = *n1 ^ *n2;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 * the lomuto partition scheme, using the last element as pivot.
 * @array: The array of integers.
 * @size: Array's size.
 * @l: Partition's left side.
 * @r: Partition's right side.
 *
 * Return: The final partition index.
 */
int l_partition(int *array, size_t size, int l, int r)
{
	int *pivot = array + r;
	int above = l;
	int below = l;

	for (; below < r; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * quick_sort_rec - Quicksort algorithm with recursion and use the Lomuto
partition scheme.
 * @array: Array of integers to sort.
 * @size: Array's size.
 * @l: Partition's left side.
 * @r: Partition's right side.
 */
void quick_sort_rec(int *array, size_t size, int l, int r)
{
	int part;

	if (r - l > 0)
	{
		part = l_partition(array, size, l, r);
		quick_sort_rec(array, size, l, part - 1);
		quick_sort_rec(array, size, part + 1, r);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the Quick sort algorithm.
 * @array: Array of integers.
 * @size: Array's size.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_rec(array, size, 0, size - 1);
}
