#include "sort.h"

/**
 * counting_sort - counting sort method.
 * @array: array.
 * @size: size of array.
 */

void counting_sort(int *array, size_t size)
{
	int *count, max = 0, *out, n, i, temp;

	if (!array || size < 2)
		return;
	out = malloc(sizeof(int) * (size));
	if (!out)
		return;
	n = size;
	for (i = 0; i < n; i++)
		if (array[i] > max)
			max = array[i];
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
	{
		free(out);
		return;
	}
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i <= n - 1; i++)
		count[array[i]] += 1;
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	for (i = 0; i < n; i++)
		out[i] = 0;
	for (i = n - 1; i > -1; i--)
	{
		temp = --count[array[i]];
		out[temp] = array[i];
	}
	for (i = 0; i < n; i++)
		array[i] = out[i];
	free(count);
	free(out);
}
