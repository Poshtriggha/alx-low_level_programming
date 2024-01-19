#include "search_algos.h"
#include <stdio.h>

/**
 * binary_search - Searches for a value in a sorted array using binary search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: The index where the value is located, or -1 if not present or if
 * the array is NULL
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left = 0, right = size - 1, mid;

	if (array == NULL)
		return -1;

	while (left <= right)
	{
		size_t i;

		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		mid = left + (right - left) / 2;

		if (array[mid] == value)
			return mid;
		else if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return -1; /* Value not found */
}

