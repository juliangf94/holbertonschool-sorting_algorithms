#include "sort.h"

/**
 * swap_int - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm.
 * The array is printed after each time a swap is performed.
 *
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			swap_int(&array[i], &array[min_idx]);
			print_array(array, size);
		}
	}
}
