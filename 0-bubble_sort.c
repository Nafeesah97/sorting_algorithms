#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: the listof numbers to be sorted
 * @size: size of array
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	j = 0;
	while (j < size)
	{
		for (i = 0; i < size - 1; i++)
        	{
            		if (array[i] > array[i + 1])
            		{
                		temp = array[i];
                		array[i] = array[i + 1];
                		array[i + 1] = temp;
                		print_array(array, size);
            		}   
        	}
        	j++;
    	}
}
