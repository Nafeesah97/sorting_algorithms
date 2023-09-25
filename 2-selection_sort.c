#include "sort.h"

/**
 * swap_array - function to swap array
 * @array: array to be swapped
 * @first_index: the first index
 * @second_index: the second index
 */

void swap_array(int *array, size_t first_index, size_t second_index)
{
	int temp;

	if (array[first_index] == array[second_index])
		return;
	temp = array[first_index];
	array[first_index] = array[second_index];
	array[second_index] = temp;
}
/**
 *  selection_sort - sorts an array of integers in ascending order
 * @size: size of array
 * @array: array to be sorted
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, k;

	if (size < 2)
	{
		print_array(array, size);
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		k = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[k])
				k = j;
		}
		if (k != i)
		{
			swap_array(array, i, k);
			print_array(array, size);
		}
	}
}
