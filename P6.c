#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Return the index where the element was found
        } else if (arr[mid] < target) {
            left = mid + 1; // Target is in the right half
        } else {
            right = mid - 1; // Target is in the left half
        }
    }

    return -1; // Return -1 if the element was not found
}

int main() {
    int size;
    printf("Enter the size of the sorted array: ");
    scanf("%d", &size);

    int array[size];
    printf("Enter %d sorted array elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    int target;
    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    int index = binarySearch(array, size, target);

    if (index != -1) {
        printf("Element %d found at index %d\n", target, index);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
