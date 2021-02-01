#include "sort.h"

/**
 * selection_sort - Function that sorts an array of integers in
 * ascending order using the Selection sort algorithm.
 * @arr: Listo to sort.
 * @size: number of arr indexes.
 */

void selection_sort(int *arr, size_t size)
{
	size_t Ncycle, cpsize, min_value;

	if (arr == NULL)
		return;
	for (cpsize = 0; cpsize < size - 1; cpsize++)
	{
		min_value = cpsize;
		for (Ncycle = cpsize + 1; Ncycle < size; Ncycle++)
		{
			if (arr[Ncycle] < arr[min_value])
				min_value = Ncycle;
		}
		if (arr[min_value] < arr[cpsize])
		{
			/*Replace values*/
			arr[cpsize] = arr[cpsize] ^ arr[min_value];
			arr[min_value] = arr[cpsize] ^ arr[min_value];
			arr[cpsize] = arr[cpsize] ^ arr[min_value];
			print_array(arr, size);
		}
	}
}
