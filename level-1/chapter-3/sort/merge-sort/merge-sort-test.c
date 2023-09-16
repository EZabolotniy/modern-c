#include "utils.h"
#include "merge-sort.h"

void test_merge_sort() {
    int data[] = {5, 3, 4, 2, 1, 0, 100, 87, 123, 12, 4, 1, 2, 4, 2, 444};
    int count = sizeof(data) / sizeof(data[0]);
    printf("Input array: ");
    print_array(data, count);
    
    merge_sort(data, 0, count-1);
    printf("Sorted array: ");
    print_array(data, count);

    printf("Is sorted = %d\n", is_array_sorted(data, count));
}