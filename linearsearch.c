#include <stdio.h>

int main() {
    int n, key, found = 0;

    // Get number of elements
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input element to search
    printf("Enter element to search: ");
    scanf("%d", &key);

    // Perform Linear Search
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element %d found at position %d.\n", key, i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element %d not found in the array.\n", key);

    return 0;
}
