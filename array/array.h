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

#define ARRAY_MAX 100

namespace mystd{

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

}

#endif // __ARRAY_H__