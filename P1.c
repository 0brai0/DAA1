#include <stdio.h>
#include <time.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++)
        if (arr[i] == target)
            return i;
    return -1;
}

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int array[size];
    printf("Enter %d array elements:\n", size);
    for (int i = 0; i < size; i++)
        scanf("%d", &array[i]);

    int target;
    printf("Enter target element: ");
    scanf("%d", &target);

    clock_t start_time = clock();
    int index = linearSearch(array, size, target);
    clock_t end_time = clock();

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    if (index != -1)
        printf("Element %d found at index %d\n", target, index);
    else
        printf("Element %d not found in array\n", target);

    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
