#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "array.h"

// 初始化 array 数组
Array *initArray(int sizeOfElem, int numSize) {
    // 初始化动态数组
    Array *arr = (Array *)malloc(sizeof(Array));
    if (arr == NULL)    // 返回 NULL 表示初始化失败
        return NULL;

    // 初始化元素的大小和当前元素的个数
    arr->m_sizeOfElem = sizeOfElem;
    arr->m_numOfElem = 0;

    // 选择初始化时数组的大小，如果 numSize 大于默认大小 ARR_DEFAULT_SIZE
    // 则选择 numSize，否则选择使用默认大小 ARR_DEFAULT_SIZE
    arr->m_capacity = numSize > ARR_DEFAULT_SIZE ? numSize : ARR_DEFAULT_SIZE;

    // 初始化数组
    arr->m_arr = malloc(arr->m_capacity * arr->m_sizeOfElem);
    memset(arr->m_arr, 0, arr->m_capacity * arr->m_sizeOfElem);    

    return arr;
}

// 添加数据到 array 中
int addArrayValue(Array *arr, void *value) {
    if (arr->m_numOfElem == arr->m_capacity) {
        // 如果当前数组中的元素个数等于当前的容量，则需要扩容
        if (reallocArray(arr, arr->m_capacity * 2) != 0)
            return -1;
    }

    // 添加元素到数组中
    memcpy((char *)arr->m_arr + arr->m_numOfElem * arr->m_sizeOfElem, value, arr->m_sizeOfElem);
    // 添加完成，数组元素增加一个
    ++arr->m_numOfElem;
    return 0;
}

// 添加到数组中任意位置
int insertArrayValue(Array *arr, int idx, void *value) {
    // 判断索引是否在有效氛围内
    if (idx < 0 || idx > arr->m_numOfElem) {
        return -1;
    }

    if (arr->m_numOfElem == arr->m_capacity) {
        // 扩容操作, 暂时返回-1
        if (reallocArray(arr, arr->m_capacity * 2) != 0)
            return -1;
    }

    if (idx == arr->m_numOfElem) {  // 表示在末尾添加数据
        return addArrayValue(arr, value);
    } else {
        // 表示在数组的中间添加数据
        memmove((char *)arr->m_arr + (idx + 1) * arr->m_sizeOfElem, (char *)arr->m_arr + idx * arr->m_sizeOfElem, \
                (arr->m_numOfElem - idx) * arr->m_sizeOfElem);
        // 插入 value 到指定位置
        memcpy((char *)arr->m_arr + idx * arr->m_sizeOfElem, value, arr->m_sizeOfElem);
        // 数组当前个数+1
        ++arr->m_numOfElem;
    }

    return 0;
}

// 删除数据，从 array 中, 数组索引位置 [begin, end)
int delArrayValue(Array *arr, int idx) {
    // 判断数组是否为空
    if (idx >= arr->m_numOfElem || arr->m_numOfElem == 0) {
        return -1;
    }

    // 缩容操作，如果当前的容量小于总容量的1/4一下，则缩容1/2
    if (arr->m_numOfElem <= arr->m_capacity / 4) {
        reallocArray(arr, arr->m_capacity / 2);
    }

    // 删除数组中的元素, 将需要删除的元素索引之后的元素全部向前移动一位
    memmove((char *)arr->m_arr + idx * arr->m_sizeOfElem, (char *)arr->m_arr + (idx + 1) * arr->m_sizeOfElem, \
            (arr->m_numOfElem - idx) * arr->m_sizeOfElem);
    
    // 当前数组中的元素个数减一
    --arr->m_numOfElem;

    return 0;
}

// 查找数据，从 array 中
int findArrayValue(Array *arr, void *value) {
    // 查找 value 所在数组中的索引
    for (int i = 0; i < arr->m_numOfElem; i++) {
        if (memcmp(arr->m_arr + i * arr->m_sizeOfElem, value, arr->m_sizeOfElem) == 0) 
            return i;
    }

    return -1;
}

// 修改数据，从 array 中
int updateArrayValue(Array *arr, int idx, void *updateVal) {
    // 判断修改的索引是否越界
    if (idx >= arr->m_numOfElem) {
        return -1;
    }

    // 修改数据
    memcpy(arr->m_arr + idx * arr->m_sizeOfElem, updateVal, arr->m_sizeOfElem);
    return 0;
}

// array 数组扩容or缩容
int reallocArray(Array *arr, int newCapacity) {
    // 新的容量和旧的容量一样，则直接返回
    if (newCapacity == arr->m_capacity) 
        return 0;
    
    // 开始扩容
    void *newPtr = realloc(arr->m_arr, newCapacity * arr->m_sizeOfElem);
    if (newPtr == NULL)
        return -1;
    
    // 更新数组的指向地址
    arr->m_arr = newPtr;

    // 更新容量
    arr->m_capacity = newCapacity;

    return 0;
}

// 销毁动态数组
void destroyArray(Array **arr) {
    // 销毁动态数组
    if ((*arr)->m_arr) free((*arr)->m_arr);
    free(*arr);
    *arr = NULL;
    return ;
}

// 遍历数组
void traversalArray(Array *arr, void (*func)(void *)) {
    printf("[");
    for (int i = 0; i < arr->m_numOfElem; i++) {
        i != 0 && printf(" ");
        func((char *)arr->m_arr + i * arr->m_sizeOfElem);
    }
    printf("]\n");
    return ;
}

// 清楚 array
void clearArray(Array *arr) {
    reallocArray(arr, ARR_DEFAULT_SIZE);
    memset(arr->m_arr, 0, arr->m_capacity * arr->m_sizeOfElem);
    return ;
}