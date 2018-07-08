/*
 * =====================================================================================
 *
 *       Filename:  copy_constructor.cpp
 *
 *    Description:  拷贝构造函数
 *
 *        Version:  1.0
 *        Created:  10/09/2017 07:55:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <iostream>

using namespace std;

class Line
{
    public:
        int getLength(void);
        Line(int len);              // 简单构造函数
        Line(const Line &obj);  // 拷贝构造函数
        ~Line();
    
    private:
        int *ptr;
};

// 构造函数, 所属类为Line
Line::Line(int len)
{
    cout << "调用构造函数: " << endl;
    /* 
     * 为指针分配内存
     */
    ptr = new int;
    *ptr = len;
}

// 拷贝构造函数
Line::Line(const Line &obj)
{
    cout << "调用拷贝构造函数并为指针ptr分配内存: " << endl;
    ptr = new int;
    *ptr = *obj.ptr;    //  拷贝值
}

// 析构函数
Line::~Line(void)
{
    cout << "释放内存..." << endl;
    delete ptr;
}

int Line::getLength(void)
{
    return *ptr;
}

// 普通函数
void display(Line obj)
{
    cout << "line 大小" << obj.getLength() << endl;
}

int main(void)
{
    Line    line(10);

    display(line);

    return 0;
}
