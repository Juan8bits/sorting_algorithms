#include "sort.h"
/**
 * bubble_sort - bubble sort method.
 * @array: unsorted array.
 * @size: size of array.
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int c, i;
	int new = 0;

	if (!array || !size)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (c = 0; c < size - i - 1; c++)
		{
			if (array[c] > array[c + 1])
			{
				new = array[c + 1];
				array[c + 1] = array[c];
				array[c] = new;
				print_array(array, size);
			}
		}
	}
}
