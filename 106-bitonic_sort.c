#include "sort.h"

/**
 * swap - Function that swap to integers.
 * @mode: Recursion mode (UP/DOWN).
 * @arr: array.
 * @size: size of arr
 */
void swap(char mode, int *arr, size_t size)
{
	size_t act, jump = size / 2;

	for (act = 0; act < jump; act++)
	{
		if (mode == (arr[act] > arr[act + jump]))
		{
			arr[act] = arr[act] ^ arr[act + jump];
			arr[act + jump] = arr[act] ^ arr[act + jump];
			arr[act] = arr[act] ^ arr[act + jump];
		}
	}
}

/**
 * sort - Recursive function that separate array.
 * @mode: Recursion mode (UP/DOWN)
 * @arr: array.
 * @size: size of array.
 */
void sort(char mode, int *arr, size_t size)
{
	if (size < 2)
		return;
	swap(mode, arr, size);
	sort(mode, arr, size / 2);
	sort(mode, arr + (size / 2), size / 2);
}
/**
 * section_arr - Recursive function that sort array.
 * @mode: UP(1)/DOWN(0) bitonic mode.
 * @arr: Array to sort.
 * @size: actual steps
 * @S: Size of Original array.
 */
void section_arr(char mode, int *arr, size_t size, size_t S)
{
	if (size < 2)
		return;
	if (mode == 1)
		printf("Merging [%lu/%lu] (UP):\n", size, S);
	else
		printf("Merging [%lu/%lu] (DOWN):\n", size, S);
	print_array(arr, size);
	section_arr(1, arr, size / 2, S);
	section_arr(0, arr + (size / 2), size / 2, S);
	sort(mode, arr, size);
	if (mode == 1)
		printf("Result [%lu/%lu] (UP):\n", size, S);
	else
		printf("Result [%lu/%lu] (DOWN):\n", size, S);
	print_array(arr, size);
}

/**
 * bitonic_sort - Function that sorts an array of integers in ascending
 * order using the Bitonic sort algorithm.
 * @arr: array.
 * @size: size of array.
 */
void bitonic_sort(int *arr, size_t size)
{
	if (!arr || size < 2)
		return;
	section_arr(1, arr, size, size);
}
