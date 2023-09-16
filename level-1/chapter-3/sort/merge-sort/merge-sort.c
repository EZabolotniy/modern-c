#include <stddef.h>

void merge_sort(int input[], int left, int right) {
    if (left >= right) {
        return;
    }
    int middle = left + (right - left) / 2;
    merge_sort(input, left, middle);
    merge_sort(input, middle+1, right);

    int leftArray[middle - left + 1];
    for (size_t i = left; i < middle + 1; i++) {
        leftArray[i-left] = input[i];
    }
    
    int rightArray[right - middle];
    for (size_t i = middle + 1; i < right + 1; i++) {
        rightArray[i-middle-1] = input[i];
    }

    int i = 0, j = 0, k = left;
    while (i < (middle - left + 1) && j < (right - middle)) {
        if (leftArray[i] < rightArray[j]) {
            input[k++] = leftArray[i++];
        } else {
            input[k++] = rightArray[j++];
        }
    }
    while (i < (middle - left + 1)) {
        input[k++] = leftArray[i++];
    }
    while (j < (right - middle)) {
        input[k++] = rightArray[j++];
    }
}