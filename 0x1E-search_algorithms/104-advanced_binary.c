#include <stdio.h>
#include <stddef.h>

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: Index where the value is located, or -1 if not present.
 */
int advanced_binary(int *array, size_t size, int value)
{
    size_t i, mid;
    int result;

    if (!array || size == 0)
        return (-1);

    printf("Searching in array: %d", array[0]);
    for (i = 1; i < size; i++)
        printf(", %d", array[i]);
    printf("\n");

    mid = (size - 1) / 2;
    if (array[mid] == value)
    {
        if (mid > 0 && array[mid - 1] == value)
            return advanced_binary(array, mid + 1, value);
        return (mid);
    }
    else if (array[mid] < value)
    {
        result = advanced_binary(array + mid + 1, size - mid - 1, value);
        if (result == -1)
            return (-1);
        return (mid + 1 + result);
    }
    else
    {
        return (advanced_binary(array, mid, value));
    }
}
