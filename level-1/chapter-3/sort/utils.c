#include "utils.h"

bool is_array_sorted(int a[], int count) {
    if (count < 2) {
        return true;
    }
    bool result = true;
    for (size_t i = 1; i < count; i++) {
        if (a[i-1] > a[i]) {
            return false;
        }
    }
    return result;
}

void print_array(int a[], size_t length) {
    for (size_t i = 0; i < length; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}