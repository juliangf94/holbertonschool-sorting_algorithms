#include "sort.h"

/**
 * partition_lomuto - partitions array using the Lomuto scheme
 * @array: array to partition
 * @low: start index
 * @high: end index (pivot position)
 * @total_size: full size of the array (for print_array)
 *
 * Return: final index of the pivot
 */
int partition_lomuto(int *array, int low, int high, size_t total_size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;

			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, total_size);
			}
		}
	}

	/* place pivot at correct position */
	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, total_size);
	}

	return (i + 1);
}

/**
 * quick_recursive - recursively sorts a sub-array using Quick Sort
 * @array: pointer to the array of integers
 * @low: starting index of the sub-array
 * @high: ending index of the sub-array
 * @total_size: total size of the array for printing purposes
 */

void quick_recursive(int *array, int low, int high, size_t total_size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition_lomuto(array, low, high, total_size);

		quick_recursive(array, low, pivot_index - 1, total_size);
		quick_recursive(array, pivot_index + 1, high, total_size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using Quick Sort
 * @array: pointer to the array of integers
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_recursive(array, 0, size - 1, size);
}
