/*
 * =====================================================================================
 *
 *       Filename:  class_box.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/05/2017 06:01:20 PM
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

class Box
{
    public:
        double     length;
        double     height;
        
        // 'Box' class member function
        double getVolume(void)
        {
            return (length * height);
        }
};

int main(void)
{
    Box     box1;
    double  result;

    box1.length = 10.0F;
    box1.height = 10.0F;

    result = box1.getVolume();
    cout << result << endl;

    return 0;
}
