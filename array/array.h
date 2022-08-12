#ifndef __ARRAY_H__
#define __ARRAY_H__

/**
 * @brief 
 * user: aloneisbestes
 * email: aloneisbestes@gmail.com
 * 
 * 头文件实现功能：
 *     该头文件实现动态数据，能容纳任何数据类型
 */

#include <stdlib.h>

#define ARRAY_MAX 100

namespace mystd{

/* 判断是否是 c/c++ 程序 */
#ifdef __STDC__
#ifdef __cplusplus
/* 如果 __cplusplus 定义，则表示为c++程序 */
template <class T>
class MyArray{
private:
    T *m_any_arr;       // 任意数据
    int m_size;         // 总大小
    int m_idx;          // 当前的索引


public:
    /* 构造与析构 */
    MyArray(int size=ARRAY_MAX);    // ARRAY_MAX: 默认大小
    MyArray(const MyArray *arr);
    MyArray(const MyArray &arr);
    ~MyArray();

public:
    /* 相关操作 */
    bool add(const T &value);
    bool add(const T *value);

private:
    /* 内部成员函数 */
};

#else 
/* 否则为c语言程序 */
typedef struct MyArray {
    void **m_any_arr;    // 存储任意数据类型
    int m_size;          // 总大小
    int m_idx;           // 当前的索引位置
}MyArray;

/* 对动态数组的操作 */
int initMyArray()
int addMyArray(const char *value);
int deleteMyArray(const char *value);
#endif

/* 如果不是c/c++ 应该怎么解决 */
#else 
// 什么都不做
#endif
}

#endif // __ARRAY_H__