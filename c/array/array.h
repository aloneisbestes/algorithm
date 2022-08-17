#ifndef __ARRAY_H__
#define __ARRAY_H__

/**
 * @brief 
 * user: aloneisbestes
 * email: aloneisbestes@gmail.com
 * 
 * 头文件实现功能：
 *     该头文件实现动态数据，能容纳任何数据类型
 *     使用数组实现动态数据
 */

/**
 * @brief 
 * c语言实现动态数据
 *  1. findArrayValue函数的返回值，如果没有则返回-1，否则返回所在的索引
 *  2. initArray函数的返回值，如果成功，返回分配的动态数组的指针，否则返回NULL
 *  3. 其余函数的返回值，如果返回-1表示失败，否则表示成功
 */

// 定义结构体
typedef struct Array {
    void *m_arr;
    int m_capacity;     // 数组的大小, 实际容纳元素的个数
    int m_numOfElem;          // 表示数据元素的当前个数
    int m_sizeOfElem;         // 表示数据元素的大小
}Array;

#define ARR_DEFAULT_SIZE    8

// 初始化 array 数组
// size: 元素或数据的大小，也就是存储的类型的带下，比如int -> 4字节
// numSize: 存储数据的个数
Array *initArray(int sizeOfElem, int numSize);

// 添加数据到 array 中, 添加到末尾
int addArrayValue(Array *arr, void *value);

// 添加到数组中任意位置
int insertArrayValue(Array *arr, int idx, void *value);

// 删除数据，从 array 中
int delArrayValue(Array *arr, int idx);

// 查找数据，从 array 中
int findArrayValue(Array *arr, void *value);

// 修改数据，从 array 中
int updateArrayValue(Array *arr, int idx, void *updateVal);

// array 数组扩容
int reallocArray(Array *arr, int newCapacity);

// 销毁动态数组
void destroyArray(Array **arr);

// 遍历数组
void traversalArray(Array *arr, void (*func)(void *));

// 清楚 array
void clearArray(Array *arr);

#endif // __ARRAY_H__