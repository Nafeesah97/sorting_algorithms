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

	if (first_index == second_index)
		return;
	temp = array[first_index];
	array[first_index] = array[second_index];
	array[second_index] = temp;
}

/**
 *  partition_arr - a function to partition the list of array
 * @size: size of array
 * @low_ind: lowest index of partion area
 * @high_ind: highest index of partition area
 * Return: the index of partition point
 */

int partition_arr(int *array, size_t size, size_t low_ind, size_t high_ind)
{
	size_t i, j;
	int pivot;

	i = low_ind - 1;
	pivot = array[high_ind];
	for(j = low_ind; j <= high_ind - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap_array(array, i, j);
			print_array(array, size);
		}
	}
	swap_array(array, i+1, high_ind);
	print_array(array, size);
	return (i + 1);
}

/**
 * sorting - to sort list and sublist
 * @array: list of numbers
 * @size: length of array
 * @low_ind: lowest index
 * @high_ind: highest index
 */

void sorting(int *array, size_t size, size_t low_ind, size_t high_ind)
{
	int p_ind;

	if (low_ind < high_ind)
	{
		p_ind = partition_arr(array, size, low_ind, high_ind);
		if (p_ind > 0)
			sorting(array, size, low_ind, p_ind - 1);
		sorting(array, size, p_ind + 1, high_ind);
	}
}

/**
 * quick_sort - function to sort in ascending order
 * @array: list of integers
 * @size: length of array
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	sorting(array, size, 0, size - 1);
}
