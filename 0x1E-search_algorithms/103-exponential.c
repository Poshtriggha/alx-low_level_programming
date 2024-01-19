#include "search_algos.h"
#include <stdio.h>

/**
 * binary_search - Searches for a value in a sorted array using Binary search
 * @array: Pointer to the first element of the array
 * @low: Starting index of the array or subarray
 * @high: Ending index of the array or subarray
 * @value: Value to search for
 *
 * Return: The index where the value is located, or -1 if not present
 */
int binary_search(int *array, size_t low, size_t high, int value)
{
    while (low <= high)
    {
        size_t mid = (low + high) / 2;

        printf("Searching in array: ");
        for (size_t i = low; i <= high; i++)
        {
            if (i < high)
                printf("%d, ", array[i]);
            else
                printf("%d\n", array[i]);
        }

        if (array[mid] == value)
            return mid;
        else if (array[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; /* Value not found */
}

/**
 * exponential_search - Searches for a value in a sorted array using Exponential search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: The first index where the value is located, or -1 if not present or if
 * the array is NULL
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t bound = 1;

    if (array == NULL)
        return -1;

    while (bound < size && array[bound] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        bound *= 2;
    }

    size_t low = bound / 2;
    size_t high = (bound < size) ? bound : size - 1;

    printf("Value found between indexes [%lu] and [%lu]\n", low, high);

    return binary_search(array, low, high, value);
}
