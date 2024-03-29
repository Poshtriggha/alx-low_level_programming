#include <stdio.h>
#include <stdlib.h>

/**
 * exponential_search - Searches for a value in a sorted array using Exponential search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: The first index where the value is located, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t bound = 1;
    size_t low, high, mid;

    if (array == NULL || size == 0)
        return -1;

    while (bound < size && array[bound] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        bound *= 2;
    }

    low = bound / 2;
    high = (bound < size) ? bound : size - 1;

    printf("Value found between indexes [%lu] and [%lu]\n", low, high);

    while (low <= high)
    {
        printf("Searching in array: ");
        for (mid = low; mid < high; mid++)
            printf("%d, ", array[mid]);
        printf("%d\n", array[mid]);

        if (array[mid] == value)
            return mid;

        if (array[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}
