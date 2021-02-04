#include "sort.h"

/**
 * shell_sort -  sorting by shell method
 * @array: pointer to array
 * @size: size of array
 */

void shell_sort(int *array, size_t size)
{
	unsigned int in, out, h = 1;
	int temp;

	if (size < 2)
	{
		return;
	}
	while (h <= size / 3)
	{
		h = h * 3 + 1;
	}

	while (h > 0)
	{
		for (out = h; out < size; out++)
		{
			temp = array[out];
			in = out;
			while (in > h - 1 && array[in - h] >= temp)
			{
				array[in] = array[in - h];
				in = in - h;
			}
			array[in] = temp;
		}
		h = (h - 1) / 3;
		print_array(array, size);
	}
}
