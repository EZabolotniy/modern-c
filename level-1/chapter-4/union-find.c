#include <stdio.h>

static void initialize(size_t parent[], size_t size) {
    for(size_t i = 0; i < size; i++) {
        parent[i] = i;
    }
}

static size_t find(size_t item, size_t parent[]) {
    if (parent[item] == item) {
        return item;
    } else {
        return find(parent[item], parent);
    }
}

static size_t findReplace(size_t item, size_t replace, size_t parent[]) {
    size_t oldItem = parent[item];
    parent[item] = replace;
    if (oldItem == item) {
        return replace;
    } else {
        return findReplace(oldItem, replace, parent);
    }
}

static size_t findCompress(size_t item, size_t parent[]) {
    size_t root = find(item, parent);
    return findReplace(item, root, parent);
}

static void Union(size_t lhs, size_t rhs, size_t parent[]) {
    size_t root = findCompress(lhs, parent);
    findReplace(rhs, root, parent);
}

void print_array(size_t a[], size_t length) {
    for (size_t i = 0; i < length; i++) {
        printf("%zu ", a[i]);
    }
    printf("\n");
}

int main() {
    size_t size = 10;
    size_t parent[size];
    initialize(parent, size);
    printf("Initialize:\n");
    print_array(parent, size);
    
    printf("Union 0 <-> 1:\n");
    Union(0, 1, parent);
    print_array(parent, size);
    
    printf("Union 1 <-> 2:\n");
    Union(1, 2, parent);
    print_array(parent, size);

    printf("Union 9 <-> 8:\n");
    Union(9, 8, parent);
    print_array(parent, size);

    printf("Union 8 <-> 2:\n");
    Union(8, 2, parent);
    print_array(parent, size);

    printf("Find 1: %zu\n", find(1, parent));
}