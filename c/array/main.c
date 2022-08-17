#include <stdio.h>
#include "array.h"

void printInt(void *val) {
    printf("%d", *(int *)val);
}

int main() {
    int ret = -2;
    int value = 0;
    int idx = -1;
    Array *arr = initArray(sizeof(int), 10);

    printf("add value: \n");
    for (int i = 0; i < 10; i++) {
        if (addArrayValue(arr, &i) != 0) {
            printf("add value failed.\n");
        }
    }
    printf("arr: ");
    traversalArray(arr, printInt);

    printf("delete value: \n");
    idx = 5;
    ret = delArrayValue(arr, idx);
    if (ret != 0) {
        printf("delete idx is %d failed.\n", idx);
    }
    printf("arr: ");
    traversalArray(arr, printInt);

    printf("find value: \n");
    value = 7;
    idx = findArrayValue(arr, &value);
    if (idx != -1) {
        printf("The index where the value resides is %d.\n", idx);
    }else {
        printf("The data does not exist.\n");
    }

    printf("update value: \n");
    if (idx != -1) {
        value = 20;
        updateArrayValue(arr, idx, &value);
        printf("arr: ");
        traversalArray(arr, printInt);
    }

    // realloc
    printf("dilatation: \n");
    for (int i = 0; i < 3; i++) {
        value = i + 10;
        if (addArrayValue(arr, &value) != 0) {
            printf("add value failed.\n");
        }
    }
    printf("arr: ");
    traversalArray(arr, printInt);
    printf("arr size is: %d.\n", arr->m_capacity);

    // 缩容
    printf("shrinkage capacity: \n");
    idx = 1;
    for (int i = 0; i < 10; i++) {
        ret = delArrayValue(arr, idx);
        if (ret != 0) {
            printf("delete idx is %d failed.\n", idx);
        }
    }
    printf("arr: ");
    traversalArray(arr, printInt);
    printf("arr size is: %d.\n", arr->m_capacity);

    // insert
    value = 20;
    if (insertArrayValue(arr, 4, &value) != 0) {
        printf("insert failed.\n");
    } 
    printf("arr: ");
    traversalArray(arr, printInt);

    return 0;
}